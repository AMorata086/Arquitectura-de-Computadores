#include <fstream>
#include <iostream>
#include <cstring>
#include <dirent.h>
#include <cmath>
#include <chrono>
#include <vector>
#include <filesystem>

#include "../common/progargs.hpp"
#include "../common/gethead.hpp"
#include "../aos/aos.hpp"

using namespace std;
using namespace std::chrono;
using clk = chrono::high_resolution_clock;

//-------------------------------------
int main(int argc, char *argv[])
{
    // Comprobacion de argumentos
    if (argsCheck(argc, argv) == -1)
    {
        return -1;
    }

    cout << "Input path: " << argv[1] << "\n";
    cout << "Output path: " << argv[2] << "\n";

    ifstream inFile;
    ofstream outFile;
    struct bmpHeader header;
    for (auto &entrada : filesystem::directory_iterator(argv[1]))
    {
        auto tini = clk::now(); // Tiempo carga

        inFile.open(entrada.path(), ifstream::binary);

        if (inFile.fail())
        { // Si no se puede abrir el fichero
            cerr << "Couldn't open the file: " << entrada.path() << endl;
            inFile.close();
            continue;
        }
        char buffer[54]; // Buffer para leer la cabecera
        inFile.read(buffer, 54);
        int comprHeader = getHeader(buffer, entrada.path(), header);
        if (comprHeader < 0)
        { // Si hay algun error al leer la cabecera
            inFile.close();
            continue;
        }

        // APLICACION DE OPERACIONES

        vector<struct aos_img> data;

        inFile.close();

        string path = entrada.path();

        cout << " File: \"" << path << "\"";

        getDataAOS(header, data, path);

        auto tload = clk::now(); // Tiempo carga
        path = path.substr(((string)argv[1]).length());
        string pathOut = argv[2] + path; // Path del fichero de salida

        vector<struct aos_img> newdata;

        if (strcmp(argv[3], "gauss") == 0)
            gauss(header, data, newdata);

        if (strcmp(argv[3], "mono") == 0)
            mono(header, data, newdata);

        auto toperation = clk::now(); // Tiempo carga

        auto thisto = clk::now();
        // operacion copy
        if (strcmp(argv[3], "histo") == 0)
            thisto = histo(header, data, pathOut);

        if (strcmp(argv[3], "copy") == 0)
            writeFileAOS(header, data, pathOut);
        else if (strcmp(argv[3], "gauss") == 0 || strcmp(argv[3], "mono") == 0)
            writeFileAOS(header, newdata, pathOut);

        auto tstore = clk::now(); // Tiempo carga

        // CALCULO DE TIEMPOS
        auto ttotal = duration_cast<microseconds>(tstore - tini);
        auto tcarga = duration_cast<microseconds>(tload - tini);
        duration<double> tescritura;
        cout << " (time: " << ttotal.count() << ")" << endl;
        cout << "\tLoad time: " << tcarga.count() << endl;

        if (strcmp(argv[3], "copy") != 0)
        {
            auto toper = duration_cast<microseconds>(toperation - tload);
            if (strcmp(argv[3], "gauss") == 0)
                cout << "\tGauss time: " << toper.count() << endl;
            else if (strcmp(argv[3], "mono") == 0)
                cout << "\tMono time: " << toper.count() << endl;

            else if (strcmp(argv[3], "histo") == 0)
            {
                auto th = duration_cast<microseconds>(thisto - tload);
                cout << "\tHisto time: " << th.count() << endl;
            }
        }
        if (strcmp(argv[3], "histo") == 0)
            tescritura = duration_cast<microseconds>(tstore - thisto);
        else
            tescritura = duration_cast<microseconds>(tstore - toperation);
        cout << "\tStore time: " << (int)(tescritura.count() * 1000000) << endl;
    }
}

#include <fstream>
#include <iostream>
#include <cstring>
#include <dirent.h>
#include <cmath>
#include <chrono>
#include <vector>
#include <filesystem>
#include "../aos/aos.hpp"
#include "../common/progargs.hpp"
#include "../common/gethead.hpp"

using namespace std;

using clk = chrono::high_resolution_clock;

/*// Declaraciones de Funciones
int getHeader(char *header, string path);
void getData(int **data);
void writeHeader();
void writeData(int **newdata);
void gauss(int **newdata, int **data);
int gaussOperator(int i, int j, int desp, int **data);
void sobel(int **newdata, int **dataG);
int sobelOperator(int i, int j, int desp, int **dataGauss);

// Variables globales
int start, width, height, totalSize;
// Ficheros de entrada y salida globales
ifstream inFile;
ofstream outFile;

// Matrices para las operaciones

const int GAUSS[5][5] = {{1, 4, 7, 4, 1},
                         {4, 16, 26, 16, 4},
                         {7, 26, 41, 26, 7},
                         {4, 16, 26, 16, 4},
                         {1, 4, 7, 4, 1}};*/

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
        cout << "Imagen: " << entrada.path() << endl;

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

        cout << "File size: " << header.file_size << "\n Width: " << header.width << "\n Height: " << header.height << endl;

        getDataAOS(header, data, path);

        vector<struct aos_img> newdata;

        path = path.substr(((string)argv[1]).length());
        string pathOut = argv[2] + path; // Path del fichero de salida
        // writeHeader(pathOut, header);

        // operacion copy
        if (strcmp(argv[3], "copy") == 0)
        {
            writeDataAOS(header, data, pathOut);
        }

        /*auto tLoad = clk::now(); // Tiempo carga
        clk::time_point tCopy;
        clk::time_point tGauss;
        clk::time_point tHisto;
        clk::time_point tMono;*/

        // if (strcmp(argv[3], "copy") != 0)
        // {
        //     gauss(data, newdata)cout << 'No es copy' << endl;
        // }
        // if (strcmp(argv[3], "gauss") != 0)
        // {
        //
        // }
        /*if (strcmp(argv[1], "copy") != 0)
        { // Si hay que hacer gauss o sobel
            gauss(newdata1, data);
            tGauss = clk::now(); // Tiempo gauss
            if (strcmp(argv[1], "sobel") == 0)
            {
                sobel(data, newdata); // En vez de crear otra matriz reutilizo la inicial
                tSobel = clk::now();  // Tiempo sobel
            }
        }
        outFile.seekp(0);          // Se posiciona al inicio
        outFile.write(buffer, 54); // Escribe el buffer inicial
        writeHeader();             // Le cambia los datos a los obligatorios(Ej: inicio datos: 54)

        if (strcmp(argv[1], "gauss") == 0 || strcmp(argv[1], "mono") == 0)
            writeData(newdata); // Si es gauss escribe de la nueva
        else
            writeData(data); // copy los nuevos datos están en data
        free(data);
        free(newdata);

        outFile.close();

        /*auto tFin = clk::now(); // Tiempo final

        // CALCULO DE TIEMPOS
        auto ttotal = duration_cast<microseconds>(tFin - tIni);
        auto tcarga = duration_cast<microseconds>(tLoad - tIni);
        duration<double> tescritura;
        cout << "(time: " << ttotal.count() << ")" << endl;
        cout << " Load time: " << tcarga.count() << endl;

        if (strcmp(argv[1], "copy") != 0)
        {
            auto tG = duration_cast<microseconds>(tGauss - tLoad);
            cout << " Gauss time: " << tG.count() << endl;

            if (strcmp(argv[1], "sobel") == 0)
            {
                auto tS = duration_cast<microseconds>(tSobel - tGauss);
                cout << " Sobel time: " << tS.count() << endl;
                tescritura = duration_cast<microseconds>(tFin - tSobel);
            }

            else
                tescritura = duration_cast<microseconds>(tFin - tGauss);
        }
        else
            tescritura = duration_cast<microseconds>(tFin - tLoad);
        cout << " Store time: " << (int)(tescritura.count() * 1000000) << endl;*/
    }
    /*

    // Bucle para cada uno de los ficheros
    for (auto &entrada : std::filesystem::directory_iterator(argv[0]))
    {
        auto tIni = clk::now(); // Tiempo inicial
        inFile.open(entrada.path(), ifstream::binary);
        if (inFile.fail())
        { // Si no se puede abrir el fichero
            cerr << "Couldn't open the file\n";
            inFile.close();
            continue;
        }
        char *buffer = new char[54]; // Buffer para leer la cabecera
        inFile.read(buffer, 54);
        int comprHeader = getHeader(buffer, entrada.path());
        if (comprHeader < 0)
        { // Si hay algun error al leer la cabecera
            inFile.close();
            continue;
        }
        string fileOut = entrada.path();
        fileOut = fileOut.substr(((string)argv[0]).length());
        string pathOut = argv[1] + fileOut; // Path del fichero de salida
        outFile.open(pathOut, ifstream::binary);
        cout << "File: " << entrada.path();

        // APLICACION DE OPERACIONES
        struct aos_img
        {
            int azul;
            int verde;
            int rojo;
        };
        aos_img image[height * width];

        inFile.seekg(start); // Se posiciona donde empiezan los datos de la imagen
        getData(aos_img);

        auto tLoad = clk::now(); // Tiempo carga
        clk::time_point tGauss;
        clk::time_point tHisto;
        clk::time_point tMono;

        struct new_aos_img
        {
            int azul;
            int verde;
            int rojo;
        };

        new_aos_img image[height * width];
        return 0;
    }
*/
}

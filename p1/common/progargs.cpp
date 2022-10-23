#include <fstream>
#include <iostream>
#include <cstring>
#include <dirent.h>
#include <filesystem>
#include <cmath>
#include <chrono>
using namespace std;
using namespace std::chrono;
using clk = chrono::high_resolution_clock;
// Declaraciones de Funciones
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
                         {1, 4, 7, 4, 1}};

int not3Args(int argc, char *argv[])
{
    // Si faltan argumentos
    if (argc != 3)
    {
        cerr << "Wrong format:\n"
             << "image in_path out_path oper\n\toperation:copy, histo, mono, gauss\n";
        return -1;
    }
    return 0;
}

int wrongValue(int argc, char *argv[])
// Si elvalor del argumento es erroneo
{
    if (strcmp(argv[2], "copy") != 0 && strcmp(argv[2], "histo") != 0 && strcmp(argv[2], "mono") != 0 && strcmp(argv[2], "gauss") != 0)
    {
        cerr << "Unexpected operation: " << argv[1] << "\n";
        return -1;
    }
    return 0;
}

int checkInDir(int argc, char *argv[])
{
    DIR *dirIn = opendir(argv[0]);
    if (dirIn == NULL)
    { // Si no se puede abrir el directorio de entrada
        cerr << "Cannot open directory [" << argv[0] << "] \n";
        return -1;
        closedir(dirIn);
    }
    closedir(dirIn);
    return 0;
}

int checkoutDir(int argc, char *argv[])
{
    DIR *dirOut = opendir(argv[1]);
    if (dirOut == NULL)
    { // Si no se puede abrir el directorio de salida
        cerr << "Output directory [" << argv[1] << "] does not exist \n";
        return -1;
        closedir(dirOut);
    }
    closedir(dirOut);

    return 0;
}

int argsCheck(int argc, char *argv[])
{
    if (not3Args(argc, argv) == -1 || wrongValue(argc, argv) == -1 || checkInDir(argc, argv) == -1 || checkoutDir(argc, argv) == -1)
    {
        cerr << "image in_path out_path oper\n\toperation:copy, histo, mono, gauss\n";
        return -1;
    }

    return 0;
}

//------------------------------------------------MAIN------------------------------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{

    string error = "image in_path out_path oper\n\toperation:copy, histo, mono, gauss\n";

    // APERTURA Y COMPROBACION DE DIRECTORIOS

    // Si faltan argumentos
    if (argc != 3)
    {
        cerr << "Wrong format: \n"
             << error;
        return -1;
    }
    // Si el nombre de operacion no es válido
    if (strcmp(argv[2], "copy") != 0 && strcmp(argv[2], "histo") != 0 && strcmp(argv[2], "mono") != 0 && strcmp(argv[2], "gauss") != 0)
    {
        cerr << "Unexpected operation: " << argv[1] << "\n"
             << error;
        return -1;
    }

    DIR *dirIn = opendir(argv[0]);
    if (dirIn == NULL)
    { // Si no se puede abrir el directorio de entrada
        cerr << "Cannot open directory [" << argv[0] << "] \n"
             << error;
        return -1;
        closedir(dirIn);
    }
    closedir(dirIn);

    DIR *dirOut = opendir(argv[1]);
    if (dirOut == NULL)
    { // Si no se puede abrir el directorio de salida
        cerr << "Output directory [" << argv[1] << "] does not exist \n"
             << error;
        return -1;
        closedir(dirOut);
    }
    closedir(dirOut);

    // tratamiento de la salida
    cout << "Input path: " << argv[0] << endl;
    cout << "Output path: " << argv[1] << endl;

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
        struct data1
        {
            int azul[height * width];
            int verde[height * width];
            int rojo[height * width];
        };
        inFile.seekg(start); // Se posiciona donde empiezan los datos de la imagen
        getData(data1);

        auto tLoad = clk::now(); // Tiempo carga
        clk::time_point tGauss;
        clk::time_point tHisto;
        clk::time_point tMono;

        for (int i = 1; i <= width * height; i++)
        {
            vector
        }

        if (strcmp(argv[1], "copy") != 0)
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
        if (strcmp(argv[1], "gauss") == 0)
            writeData(newdata); // Si es gauss escribe de la nueva
        else
            writeData(data); // Para sobel o copy los nuevos datos están en data
        free(data);
        free(newdata);
        inFile.close();
        outFile.close();

        auto tFin = clk::now(); // Tiempo final

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
        cout << " Store time: " << (int)(tescritura.count() * 1000000) << endl;
    }
    return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// COMPROBACION DE PARAMETROS FICHERO BMP
int getHeader(char *buffer, string path)
{

    string error = "Error processing \"" + path + "\"\n";

    if ((buffer[0] != 'B') || (buffer[1] != 'M'))
    {
        cerr << error << " It isn't a bmp format\n";
        return -1;
    }
    totalSize = (unsigned char)buffer[2] + (unsigned char)buffer[3] * 256 + (unsigned char)buffer[4] * 65536 + (unsigned char)buffer[5] * 16777216;

    start = (unsigned char)buffer[10] + (unsigned char)buffer[11] * 256 + (unsigned char)buffer[12] * 65536 + (unsigned char)buffer[13] * 16777216;

    uint16_t planes = (unsigned char)buffer[26] + (unsigned char)buffer[27] * 256;
    if (planes != 1)
    {
        cerr << error << " Number of planes is not 1\n";
        return -1;
    }

    uint16_t point_size = (unsigned char)buffer[28] + (unsigned char)buffer[29] * 256;
    if (point_size != 24)
    {
        cerr << error << " Bit count is not 24\n";
        return -1;
    }

    int compression = (unsigned char)buffer[30] + (unsigned char)buffer[31] * 256 + (unsigned char)buffer[32] * 65536 + (unsigned char)buffer[33] * 16777216;
    if (compression != 0)
    {
        cerr << error << " Compression is not 0\n";
        return -1;
    }

    width = (unsigned char)buffer[18] + (unsigned char)buffer[19] * 256 + (unsigned char)buffer[20] * 65536 + (unsigned char)buffer[21] * 16777216;

    height = (unsigned char)buffer[22] + (unsigned char)buffer[23] * 256 + (unsigned char)buffer[24] * 65536 + (unsigned char)buffer[25] * 16777216;
    return 0;
}

//------------------------------------------------------------------------
// Escribir los datos obligatorios en el header
void writeHeader()
{
    char *newHeader = new char[4];
    int size = totalSize - (start - 54);
    newHeader[0] = (size)&0xFF;
    newHeader[1] = ((size) >> 8) & 0xFF;
    newHeader[2] = ((size) >> 16) & 0xFF;
    newHeader[3] = ((size) >> 24) & 0xFF;
    outFile.seekp(2);
    outFile.write(newHeader, 4);
    newHeader[0] = (54) & 0xFF;
    newHeader[1] = ((54) >> 8) & 0xFF;
    newHeader[2] = ((54) >> 16) & 0xFF;
    newHeader[3] = ((54) >> 24) & 0xFF;
    outFile.seekp(10);
    outFile.write(newHeader, 4);
    newHeader[0] = (40) & 0xFF;
    newHeader[1] = ((40) >> 8) & 0xFF;
    newHeader[2] = ((40) >> 16) & 0xFF;
    newHeader[3] = ((40) >> 24) & 0xFF;
    outFile.write(newHeader, 4);
    newHeader[0] = (2835) & 0xFF;
    newHeader[1] = ((2835) >> 8) & 0xFF;
    newHeader[2] = ((2835) >> 16) & 0xFF;
    newHeader[3] = ((2835) >> 24) & 0xFF;
    outFile.seekp(38);
    outFile.write(newHeader, 4);
    outFile.write(newHeader, 4);
    newHeader[0] = (0) & 0xFF;
    newHeader[1] = ((0) >> 8) & 0xFF;
    newHeader[2] = ((0) >> 16) & 0xFF;
    newHeader[3] = ((0) >> 24) & 0xFF;
    outFile.write(newHeader, 4);
    outFile.write(newHeader, 4);
}
//------------------------------------------------------------------------

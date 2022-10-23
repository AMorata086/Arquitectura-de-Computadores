#include <fstream>
#include <iostream>
#include <cstring>
#include <dirent.h>
#include <filesystem>
#include <cmath>
#include <chrono>
#include "./aos/aos.h"
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

//-------------------------------------
int main(int argc, char *argv[])
{
    // vector<struct img_aos> image;

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

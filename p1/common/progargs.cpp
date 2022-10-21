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

    cout << "Input path: " << argv[0] << "\n";
    cout << "Output path: " << argv[1] << "\n";
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

    cout << "Input path: " << argv[0] << endl;
    cout << "Output path: " << argv[1] << endl;

    struct dirent *input;
    // bucle para la ejecucion de la operacion sobre cada imagen en el directorio
    while ((input = readdir(dirIn)) != NULL)
    {
        if ((strcmp(input->d_name, ".") != 0) && (strcmp(input->d_name, "..") != 0))
        {
            // Falta ver como hacer esto
        }
    }
    closedir(dirIn);

    return 0;
}
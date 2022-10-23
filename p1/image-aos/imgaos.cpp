#include <fstream>
#include <iostream>
#include <cstring>
#include <dirent.h>
#include <filesystem>
#include <cmath>
#include <chrono>
#include <progarps.cpp>
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
    progrargs.parameterCheck(int argc, char *argv[])
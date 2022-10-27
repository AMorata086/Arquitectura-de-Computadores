#include <iostream>
#include <cstring>
#include <dirent.h>
#include "progargs.hpp"

using namespace std;

int not3Args(int argc, char *argv[])
{
    // Si faltan argumentos
    if (argc != 4)
    {
        cerr << "Wrong format:" << endl;
        return -1;
    }
    return 0;
}

int wrongValue(int argc, char *argv[])
// Si elvalor del argumento es erroneo
{
    if (strcmp(argv[3], "copy") != 0 && strcmp(argv[3], "histo") != 0 && strcmp(argv[3], "mono") != 0 && strcmp(argv[3], "gauss") != 0)
    {
        cerr << "Unexpected operation: " << argv[3] << "\n";
        return -1;
    }
    return 0;
}

int checkInDir(int argc, char *argv[])
{
    DIR *dirIn = opendir(argv[1]);
    if (dirIn == NULL)
    { // Si no se puede abrir el directorio de entrada
        cerr << "Cannot open directory [" << argv[1] << "] \n";
        return -1;
        closedir(dirIn);
    }
    closedir(dirIn);
    return 0;
}

int checkoutDir(int argc, char *argv[])
{
    DIR *dirOut = opendir(argv[2]);
    if (dirOut == NULL)
    { // Si no se puede abrir el directorio de salida
        cerr << "Output directory [" << argv[2] << "] does not exist \n";
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
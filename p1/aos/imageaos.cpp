#include <fstream>
#include <iostream>
#include <cstring>
#include <dirent.h>
#include <filesystem>
#include <cmath>
#include "aos.hpp"
#include "../common/gethead.hpp"

using namespace std;

struct aos_img
{
    int azul;
    int verde;
    int rojo;
};

void getDataAOS(struct bmpHeader &header, vector<struct aos_img> &image, string path)
{
    ifstream inFile;
    inFile.open(path, ifstream::binary);
    inFile.seekg(header.offset, ios::beg);
    char pixel[4];
    int extra = 4 - ((header.width * 3) % 4); // Para los bytes de padding
    for (int i = 1; i <= (header.height * header.width); i++)
    {
        inFile.read(pixel, 3);
        image.push_back(aos_img{(int)(unsigned char)pixel[0], (int)(unsigned char)pixel[1], (int)(unsigned char)pixel[2]});

        // Si hay padding, lo lee pero no lo guarda
        if (i % (header.width) == 0 && extra < 4)
            inFile.read(pixel, extra);
    }
    inFile.close();
}

// Escribir los datos nuevos para SOA
void writeDataAOS(struct bmpHeader &header, vector<struct aos_img> &image, string path)
{
    ofstream outFile;
    outFile.open(path, ifstream::binary);
    outFile.seekp(header.offset, ios::beg);
    char palabra[4];
    char ext[3] = {0, 0, 0};
    int extra = 4 - ((header.width * 3) % 4); // Para el padding
    int counter = 1;
    for (int i = 0; i < (header.height * header.width); i++)
    {
        switch (counter)
        {
        case 1:
            palabra[0] = image[i].azul;
            palabra[1] = image[i].verde;
            palabra[2] = image[i].rojo;
            palabra[3] = image[i + 1].azul;
            break;
        case 2:
            palabra[0] = image[i].verde;
            palabra[1] = image[i].rojo;
            palabra[2] = image[i + 1].azul;
            palabra[3] = image[i + 1].verde;
            break;
        case 3:
            palabra[0] = image[i].rojo;
            palabra[1] = image[i + 1].azul;
            palabra[2] = image[i + 1].verde;
            palabra[3] = image[i + 1].rojo;
            break;
        case 4:
            break;
        }
        if (counter % 4 != 0)
            counter++;
        else
            counter = 1;

        outFile.write(palabra, 4);
        // Si hay padding lo escribe al final de la linea
        if (i % (header.width) == 0 && extra < 4)
            outFile.write(ext, extra);
        outFile.close();
    }

    // Escribir los datos nuevos
    // void writeData(int **newdata)
    // {
    //     char *pixel = new char[4];
    //     char ext[3] = {0, 0, 0};
    //     int extra = 4 - ((width * 3) % 4); // Para el padding
    //     for (int i = 0; i < height; i++)
    //     {
    //         for (int j = 0; j < (width * 3); j += 3)
    //         {
    //             pixel[0] = newdata[i][j];
    //             pixel[1] = newdata[i][j + 1];
    //             pixel[2] = newdata[i][j + 2];
    //             outFile.write(pixel, 3);
    //             // Si hay padding lo escribe al final de la linea
    //             if (j == ((width - 1) * 3) && extra < 4)
    //                 outFile.write(ext, extra);
    //         }
    //     }
    // }
}
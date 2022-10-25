#include <fstream>
#include <iostream>
#include <cstring>
#include <dirent.h>
#include <filesystem>
#include <cmath>
#include <vector>
#include "./soa/soa.hpp"

using namespace std;

//------------------------------------------------------------------------

void getDataSOA(ifstream inFile, int height, int width, struct soa_img image)
{
    char pixel[3];
    int extra = 4 - ((width * 3) % 4); // Para los bytes de padding
    for (int i = 0; i < (height * width); i++)
    {
        inFile.read(pixel, 3);

        image.azul.push_back((int)(unsigned char)pixel[0]);
        image.verde.push_back((int)(unsigned char)pixel[1]);
        image.rojo.push_back((int)(unsigned char)pixel[2]);
        // Si hay padding, lo lee pero no lo guarda
        if (i % (width - 1) == 0 && extra < 4)
            inFile.read(pixel, extra);
    }
}

// Escribir los datos nuevos para SOA
void writeDataSOA(ofstream outFile, int height, int width, struct soa_img image)
{
    char pixel[3]; // es 4?
    char ext[3] = {0, 0, 0};
    int extra = 4 - ((width * 3) % 4); // Para el padding
    for (int i = 0; i < (height * width); i++)
    {
        {
            pixel[0] = image.azul[i];
            pixel[1] = image.verde[i];
            pixel[2] = image.rojo[i];
            outFile.write(pixel, 3);
            // Si hay padding lo escribe al final de la linea
            if (i % (width - 1) == 0 && extra < 4)
                outFile.write(ext, extra);
        }
    }
}

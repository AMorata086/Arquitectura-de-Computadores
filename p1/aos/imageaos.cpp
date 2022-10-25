#include <fstream>
#include <iostream>
#include <cstring>
#include <dirent.h>
#include <filesystem>
#include <cmath>
#include "./aos/aos.hpp"

using namespace std;

//------------------------------------------------------------------------
// Escribir los datos obligatorios en el header
/*void writeHeader(ofstream outFile, struct bmpHeader header)
{
    outFile.write((char *)header.caracB, 1);
    outFile.write((char *)header.caracM, 1);
    outFile.write((char *)header.file_size, 4);
    outFile.write((char *)header.reserved, 4);
    outFile.write((char *)header.offset, 4);
    outFile.write((char *)header.header_size, 4);
    outFile.write((char *)header.width, 4);
    outFile.write((char *)header.height, 4);
    outFile.write((char *)header.planes, 2);
    outFile.write((char *)header.bpp, 2);
    outFile.write((char *)header.compress, 4);
    outFile.write((char *)header.img_size, 4);
    outFile.write((char *)header.res_x, 4);
    outFile.write((char *)header.res_y, 4);
    outFile.write((char *)header.colors, 4);
    outFile.write((char *)header.important_c, 4);
}
*/
void getDataAOS(ifstream inFile, int height, int width, struct aos_img image[])
{
    char pixel[3];
    int extra = 4 - ((width * 3) % 4); // Para los bytes de padding
    for (int i = 0; i < height * width; i++)
    {
        inFile.read(pixel, 3);
        image[i].azul = ((int)(unsigned char)pixel[0]);
        image[i].verde = ((int)(unsigned char)pixel[1]);
        image[i].rojo = ((int)(unsigned char)pixel[2]);
        // Si hay padding, lo lee pero no lo guarda
        if (i % (width - 1) == 0 && extra < 4)
            inFile.read(pixel, extra);
    }
}

// Escribir los datos nuevos para SOA
void writeDataAOS(ofstream outFile, int height, int width, struct aos_img image[])
{
    char pixel[3];
    char ext[3] = {0, 0, 0};
    int extra = 4 - ((width * 3) % 4); // Para el padding
    for (int i = 0; i < (height * width); i++)
    {
        {
            pixel[0] = image[i].azul;
            pixel[1] = image[i].verde;
            pixel[2] = image[i].rojo;
            outFile.write(pixel, 3);
            // Si hay padding lo escribe al final de la linea
            if (i % (width - 1) == 0 && extra < 4)
                outFile.write(ext, extra);
        }
    }
}
* /
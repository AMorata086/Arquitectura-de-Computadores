#include <fstream>
#include <iostream>
#include <cstring>
#include <dirent.h>
#include <chrono>
#include <filesystem>
#include <cmath>
#include <vector>
#include "aos.hpp"
#include "../common/gethead.hpp"

using namespace std;

using namespace std::chrono;
using clk = chrono::high_resolution_clock;

struct aos_img
{
    int azul;
    int verde;
    int rojo;
};

const int GAUSS[5][5] = {{1, 4, 7, 4, 1},
                         {4, 16, 26, 16, 4},
                         {7, 26, 41, 26, 7},
                         {4, 16, 26, 16, 4},
                         {1, 4, 7, 4, 1}};

void getDataAOS(struct bmpHeader &header, vector<struct aos_img> &image, string path)
{
    ifstream inFile;
    inFile.open(path, ifstream::binary);
    inFile.seekg(header.offset, ios::beg);
    char pixel[4];
    int extra = 4 - (((int)(header.width) * 3) % 4); // Para los bytes de padding
    for (int i = 1; i <= ((int)(header.height) * (int)(header.width)); i++)
    {
        inFile.read(pixel, 3);
        image.push_back(aos_img{(int)(unsigned char)pixel[0], (int)(unsigned char)pixel[1], (int)(unsigned char)pixel[2]});

        // Si hay padding, lo lee pero no lo guarda
        if (i % ((int)(header.width)) == 0 && extra < 4)
            inFile.read(pixel, extra);
    }
    inFile.close();
}

// Escribir los datos nuevos para AOS
void writeFileAOS(struct bmpHeader &header, vector<struct aos_img> &newimage, string path)
{
    ofstream outFile;
    outFile.open(path, ios::binary);

    outFile.seekp(0, ios::beg);
    char newHeader[4] = {'B', 'M'};

    outFile.write(newHeader, 2);
    newHeader[0] = (header.file_size) & 0xFF;
    newHeader[1] = ((header.file_size) >> 8) & 0xFF;
    newHeader[2] = ((header.file_size) >> 16) & 0xFF;
    newHeader[3] = ((header.file_size) >> 24) & 0xFF;
    outFile.write(newHeader, 4);
    newHeader[0] = (header.offset) & 0xFF;
    newHeader[1] = ((header.offset) >> 8) & 0xFF;
    newHeader[2] = ((header.offset) >> 16) & 0xFF;
    newHeader[3] = ((header.offset) >> 24) & 0xFF;
    outFile.seekp(10, ios::beg);
    outFile.write(newHeader, 4);
    newHeader[0] = (header.header_size) & 0xFF;
    newHeader[1] = ((header.header_size) >> 8) & 0xFF;
    newHeader[2] = ((header.header_size) >> 16) & 0xFF;
    newHeader[3] = ((header.header_size) >> 24) & 0xFF;
    outFile.write(newHeader, 4);
    newHeader[0] = ((int)(header.width)) & 0xFF;
    newHeader[1] = (((int)(header.width)) >> 8) & 0xFF;
    newHeader[2] = (((int)(header.width)) >> 16) & 0xFF;
    newHeader[3] = (((int)(header.width)) >> 24) & 0xFF;
    outFile.write(newHeader, 4);
    newHeader[0] = ((int)(header.height)) & 0xFF;
    newHeader[1] = (((int)(header.height)) >> 8) & 0xFF;
    newHeader[2] = (((int)(header.height)) >> 16) & 0xFF;
    newHeader[3] = (((int)(header.height)) >> 24) & 0xFF;
    outFile.write(newHeader, 4);
    newHeader[0] = (1) & 0xFF;
    newHeader[1] = ((1) >> 8) & 0xFF;
    outFile.write(newHeader, 2);
    newHeader[0] = (24) & 0xFF;
    newHeader[1] = ((24) >> 8) & 0xFF;
    outFile.write(newHeader, 2);
    newHeader[0] = (0) & 0xFF;
    newHeader[1] = ((0) >> 8) & 0xFF;
    newHeader[2] = ((0) >> 16) & 0xFF;
    newHeader[3] = ((0) >> 24) & 0xFF;
    outFile.write(newHeader, 4);
    newHeader[0] = (header.img_size) & 0xFF;
    newHeader[1] = ((header.img_size) >> 8) & 0xFF;
    newHeader[2] = ((header.img_size) >> 16) & 0xFF;
    newHeader[3] = ((header.img_size) >> 24) & 0xFF;
    outFile.write(newHeader, 4);
    outFile.write(newHeader, 4);
    outFile.write(newHeader, 4);
    outFile.write(newHeader, 4);
    outFile.write(newHeader, 4);

    outFile.seekp(header.offset, ios_base::beg);
    char pixel[3];
    char ext[3] = {0, 0, 0};
    int extra = 4 - (((int)(header.width) * 3) % 4); // Para el padding
    int counter = 0;
    for (int i = 0; i < ((int)(header.height)); i++)
    {
        for (int j = 0; j < (int)(header.width); j++)
        {
            pixel[0] = newimage[counter].azul;
            pixel[1] = newimage[counter].verde;
            pixel[2] = newimage[counter].rojo;
            counter++;
            outFile.write(pixel, 3);
            // Si hay padding lo escribe al final de la linea
            if (j == (((int)(header.width) - 1)) && extra < 4)
                outFile.write(ext, extra);
        }
    }
    outFile.close();
}

//------------------------------------------------------------------------
// Método para gauss
void gauss(struct bmpHeader &header, vector<struct aos_img> &image, vector<struct aos_img> &imageNew)
{
    int resB = 0, resG = 0, resR = 0;
    for (int i = 0; i < ((int)(header.height)); i++)
    {
        for (int j = 0; j < ((int)(header.width)); j++)
        {
            for (int s = -2; s < 3; s++)
            {
                for (int t = -2; t < 3; t++)
                {
                    // Comprueba que no se sale de los limites
                    if ((i + s) >= 0 && (i + s) < (int)(header.height) && (j + t) >= 0 && (j + t) < (int)(header.width))
                    {
                        resB += GAUSS[s + 2][t + 2] * image[(i + s) * (int)(header.width) + (j + t)].azul;
                        resG += GAUSS[s + 2][t + 2] * image[(i + s) * (int)(header.width) + (j + t)].verde;
                        resR += GAUSS[s + 2][t + 2] * image[(i + s) * (int)(header.width) + (j + t)].rojo;
                    }
                }
            }
            // Guarda la suma/273
            imageNew.push_back(aos_img{resB / 273, resG / 273, resR / 273});
            resB = 0;
            resG = 0;
            resR = 0;
        }
    }
}

//---------------------------------------------------
void mono(struct bmpHeader &header, vector<struct aos_img> &image, vector<struct aos_img> &imageNew)
{
    for (int counter = 0; counter < ((int)(header.width) * (int)(header.height)); counter++)
    {
        // Paso 1
        double cg, cl, azul = ((double)image[counter].azul / 255), verde = ((double)image[counter].verde / 255), rojo = ((double)image[counter].rojo / 255);
        // Paso 2
        if (azul <= 0.04045)
            azul /= 12.92;
        else
            azul = pow(((azul + 0.055) / 1.055), 2.4);

        if (verde <= 0.04045)
            verde /= 12.92;
        else
            verde = pow(((verde + 0.055) / 1.055), 2.4);

        if (rojo <= 0.04045)
            rojo /= 12.92;
        else
            rojo = pow(((rojo + 0.055) / 1.055), 2.4);
        // Paso 3
        cl = (0.2126 * rojo) + (0.7152 * verde) + (0.0722 * azul);
        // Paso 4 y 5
        if (cl <= 0.0031308)
            cg = 12.92 * cl * 255;
        else
            cg = ((1.055 * (pow(cl, (1 / 2.4)))) - 0.055) * 255;
        imageNew.push_back(aos_img{int(cg), int(cg), int(cg)});
    }
}
auto histo(struct bmpHeader &header, vector<struct aos_img> &image, string path)
{
    ofstream outFile;
    path = path.substr(0, path.length() - 4);
    path += ".hst";
    outFile.open(path, fstream::out);
    outFile.seekp(0);
    int rojo[256] = {};
    int verde[256] = {};
    int azul[256] = {};
    for (int i = 0; i < ((int)(header.height) * (int)(header.width)); i++)
    {
        rojo[image[i].rojo]++;
        verde[image[i].verde]++;
        azul[image[i].azul]++;
    }

    auto toperation = clk::now();

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 256; j++)
        {
            switch (i)
            {
            case 0:
                outFile << rojo[j] << endl;
                break;
            case 1:
                outFile << verde[j] << endl;
                break;
            case 2:
                outFile << azul[j] << endl;
                break;
            }
        }
    }
    outFile.close();
    return toperation;
}

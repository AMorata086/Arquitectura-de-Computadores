#include <fstream>
#include <iostream>
#include <cstring>
#include <dirent.h>
#include <filesystem>
#include <cmath>
#include <vector>
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
    outFile.open(path, ios::binary);

    outFile.seekp(0, ios::beg);
    char newHeader[4] = {'B', 'M'};

    outFile.write(newHeader, 2);
    int size = header.file_size;
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
    newHeader[0] = (header.width) & 0xFF;
    newHeader[1] = ((header.width) >> 8) & 0xFF;
    newHeader[2] = ((header.width) >> 16) & 0xFF;
    newHeader[3] = ((header.width) >> 24) & 0xFF;
    outFile.write(newHeader, 4);
    newHeader[0] = (header.height) & 0xFF;
    newHeader[1] = ((header.height) >> 8) & 0xFF;
    newHeader[2] = ((header.height) >> 16) & 0xFF;
    newHeader[3] = ((header.height) >> 24) & 0xFF;
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

    cout << "Offset: " << header.offset << endl;
    outFile.seekp(header.offset, ios_base::beg);
    char pixel[3];
    char ext[3] = {0, 0, 0};
    int extra = 4 - ((header.width * 3) % 4); // Para el padding
    int counter = 0;
    for (int i = 0; i < (header.height); i++)
    {
        for (int j = 0; j < header.width; j++)
        {
            pixel[0] = image[counter].azul;
            pixel[1] = image[counter].verde;
            pixel[2] = image[counter].rojo;
            counter++;
            outFile.write(pixel, 3);

            if (j == ((header.width - 1)) && extra < 4)
                outFile.write(ext, extra);
        }

        // Si hay padding lo escribe al final de la linea
        /*if (extra > 0)
            outFile.write(ext, extra);*/
    }
    outFile.close();

    // ifstream fileTest;
    // fileTest.open(path, ifstream::binary);
    // char buffer[54];
    // fileTest.read(buffer, 54);
    // cout << buffer << endl;
    // fileTest.close();

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
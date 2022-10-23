#include <fstream>
#include <iostream>
#include <cstring>
#include <dirent.h>
#include <filesystem>
#include <cmath>
#include <vector>
#include "soa.h"

using namespace std;

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// COMPROBACION DE PARAMETROS FICHERO BMP

int getHeader(struct bmpHeader header, char buffer[], string path)
{
    // struct bmpHeader header;
    string error = "Error processing \"" + path + "\"\n";

    if ((buffer[0] != 'B') || (buffer[1] != 'M'))
    {
        cerr << error << " It isn't a bmp format\n";
        return -1;
    }
    header.caracB = buffer[0];
    header.caracM = buffer[1];
    header.file_size = (unsigned char)buffer[2] + (unsigned char)buffer[3] * 256 + (unsigned char)buffer[4] * 65536 + (unsigned char)buffer[5] * 16777216;
    header.reserved = (unsigned char)buffer[6] + (unsigned char)buffer[7] * 256 + (unsigned char)buffer[8] * 65536 + (unsigned char)buffer[9] * 16777216;
    header.offset = (unsigned char)buffer[10] + (unsigned char)buffer[11] * 256 + (unsigned char)buffer[12] * 65536 + (unsigned char)buffer[13] * 16777216;
    header.header_size = (unsigned char)buffer[14] + (unsigned char)buffer[15] * 256 + (unsigned char)buffer[16] * 65536 + (unsigned char)buffer[17] * 16777216;
    header.width = (unsigned char)buffer[18] + (unsigned char)buffer[19] * 256 + (unsigned char)buffer[20] * 65536 + (unsigned char)buffer[21] * 16777216;
    header.height = (unsigned char)buffer[22] + (unsigned char)buffer[23] * 256 + (unsigned char)buffer[24] * 65536 + (unsigned char)buffer[25] * 16777216;
    header.planes = (unsigned char)buffer[26] + (unsigned char)buffer[27] * 256;
    if (header.planes != 1)
    {
        cerr << error << " Number of planes is not 1\n";
        return -1;
    }
    header.bpp = (unsigned char)buffer[28] + (unsigned char)buffer[29] * 256;
    if (header.bpp != 24)
    {
        cerr << error << " Bit count is not 24\n";
        return -1;
    }
    header.compress = (unsigned char)buffer[30] + (unsigned char)buffer[31] * 256 + (unsigned char)buffer[32] * 65536 + (unsigned char)buffer[33] * 16777216;
    if (header.compress != 0)
    {
        cerr << error << " Compression is not 0\n";
        return -1;
    }
    header.img_size = (unsigned char)buffer[34] + (unsigned char)buffer[35] * 256 + (unsigned char)buffer[36] * 65536 + (unsigned char)buffer[37] * 16777216;
    header.res_x = (unsigned char)buffer[38] + (unsigned char)buffer[39] * 256 + (unsigned char)buffer[40] * 65536 + (unsigned char)buffer[41] * 16777216;
    header.res_y = (unsigned char)buffer[42] + (unsigned char)buffer[43] * 256 + (unsigned char)buffer[44] * 65536 + (unsigned char)buffer[45] * 16777216;
    header.colors = (unsigned char)buffer[46] + (unsigned char)buffer[47] * 256 + (unsigned char)buffer[48] * 65536 + (unsigned char)buffer[49] * 16777216;
    header.important_c = (unsigned char)buffer[50] + (unsigned char)buffer[51] * 256 + (unsigned char)buffer[52] * 65536 + (unsigned char)buffer[53] * 16777216;
    return 0;
}

//------------------------------------------------------------------------
// Escribir los datos obligatorios en el header
void writeHeader(ofstream outFile, struct bmpHeader header)
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

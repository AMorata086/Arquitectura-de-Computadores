#include "gethead.hpp"
#include <iostream>
#include <fstream>

using namespace std;

struct bmpHeader
{
    // Cabecera de 54 bytes de un fichero Bitmap
    char caracB;        // Caracter B
    char caracM;        // Caracter M
    uint32_t file_size; /* Tamaño del archivo */
    uint32_t reserved;  /* Reservado */
    // uint16_t resv2;     /* Reservado */
    uint32_t offset;      /* Offset hasta hasta los datos de imagen */
    uint32_t header_size; /* Tamaño de la cabecera */
    uint32_t width;       /* Ancho en pixeles */
    uint32_t height;      /* Alto  en pixeles */
    uint16_t planes;      /* Planos de color (Siempre 1) */
    uint16_t bpp;         /* tamaño de punto en bits */
    uint32_t compress;    /* compresión */
    uint32_t img_size;    /* tamaño de los datos de imagen */
    uint32_t res_x;       /* Resolución horizontal en bits por metro */
    uint32_t res_y;       /* Resolución vertical en bits por metro */
    uint32_t colors;      /* tamaño de la tabla de color */
    uint32_t important_c; /* Contador de colores importantes. 0 si son todos */
};

int getHeader(char buffer[], string path, struct bmpHeader &header)
{

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
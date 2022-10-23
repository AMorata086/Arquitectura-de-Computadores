#ifndef _SOA_H
#define _SOA_H
#include <vector>
#include <iostream>

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

int getHeader(struct bmpHeader header, char *buffer, string path);

struct soa_img
{
    vector<int> azul;
    vector<int> verde;
    vector<int> rojo;
};

void getDataSOA(ifstream inFile, int height, int width, struct soa_img image);
void writeDataSOA(ofstream outFile, int height, int width, struct soa_img image);

#endif _SOA_H
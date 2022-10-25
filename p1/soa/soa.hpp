#ifndef _SOA_H
#define _SOA_H
#include <vector>
#include <iostream>

int getHeader(struct bmpHeader header, char *buffer, string path);

struct soa_img
{
    vector<int> azul;
    vector<int> verde;
    vector<int> rojo;
};

void getDataSOA(ifstream inFile, int height, int width, struct soa_img image);
void writeDataSOA(ofstream outFile, int height, int width, struct soa_img image);

#endif
#ifndef _AOS_H
#define _AOS_H

#include <fstream>
#include <cstring>
#include <string>

using namespace std;

struct aos_img
{
    int azul;
    int verde;
    int rojo;
};

void getDataAOS(ifstream inFile, int height, int width, struct aos_img image[]);
void writeDataAOS(ofstream outFile, int height, int width, struct aos_img image[]);

#endif
#ifndef _AOS_H
#define _AOS_H

#include <fstream>
#include <cstring>
#include <string>
#include "imageaos.cpp"

using namespace std;

typedef struct aos_img;

void getDataAOS(struct bmpHeader &header, vector<struct aos_img> &image, string path);
void writeDataAOS(ofstream outFile, int height, int width, struct aos_img image[]);

#endif
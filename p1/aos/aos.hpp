#ifndef _AOS_H
#define _AOS_H

#include <fstream>
#include <cstring>
#include <string>
#include "imageaos.cpp"

using namespace std;

typedef struct aos_img;

void getDataAOS(struct bmpHeader &header, vector<struct aos_img> &image, string path);
void writeDataAOS(struct bmpHeader &header, vector<struct aos_img> &newimage, string path);
void gauss(struct bmpHeader &header, vector<struct aos_img> &image, vector<struct aos_img> &imageNew);
void mono(struct bmpHeader &header, vector<struct aos_img> &image, vector<struct aos_img> &imageNew);

#endif
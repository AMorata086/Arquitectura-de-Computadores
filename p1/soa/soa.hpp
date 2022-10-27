#ifndef _SOA_H
#define _SOA_H
#include <vector>
#include <iostream>
#include "imagesoa.cpp"

typedef struct soa_img;

void getDataSOA(struct bmpHeader &header, struct soa_img &image, string path);
void writeDataSOA(struct bmpHeader &header, struct soa_img &image, string path);
void gauss(struct bmpHeader &header, struct soa_img &image, struct soa_img &imageNew);
void mono(struct bmpHeader &header, struct soa_img &image, struct soa_img &imageNew);
#endif
#ifndef _GETHEAD_H
#define _GETHEAD_H

#include <fstream>
#include "gethead.cpp"

using namespace std;

typedef struct bmpHeader;

int getHeader(char buffer[], string path, struct bmpHeader &header);
int writeHeader(string path, struct bmpHeader &header);

#endif
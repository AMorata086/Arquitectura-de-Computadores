#ifndef _PROGARGS_H
#define _PROGARGS_H
#include "progargs.cpp"

int not3Args(int argc);

int wrongValue(char *argv[]);

int checkInDir(char *argv[]);

int checkoutDir(char *argv[]);

int argsCheck(int argc, char *argv[]);

#endif
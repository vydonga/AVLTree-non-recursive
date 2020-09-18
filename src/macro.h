#ifndef _VERSION_H
#define _VERSION_H
#include <stdio.h> 
#include <stdlib.h>
#include <stdint.h>

#define Hello() printf("Hello world!\n");
typedef struct SV
{
    char* name;
    int id;
}SV;
int print_int(int x) { return x; }
double print_dbl(double x) { return x; }
SV print_SV(SV x){return x;}
void print_default() { puts("unknown argument\n"); }

#define print(X) _Generic((X), \
        int: print_int, \
        double: print_dbl, \
        SV: print_SV,\
        default: print_default)(X)




#endif

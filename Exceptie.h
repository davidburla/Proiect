#ifndef EXCEPTIE_H
#define EXCEPTIE_H


#include <iostream>
#include <string.h>
using namespace std;

class Exceptie
{
    char catEx[50], tipEx[50], infoEx[100];
public:
    Exceptie(char _catEx[], char _tipEx[], char _infoEx[]);

    void Print(void);
};

#endif // EXCEPTIE_H

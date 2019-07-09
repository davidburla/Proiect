#ifndef PERSOANA_H
#define PERSOANA_H
#include <string.h>
#include <iostream>
#include <fstream>
#include "data_c.h"
using namespace std;


class Persoana: public Data
{
    public:
        Persoana(char _name[]="name_ndef", char _pren[]="prenume_ndef", char _nCnp[]="cnp_ndef");
        ~Persoana();
        virtual char* Print();
        char* retCNP();
        char* retNume();
        char* retPrenume();
        char* retNumePrenume();

        friend istream& operator>>(istream &c, Persoana &p);
        friend ostream& operator<<(ostream &c, Persoana &p);
    protected:

        char nume[20];
        char prenume[20];
        char CNP[20];
    private:






};

#endif // PERSOANA_H

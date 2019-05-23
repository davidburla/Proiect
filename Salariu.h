#ifndef SALARIU_H
#define SALARIU_H
#include <iostream>
using namespace std;


class Salariu
{
    public:
        Salariu(float _val=1900.0, float _bon=0.0);
        char* Print();
        float retVal();
        float retBon();
        float retSlariu();
        void SchimbareSalariu();
        void SchimbareBonificatie();
        void operator+(float x);
        ~Salariu();

        friend istream& operator>>(istream&c, Salariu &a);
        friend ostream& operator<<(ostream&c, Salariu &a);

    protected:

    //private:
        float valoare;
        float bonificatie;
};

#endif // SALARIU_H

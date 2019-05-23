#ifndef FUNCTIE_H
#define FUNCTIE_H

#include <iostream>
using namespace std;
class Functie
{
    public:
        Functie(char _den[]="angajat");
        char* Print();
        char* retFunctie();
        double ret_Sal();
        ~Functie();

        friend istream& operator>>(istream&c, Functie &a);
        friend ostream& operator<<(ostream&c, Functie &a);
    protected:

   // private:
        char denumire[20];
        double salariu_start;
};

#endif // FUNCTIE_H

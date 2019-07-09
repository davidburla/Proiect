#ifndef ANGAJAT_H
#define ANGAJAT_H
#include "Persoana.h"
#include "Salariu.h"
#include "Functie.h"
#include "Departament.h"
#include <iostream>
#include "Exceptie.h"
using namespace std;


class Angajat: public Persoana, public Salariu, public Functie, public Departament
{
    public:
        Angajat(Persoana &p, Functie &f, Salariu&s, Departament &d) : Persoana::Persoana(p), Salariu (s),Functie::Functie(f), Departament::Departament(d)
        {
            ID = ++n_ID;
        }
        Angajat();
        virtual ~Angajat();

        char* Print();
        friend istream& operator>>(istream&c, Angajat &a);
        friend ostream& operator<<(ostream&c, Angajat &a);
        void SalvareDateFisier(Angajat &a);
        int operator==(Angajat&a);
    protected:

    private:
        int ID;
        static int  n_ID;
};











#endif // ANGAJAT_H

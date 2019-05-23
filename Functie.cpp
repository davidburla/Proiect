#include "Functie.h"
#include <string.h>
#include <iostream>
using namespace std;
Functie::Functie(char _den[])
{
    if(strcmp(_den, "angajat")!=0 && strcmp(_den, "director")!=0 &&
            strcmp(_den, "contabil")!=0 && strcmp(_den, "secretar")!=0 )
    {
        cout<<"Functie inexistenta";
        strcpy(denumire, "_n_def_");
    }
    else
        strcpy(denumire, _den);
    salariu_start=1900;
}
char* Functie::Print()
{
    return strcat(denumire, " ");
}
char* Functie::retFunctie()
{
    return denumire;
}
double Functie::ret_Sal()
{
    return salariu_start;
}
Functie::~Functie() {};
istream& operator>>(istream&c, Functie &a)
{
    char _den[20];
    cout<<"\nDati numele functiei: ";
    do
    {
        c>>_den;
        if(strcmp(_den, "angajat")==0 || strcmp(_den, "director")==0 ||
            strcmp(_den, "contabil")==0 || strcmp(_den, "sectretar")==0 )
        {
            break;
        }
        cout<<"Functie inexistenta\n";
    }while(1);
    strcpy(a.denumire, _den);
    return c;
}
ostream& operator<<(ostream&c, Functie &a)
{
    c<<"Functia: "<<a.denumire<<", salariu start: "<<a.salariu_start;
    return c;
}

#include "Departament.h"
#include <string.h>
#include <iostream>
using namespace std;
Departament::Departament(char _den[])
{
    if(strcmp(_den, "resurse_umane")!=0 && strcmp(_den, "administrare")!=0 &&
       strcmp(_den, "contabilitate")!=0 && strcmp(_den, "secretariat")!=0 )
    {
        strcpy(dep_nume, "angajati");
    }
    else
        strcpy(dep_nume, _den);
}
char* Departament::Print()
{
    return strcat(dep_nume, " ");
}
char* Departament::retDepartament()
{
    return dep_nume;
}
Departament::~Departament(){};
istream& operator>>(istream&c, Departament &a)
{
    char _den[20];
    cout<<"Dati numele departamentului: ";
    do{
        c>>_den;
        if(strcmp(_den, "resurse_umane")==0 || strcmp(_den, "administrare")==0 ||
       strcmp(_den, "contabilitate")==0 || strcmp(_den, "secretariat")==0 || strcmp(_den, "angajati")==0 )
       {
           break;
       }
       cout<<"Departament inexistent!\n";
    }while(1);
    strcpy(a.dep_nume, _den);
    return c;
}
ostream& operator<<(ostream&c, Departament &a)
{
    c<<"Nume departament: "<<a.dep_nume;
    return c;
}

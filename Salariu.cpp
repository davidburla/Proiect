#include "Salariu.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
Salariu::~Salariu()
{
    //dtor
}
Salariu::Salariu(float _val, float _bon)
{
    valoare=_val;
    bonificatie=_bon;
}
char* Salariu::Print()
{
    int decimal, sign;
    char* x=ecvt(valoare+bonificatie, 4, &decimal, &sign);
    strcat(x, " ");
    return x;
}
float Salariu::retVal()
{
    return valoare;
}
float Salariu::retBon()
{
    return bonificatie;
}
float Salariu::retSlariu()
{
    return valoare+bonificatie;
}
void Salariu::SchimbareSalariu()
{
    cout<<"Introduceti unitatea de crestere salariu: ";
    float x;
    cin>>x;
    valoare+=x;
}
void Salariu::operator+(float x)
{
    valoare+=x;
}
void Salariu::SchimbareBonificatie()
{
    cout<<"Introduceti unitatea de crestere bonificate: ";
    float x;
    cin>>x;
    bonificatie+=x;
}
istream& operator>>(istream&c, Salariu &a)
{
    cout<<"Dati valoare salariu: ";
    float x;
    do
    {
        cin>>x;
        if(x>=1000)
            break;
        cout<<"Valaoare nevalida!"<<endl;
    }while(1);
    a.valoare=x;
    cout<<"Dati valoare bonificatie: ";
    do
    {
        cin>>x;
        if(x>=0)
            break;
        cout<<"Valaoare nevalida!"<<endl;
    }while(1);
    a.bonificatie=x;
    return c;
}
ostream& operator<<(ostream&c, Salariu &a)
{
    c<<"Salariu: "<<a.valoare<<", bonificatie: "<<a.bonificatie<<endl;
    return c;
}



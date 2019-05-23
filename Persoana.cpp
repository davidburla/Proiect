#include "Persoana.h"
#include "Exceptie.h"

Persoana::~Persoana()
{
    //dtor
}
Persoana::Persoana(char _name[], char _pren[], char _nCnp[])
{

    strcpy(nume, _name);
    strcpy(prenume, _pren);
    strcpy(CNP, _nCnp);
    Data_nastere(_nCnp);
}
char* Persoana::Print()
{
    char *n= new char[50];
    //strcpy(n, "\n");
    strcpy(n, retNume());
    //cout<<n<<endl;
    strcat(n, " ");
    //cout<<n<<endl;
    strcat(n, retPrenume());
    //strcat(n, retPrenume());
    //cout<<n<<endl;
    //cout<<n;
    return n;
    //cout<<strcat(retNume(), retPrenume());
    //return "da";


}
char* Persoana::retNumePrenume()
{
    char *n= new char[50];
    //strcpy(n, "\n");
    strcpy(n, retNume());
    //cout<<n<<endl;
    strcat(n, " ");
    //cout<<n<<endl;
    strcat(n, retPrenume());
    return n;
}

char* Persoana::retCNP()
{
    return CNP;
}
istream& operator>>(istream &c, Persoana &p)
{
    cout<<endl<<"Nume: ";
    cin>>p.nume;
    cout<<"Prenume: ";
    cin>>p.prenume;
    cout<<"CNP: ";
    cin>>p.CNP;
    return c;
}
ostream& operator<<(ostream &c, Persoana &p)
{
    c<<"Nume: "<<p.nume<<endl;
    c<<"Prenume: "<<p.prenume<<endl;
    c<<"CNP: "<<p.CNP<<endl;
    return c;
}
char* Persoana::retNume()
{
    return nume;
}
char* Persoana::retPrenume()
{
    return prenume;
}

#include "Angajat.h"
#include <string.h>
#include <stdlib.h>
#include "Exceptie.h"
int Angajat::n_ID=0;
Angajat:: Angajat()
{
    ID=++n_ID;
}
Angajat::~Angajat()
{
    //dtor
}
char* Angajat::Print()
{
    //cout<<endl<<"Test in print angajat: "<<this->Persoana::Print()<<endl;
    char* x = new char( 100);
    itoa(ID,x,10);
    strcat(x, " ");
    //cout<<"\nTest nume in angajat: "<<Persoana::retNume()<<endl;
    strcat(x, Persoana::retNume());
    strcat(x, " ");
    strcat(x, Persoana::retPrenume());
    strcat(x," ");

    strcat(x, Functie::Print());
    strcat(x, Salariu::Print());
    strcat(x, Departament::Print());
    //return strcat(strcat(strcat(strcat(x, Persoana::Print()), Functie::Print()), Salariu::Print()), Departament::Print());
    return x;
}
istream& operator>>(istream&c, Angajat &a)
{
    cout<<endl<<"Nume: ";
    cin>>a.nume;
    cout<<"Prenume: ";
    cin>>a.prenume;


    int ok=1;
    char _CNP[20];
    while(ok!=0)
    {
        try
        {
            cout<<"CNP: ";
            cin>>_CNP;
            if(strlen(_CNP)==13)
            {
                for(int i=0; i<strlen(_CNP); i++)
                    if(isdigit(_CNP[i])==0)
                        throw Exceptie("CNP", "forma nevalida", "13 cifre, fara litere");
            }
            else
            {
                throw Exceptie("CNP", "forma nevalida", "13 cifre");
            }
            strncpy(a.CNP, _CNP, 13);
            a.Data_nastere(_CNP);

            float x;
            cout<<"Dati valoare salariu: ";
            cin>>x;
            if(x<1000)
            {
                throw Exceptie("Salariu: ","valoare nevalida", ">= 1000" );
            }
            a.valoare=x;


            cout<<"Dati valoare bonificatie: ";
            cin>>x;
            if(x<0)
            {
                throw Exceptie("Salariu: ", "bonificatie nevalida",">= 0" );
            }
            a.bonificatie=x;

            char _den[20];
            cout<<"Dati numele functiei: ";
            c>>_den;
            if(strcmp(_den, "angajat")!=0 && strcmp(_den, "director")!=0 &&
                    strcmp(_den, "contabil")!=0 && strcmp(_den, "secretar")!=0 )
                throw Exceptie("Functie", "nume nevalid", "angajat / director / contabil / secretar");
            strcpy(a.denumire, _den);

            cout<<"Dati numele departamentului: ";
            c>>_den;
            if(strcmp(_den, "resurse_umane")!=0 && strcmp(_den, "administrare")!=0 &&
                strcmp(_den, "contabilitate")!=0 && strcmp(_den, "secretariat")!=0 )
                    throw Exceptie("Departament", "nume nevalid", "resurse_umane / administrare / contabilitate / secretariat");
            strcpy(a.dep_nume, _den);
            ok=0;

        }
        catch(Exceptie e)
        {
            e.Print();
            ok = 1;
        }
        catch(...)
        {
            cout<<"Exceptie nedefinita!"<<endl;
        }
    }
    /*while(ok != 0)
    {
        try
        {
            cout<<"CNP: ";
            cin>>_CNP;
            if(strlen(_CNP)==13)
            {
                for(int i=0; i<strlen(_CNP); i++)
                    if(isdigit(_CNP[i])==0)
                        throw Exceptie("CNP", "forma nevalida", "13 cifre, fara litere");
            }
            else
            {
                throw Exceptie("CNP", "forma nevalida", "13 cifre");
            }
            strncpy(a.CNP, _CNP, 13);
            a.Data_nastere(_CNP);
            ok=0;
        }
        catch(Exceptie e)
        {
            e.Print();
            ok = 1;
        }
        catch(...)
        {
            cout<<"Exceptie nedefinita!"<<endl;
        }
    }
    float x;
    ok=1;
    while(ok != 0)
    {
        try
        {
            cout<<"Dati valoare salariu: ";
            cin>>x;
            if(x<1000)
            {
                throw Exceptie("Salariu: ","valoare nevalida", ">= 1000" );
            }
            a.valoare=x;
            ok=0;
        }
        catch(Exceptie e)
        {
            e.Print();
            ok = 1;
        }
        catch(...)
        {
            cout<<"Exceptie nedefinita!"<<endl;
        }
    }
    ok=1;
    while(ok != 0)
    {
        try
        {
            cout<<"Dati valoare bonificatie: ";
            cin>>x;
            if(x<0)
            {
                throw Exceptie("Salariu: ", "bonificatie nevalida",">= 0" );
            }
            a.bonificatie=x;
            ok=0;
        }
        catch(Exceptie e)
        {
            e.Print();
            ok = 1;
        }
        catch(...)
        {
            cout<<"Exceptie nedefinita!"<<endl;
        }
    }
    char _den[20];
    ok=1;
    while(ok != 0)
    {
        try
        {
            cout<<"Dati numele functiei: ";
            c>>_den;
            if(strcmp(_den, "angajat")!=0 && strcmp(_den, "director")!=0 &&
                    strcmp(_den, "contabil")!=0 && strcmp(_den, "secretar")!=0 )
                throw Exceptie("Functie", "nume nevalid", "angajat / director / contabil / secretar");
            strcpy(a.denumire, _den);
            ok=0;
        }
        catch(Exceptie e)
        {
            e.Print();
            ok = 1;
        }
        catch(...)
        {
            cout<<"Exceptie nedefinita!"<<endl;
        }
    }
    ok=1;
    while(ok != 0)
    {
        try
        {
            cout<<"Dati numele departamentului: ";
            c>>_den;
            if(strcmp(_den, "resurse_umane")!=0 && strcmp(_den, "administrare")!=0 &&
                strcmp(_den, "contabilitate")!=0 && strcmp(_den, "secretariat")!=0 )
                    throw Exceptie("Departament", "nume nevalid", "resurse_umane / administrare / contabilitate / secretariat");
            strcpy(a.dep_nume, _den);
            ok=0;
        }
        catch(Exceptie e)
        {
            e.Print();
            ok = 1;
        }
        catch(...)
        {
            cout<<"Exceptie nedefinita!"<<endl;
        }
    }*/

    return c;

}
ostream& operator<<(ostream&c, Angajat &a)
{
    cout<<"\nID: "<<a.ID;
    cout<<"\nNume: "<<a.nume<<" "<<a.prenume;
    cout<<"\nFunctie: "<<a.denumire;
    cout<<"\nSalariu: "<<a.retSlariu();
    cout<<"\nDepartament: "<<a.dep_nume;
    return c;
}
int Angajat::operator==(Angajat&a)
{
    if(strcmp(CNP,a.CNP)==0 || strcmp(nume, a.nume)==0)
        return 1;
    else
        return 0;
}

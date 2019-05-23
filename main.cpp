#include <iostream>
#include "Persoana.h"
#include "Angajat.h"
#include "Salariu.h"
#include "Functie.h"
#include "Departament.h"
#include "data.h"
#include "listai.h"
#include "Exceptie.h"
#include "functii.h"
#include <conio.h>
#include <cstdlib>

#define N 4
using namespace std;



int main()
{
    cout<<" Date de acces! \n";
    cout<<"UserName: proiect\n"<<"Password: 3122";
    getch();
    clear();
    char opt;
    int ok = 1, log=0;
    LISTA lst = newl();
    lst=CitireFisier("data_angajati.txt", lst);
    //SalvareDateFisier(lst);
    do
    {
        opt=meniu_intrare();
        switch(opt)
        {
        case '1':
        {
            if(log==0)
            {
                cout<<" Logare: "<<endl;
                logare();
                log=1;
            }
            getch();
            clear();
            char o;
            do
            {
                o=meniu_functii();
                switch(o)
                {
                case '1':
                {
                    cout<<"Interogare";
                    char o;
                    do
                    {
                        clear();
                        o=meniu_interogare();
                        switch(o)
                        {
                        case '1':
                        {
                            Afisare(lst);
                            getch();
                            clear();
                            break;
                        }
                        case '2':
                        {
                            AfisareDataN(lst);
                            getch();
                            clear();
                            break;
                        }
                        case '3':
                        {
                            cout<<"-Informatii complete-\t\n";

                            AfisareCompleta(lst);
                            getch();
                            clear();
                            break;
                        }
                        case 'X':
                        {
                            cout<<"-REVENIRE-"<<endl;
                            getch();
                            clear();
                            break;
                        }

                        }
                    }
                    while(o!='X');
                    break;
                }
                case '2':
                {
                    cout<<"Adauga angajat";
                    Angajat a;
                    cin>>a;
                    lst=ins_la_urma(lst, a);
                    //SalvareDateFisier(lst);
                    getch();
                    clear();
                    break;
                }
                case '3':
                {
                    cout<<"Sterge angajat\n";
                    char *aux=new char[40];
                    cout<<"Introduceti CNP-ul persoanei: ";
                    getchar();
                    gets(aux);
                    cout<<endl;
                    lst=sterge_element(lst,aux);
                    //SalvareDateFisier(lst);
                    getch();
                    clear();
                    break;
                }
                case '4':
                {
                    clear();
                    cout<<"\n- SALARII - \n";
                    char o;
                    do
                    {
                        o=meniu_salarii();
                        switch(o)
                        {
                        case '1':
                        {
                            cout<<"Salariu pentru  achitare pe aceasta luna este de: "<<SalariuComplet(lst)<<" RON.";
                            getch();
                            clear();
                            break;
                        }
                        case '2':
                        {
                            SalariuPersoane(lst);
                            getch();
                            clear();
                            break;
                        }
                        case '3':
                        {
                            char *aux=new char[40];
                            int p;
                            int x=3;
                            do
                            {
                                cout<<"Introduceti CNP-ul persoanei: ";
                                fflush(stdin);
                                cin>>aux;
                                p=Cautare_Cnp(lst, aux);
                                if (p)
                                    break;
                            }
                            while(1 || strcmp(aux, "x")!=0);
                            lst=SchimbareSalariu(lst, aux);
                            delete(aux);
                            getch();
                            clear();
                            break;
                        }
                        case 'X':
                        {
                            cout<<"REVENIRE";
                            getch();
                            clear();
                            break;
                        }
                        }

                    }
                    while(o!='X');
                    break;
                }
                case '5':
                {
                    clear();
                    cout<<"\n-CAUTARE-\n";

                    char m;
                    do
                    {
                        m=meniu_cautare();
                        switch(m)
                        {
                        case '1':
                        {
                            cout<<"\nCautare dupa nume \n";
                            char *n=new char[40];
                            cout<<"Scrieti nume complet: ";
                            fflush(stdin);
                            cin.getline(n, 40, '\n');
                            if(Cautare_Cnp(lst, n)==1)
                            {
                                AfisareComanda(lst, n);
                            }
                            else
                            {
                                cout<<"Nici o inregistrare nu corespunde cautarii!";
                            }
                            delete n;
                            getch();
                            clear();
                            break;
                        }
                        case '2':
                        {
                            clear();
                            cout<<"\nCautare dupa CNP\n";
                            char *n=new char[13];
                            cout<<"Scrieti CNP: ";
                            cin>>n;
                            if(Cautare_Cnp(lst, n)==1)
                            {
                                AfisareComanda(lst, n);
                            }
                            else
                            {
                                cout<<"Nici o inregistrare nu corespunde cautarii!";
                            }
                            delete n;
                            getch();
                            clear();
                            break;
                        }
                        case 'X':
                        {
                            cout<<"\n-REVENIRE-"<<endl;
                            getch();
                            clear();
                            break;
                        }
                        }
                    }
                    while(m!='X');
                    break;
                }
                case 'X':
                {
                    cout<<"REVENIRE";
                    getch();
                    clear();
                }

                };
            }
            while(o!='X');

            break;
        }
        case 'X':
        {
            cout<<" Parasire program.";
            cout<<" \nConfirmare!";
            getch();
            clear();
            SalvareDateFisier(lst);
    destroyl(lst);
            return 0;
            break;
        }
        case 'C':
        {
            cout<<"Copyright (c) : Burla David - 2018-2019 - (G)3122B - FiEsC - C";
            getch();
            clear();
            break;
        }
        };
    }
    while(1);


    return 0;
}

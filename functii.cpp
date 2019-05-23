#include <iostream>
#include "functii.h"
using namespace std;
char user[]="proiect";
char pass[]="3122";
char meniu_intrare()
{
    char opt;
    cout<<"\n 1 ~ Logare\n X ~ Anulare\n C ~ Copyright\n\n";
    do
    {
        cout<<"> > >";
        cin>>opt;
        opt=toupper(opt);
    }while(opt!='1' &&opt!='X' && opt != 'C');
    return opt;
}
char meniu_functii()
{
    char opt;
    cout<<"\n 1 ~ Interogare Angajati\n 2 ~ Adaugare Angajati\n 3 ~ Stergere Angajati\n 4 ~ Salarii\n 5 ~ Cautare angajat\n X ~ Anulare\n";
    do
    {
        cout<<"> > >";
        cin>>opt;
        opt=toupper(opt);
    }while(opt!='1' && opt!='2' && opt != '3' && opt != '4' && opt != '5' && opt != 'X');
    return opt;
}
char meniu_interogare()
{
    char opt;
    cout<<"\n 1 ~ Angajati\n 2 ~ Afisare data nastere\n 3 ~ Afisare informatii[securizat] \n X ~ Anulare\n";
    do
    {
        cout<<"> > >";
        cin>>opt;
        opt=toupper(opt);
    }while(opt!='1' && opt!='2' && opt != '3'  && opt != 'X');
    return opt;
}
char meniu_angajati()
{
    char opt;
    cout<<"\n 1 ~ Afisare angajati\n 2 ~ Afisare date de nastere \n 3  \n X ~ Anulare\n";
    do
    {
        cout<<"> > >";
        cin>>opt;
        opt=toupper(opt);
    }while(opt!='1' && opt!='2' && opt != '3'  && opt != 'X');
    return opt;
}
char meniu_cautare()
{
    char opt;
    cout<<"\n 1 ~ Dupa nume\n 2 ~ Dupa CNP \n X ~ Anulare\n";
    do
    {
        cout<<"> > >";
        cin>>opt;
        opt=toupper(opt);
    }while(opt!='1' && opt!='2' && opt != 'X');
    return opt;
}
char meniu_salarii()
{
    char opt;
    cout<<"\n 1 ~ Salariu complet pe firma\n 2 ~ Salariu pe persoane \n 3 ~ Crestere salariu persoana\n X ~ Anulare\n";
    do
    {
        cout<<"> > >";
        cin>>opt;
        opt=toupper(opt);
    }while(opt!='1' && opt!='2'  && opt!='3' && opt != 'X');
    return opt;
}
void logare()
{
    char n[10], p[10];
    cout<<"UserName: \n > > > ";
    do
    {
        cin>>n;
        if(strcmp(n, user)!=0)
            cout<<"User nevalid! \n > > > ";
        else
            break;
    }while(1);
    cout<<"Password: \n > > > ";
     do
    {
        cin>>p;
        if(strcmp(p, pass)!=0)
            cout<<"Parola gresita!\n > > > ";
        else
            break;
    }while(1);
}
void clear() {
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}


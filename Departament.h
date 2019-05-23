#ifndef DEPARTAMENT_H
#define DEPARTAMENT_H

#include <iostream>
using namespace std;
class Departament
{
    public:
        Departament(char den[]="n_def");
        char* Print();
        ~Departament();
        char* retDepartament();
        friend istream& operator>>(istream&c, Departament &a);
        friend ostream& operator<<(ostream&c, Departament &a);
    protected:

    //private:
        char dep_nume[20];
};

#endif // DEPARTAMENT_H

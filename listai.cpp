#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Angajat.h"
#include "Persoana.h"
#include "Salariu.h"
#include "Functie.h"
#include "Departament.h"
#include "Exceptie.h"
#include "data_c.h"
#include "listai.h"
struct element {
    DATA info;
    struct element *urm;
};
typedef struct element Element;

LISTA newl(){
    return NULL;
}
static ELEMENT creareElement(DATA x, ELEMENT urmator){
    ELEMENT w= (ELEMENT) malloc( sizeof(Element) );
    if(w!=NULL) {
        w->info = x;
        w->urm  = urmator;
    }
    return w;
}
LISTA ins_in_fata(LISTA l, DATA x){
    if(isFull(l)) return l;
    ELEMENT w = creareElement(x, l);
    return w!=NULL ? w : l;
}
LISTA ins_la_urma(LISTA l, DATA x){
    if(isFull(l)) return l;
    ELEMENT w = creareElement(x, NULL);
    if(w!=NULL) {
        if(isEmptyl(l)) {
            return w;
        } else {
            ELEMENT p;
            for(p=l; p->urm!=NULL; p = p->urm) ;
            p->urm = w;
        }
    }
    return l;
}
LISTA sterge_ultimul(LISTA l){
    if(!isEmptyl(l)) {
        if(l->urm == NULL) { //este unicul element
            free(l);
            return NULL;
        }
        else {           // sunt cel putin 2 elemente
            ELEMENT p;
            for(p=l; p->urm->urm!=NULL; p = p->urm) ;
            // p adresa penultimului element
            free(p->urm);  // elimina ultimul
            p->urm = NULL; // penultimul devine ultimul
        }
    }
    return l;
}
LISTA sterge_primul(LISTA l){
    if(!isEmptyl(l))
    {
       ELEMENT p = l->urm;
       free(l);
       return p;
    }
    return l;
}
LISTA sterge_element(LISTA l, char *str){
    int ok=0;
    if(!isEmptyl(l)) {
       ELEMENT p;
       ELEMENT k;
       for(p=l; p->urm!=NULL; p = p ->urm)
       {
           if(/*strcmp(p->info.Persoana::Print() , str) == 0 || */strcmp(p->urm->info.Persoana::retCNP() , str)==0)
           {
               k=p->urm->urm;;
               free(p->urm);
               p->urm=k;
               ok=1;
           }
       }
    }
    if(ok)
    {
        cout<<"S-a sters"<<endl;
    }
    else
        cout<<"Nici un angajat nu corespunde acestei informatii!"<<endl;
    return l;
}
int Cautare_Cnp(LISTA l, char *str)
{
     int ok=0;
    if(!isEmptyl(l)) {
       ELEMENT p;
       for(p=l; p->urm!=NULL; p = p ->urm)
       {
           if(strcmp(p->info.retCNP() , str)==0||strcmp(p->info.Persoana::retNumePrenume(), str)==0)
           {
               return 1;
           }
       }
    }
    return 0;
}
void AfisareComanda(LISTA l, char* str)
{
    if(!isEmptyl(l)) {
       ELEMENT p;
       for(p=l; p->urm!=NULL; p = p ->urm)
       {

           if(strcmp(p->info.Persoana::retCNP() , str)==0 || strcmp(p->info.Persoana::retNumePrenume(), str)==0)
           {
               cout<<p->info;
           }
       }
    }
}
LISTA SchimbareSalariu(LISTA l,char *str)
{
    int ok=0;
    if(!isEmptyl(l)) {
       ELEMENT p;
       for(p=l; p->urm!=NULL; p = p ->urm)
       {
           if(strcmp(p->info.Persoana::retCNP() , str)==0)
           {
               cout<<"Introduceti unitatea de crestere salariu: ";
                float x;
                cin>>x;
                p->info+x;
               //p->info.SchimbareSalariu();
               p->info.SchimbareBonificatie();
               cout<<p->info.Persoana::Print()<<": [complet] - "<<p->info.retSlariu()<<" RON - [din care bonificatii] - "<<p->info.retBon()<<endl;
                break;
            }
       }
    }
    return l;
}
ELEMENT cauta(LISTA l, DATA k) {
    if(!isEmptyl(l)) {
        ELEMENT p;
        for(p=l; p!=NULL; p = p->urm) {
            if(p->info == k) return p;
        }
    }
    return NULL;
}

DATA primul(LISTA l) {
    return isEmptyl(l) ? DATA() : l->info;
}
DATA ultimul(LISTA l){
    if(isEmptyl(l)) return DATA();
    for( ; l->urm!=NULL; l=l->urm);
    return l->info;

}

int nrElemente(LISTA l){
    int n=0;
    for( ; l!=NULL; l=l->urm) n++;
    return n;
}
LOGIC isEmptyl(LISTA l){
    return l==NULL;
}
LOGIC isFull(LISTA l){
    return FALS;
}
char *toStringl(LISTA l,char *s){
    /*char buf[100];
    sprintf(s, "l(%p) ={", l);
    if(isEmptyl(l)) {
            strcat(s, "vida}");
    } else {
        ELEMENT p;
        for(p=l; p!=NULL; p = p->urm) {
            sprintf(buf, "\n%p: {"FORMAT", %p}%c", p, p->info, p->urm,
                                    p->urm==NULL?'}' : ',');
            strcat(s, buf);
        }
    }
    return s;*/
}
// ...
void destroyl(LISTA l) {
    ELEMENT p;
    while(l!=NULL) {
        p=l;
        l = l->urm;
        free(p);
    }
}
void Afisare(LISTA l)
{
    if(isEmptyl(l)) {
        cout<<"Nu exista angajati!"<<endl;
    } else {
        ELEMENT p;
        for(p=l; p!=NULL; p = p->urm) {
            cout<<p->info<<endl;
        }
    }
}
void AfisareDataN(LISTA l)
{
    if(isEmptyl(l)) {
        cout<<"Nu exista angajati!"<<endl;
    } else {
        ELEMENT p;
        for(p=l; p!=NULL; p = p->urm) {
            cout<<p->info.Persoana::Print()<<"\b - "<<p->info.Data_()<<endl;
        }
    }
}
void AfisareCompleta(LISTA l)
{
    if(isEmptyl(l)) {
        cout<<"Nu exista angajati!"<<endl;
    } else {
        ELEMENT p;
        for(p=l; p!=NULL; p = p->urm) {
            cout<<"\t"<<p->info.Persoana::Print()<<" - \nCNP: "<<p->info.retCNP()<<" - \nData nastere: "<<p->info.Data::Data_()<< " - \nFunctie: " << p->info.retFunctie();
            cout<<" - \nDepartament: "<<p->info.Departament::retDepartament()<<" -  \nSalariu [complet] - "<<p->info.Salariu::retSlariu()<<" RON - [brut] - "<<p->info.Salariu::retVal()<<" RON - [bonificatii] - "<<p->info.Salariu::retBon()<<endl<<endl;
        }
    }

}

float SalariuComplet(LISTA l)
{
    float x=0;
    if(isEmptyl(l)) {
        cout<<"Nu sunt date!"<<endl;
    } else {
        ELEMENT p;
        for(p=l; p!=NULL; p = p->urm) {
            x=x+p->info.retSlariu();
        }
    }
    return x;
}
void SalariuPersoane(LISTA l)
{
    if(isEmptyl(l)) {
        cout<<"Nu sunt date!"<<endl;
    } else {
        ELEMENT p;
        for(p=l; p!=NULL; p = p->urm) {
            cout<<p->info.Persoana::Print()<<": [complet] - "<<p->info.retSlariu()<<" RON - [din care bonificatii] - "<<p->info.retBon()<<endl;
        }
    }
}


LISTA CitireFisier(char* NumeFisier, LISTA l)
{
    ifstream f(NumeFisier);

    char _nume[20];
    char _prenu[20];
    char _cnp[13], c[20];
    int n;
    f>>n;
    for(int i=1; i<=n; i++)
    {
        f>>_nume;
        f>>_prenu;
        strcpy(c, _prenu);
        f>>_cnp;

        Persoana p(_nume, c, _cnp);
        //cout<<p.retNume()<<" "<<p.retPrenume()<<" "<<p.retCNP()<<endl;

        f>>_nume;
        Functie f1(_nume);

        f>>_nume;
        f>>_prenu;

        float x = atof(_nume);
        float y = atof(_prenu);
        Salariu s(x, y);
        f>>_nume;
        Departament d(_nume);
        Angajat a(p, f1, s, d);
        l=ins_la_urma(l, a);
    }
    return l;
}
void SalvareDateFisier(LISTA l)
{
    char s[200];
    ofstream g("ANGAJATI.txt");
    if(!g.is_open())
        Exceptie("Scriere fisier","verificare declaratie", "");
    else
    {
        if(isEmptyl(l)) {
            g<<"Nu exista angajati!"<<endl;
    } else {
        ELEMENT p;
        for(p=l; p!=NULL; p = p->urm)
        {
            strcpy(s,p->info.Print());
            g<<s<<endl;
        }
    }
    }

}

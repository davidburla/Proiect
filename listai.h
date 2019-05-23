#ifndef LISTAI_H_INCLUDED
#define LISTAI_H_INCLUDED

#include "data.h"
//-----------------------------------
// Proprietatile TDA lista inlantuita
//

typedef struct element *ELEMENT;
typedef struct element *LISTA;
//
//----------------------------------
// Metodele (operatiile) TDA
//
LISTA newl();
LISTA ins_in_fata(LISTA l, DATA x);
LISTA ins_la_urma(LISTA l, DATA x);
LISTA sterge_primul(LISTA l);
LISTA sterge_ultimul(LISTA l);
ELEMENT cauta(LISTA l, DATA k);
DATA primul(LISTA l);
DATA ultimul(LISTA l);
int nrElemente(LISTA l);
LOGIC isEmptyl(LISTA l);
LOGIC isFull(LISTA l);
char *toStringl(LISTA l,char *s);
void Afisare(LISTA l);
LISTA CitireFisier(char* NumeFisier, LISTA l);
void SalvareDateFisier(LISTA l);
LISTA sterge_element(LISTA l, char *str);
float SalariuComplet(LISTA l);
void SalariuPersoane(LISTA l);

int Cautare_Cnp(LISTA l, char *s);
LISTA SchimbareSalariu(LISTA l, char *str);
void AfisareDataN(LISTA l);
void AfisareCompleta(LISTA l);
void AfisareComanda(LISTA l, char* str);
// ...
void destroyl(LISTA l);
#endif

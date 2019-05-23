#include "Exceptie.h"

Exceptie::Exceptie(char _catEx[], char _tipEx[], char _infoEx[])
    {
        strcpy(catEx, _catEx );
        strcpy(tipEx, _tipEx );
        strcpy(infoEx, _infoEx );
    }
void Exceptie::Print(void)
    {
        cerr<<"Exceptie ["<<catEx<<"] - "<<tipEx<<" [ Indicatii] "<<infoEx<<endl;
    }

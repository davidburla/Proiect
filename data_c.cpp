#include "data_c.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
void Data :: Data_nastere(char cnp[13])
{
    int an, luna, zi;
    an=(cnp[1]-'0')*10+cnp[2]-'0';
    if(an>18)
        an=19*100+an;
    else
        an=20*100+an;
    luna=(cnp[3]-'0')*10+cnp[4]-'0';
    zi=(cnp[5]-'0')*10+cnp[6]-'0';
    SetData(an, luna, zi);
}
void Data :: SetData( int an, int luna, int zi)
{
    _an=an;
    _luna=luna;
    _zi=zi;
}
char* Data :: Print(void)
{
    char ziua[30];
    sprintf(ziua, "%3d %s %4d",_zi , luni[_luna-1], _an);
    return ziua;

}
char* Data::Data_()
{
    char * ziua=new char[30];
    sprintf(ziua, "\n%4d %s %3d",_zi , luni[_luna-1], _an);
    return ziua;
}
int Data::an()
{
    return _an;
}

int Data::zi()
{
    return _zi;
}
int Data::luna()
{
    return _luna;
}
int Data::bisect(int an){
    if(an%4==0)
        if(an%100!=0)
            return 1;
        else if(an%100==0 && an%400==0);
            return 1;
    return 0;
}
int Data :: NrZile( Data t )
{
    int zile=0, i;
    if(_zi<t._zi)
    {
        zile=-(_zi-t._zi)+zi_l[_luna-1];
        _luna++;
    }
    else
        zile=zile+_zi-t._zi;
    if(this->_luna<t._luna)
    {
        for(i=_luna;i<t._luna;i++)
            zile=zile-zi_l[i-1];
        if(bisect(_an))
            zile=zile+366;
        else
            zile = zile+365;
        _an--;
    }
    else
        for(i=_luna;i<t._luna; i++)
            zile=zile+zi_l[i-1];
    if(_an<t._an)
    {
        for(i=_an; i<t._an;i++)
            if(bisect(i))
                zile=zile+366;
            else
                zile=zile+365;
    }
    else
        for(i=t._an+1; i<=_an;i++)
            if(bisect(i))
                zile=zile+366;
            else
                zile=zile+365;
    return zile;
}


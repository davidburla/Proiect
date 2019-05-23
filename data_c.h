#ifndef DATA_C_H_INCLUDED
#define DATA_C_H_INCLUDED
#include <string>
#include <map>

using namespace std;
class Data {
    int _an, _luna, _zi;
public:
    void SetData( int an, int luna, int zi );
    char* Print();
    char* Data_();
    char*  luni[12]= {"IANUARIE", "FEBRUARIE", "MARTIE",
    "APRILIE", "MAI", "IUNIE", "IULIE", "AUGUST",
    "SEPTEMBRIE","OCTOMBRIE", "NOIEMBRIE",
    "DECEMBRIE"};
    int zi_l[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    //BASEPAIRS = { "T": "A", "A": "T", "G": "C", "C": "G" }
    int NrZile( Data t );
    int an();
    int zi();
    int luna();
    int bisect(int an);
    void Data_nastere(char* cnp);
};

#endif // DATA_C_H_INCLUDED

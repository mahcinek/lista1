#include <sstream>
#include <vector>
#include <cstdlib>
#include <iterator>
#include <stdlib.h>
#include "CTable.h"
#include <iostream>
#include <iterator>
#include <sstream>
#include "string.h"
#include "Osoba.h"
#include <cstdlib>



int main() {
    using namespace std;
    CTable<string*> STR (5,"string"); // CTable wskaźników na string
    STR.setValue(new string ("a"),1);
    cout<<*STR.getValue(1)<<endl;
    int *tablica = new int [3];
    tablica[0]=1;
    tablica[1]=2;
    CTable<int*> taboftabs (2,"tablicaTablic",tablica); //Ctable tablic int
    int *pobrana= taboftabs.getValue(0);
    cout<<pobrana[0]<<endl;
    cout<<pobrana[1]<<endl;
    CTable<string> A(1,"ssa","jup"); //Ctable string
    try{
    A.setValue("a",0);
    A.setValue("b",1);}
    catch (int w)
    {if (w==-1) cout<<"Podany element jest spoza zakresu CTable"<<endl;}
    try {
        cout << A.getValue(3);
    }
    catch (int wyj){if (wyj==-1) cout<<"liczba spoza zakresy CTable"<<endl;}
    Osoba a (10,"a");
    CTable<Osoba> osobaTable (5,"osobaTab",a);
    try{
        cout<<osobaTable.getValue(0).toString()<<endl;
    }
    catch (int wyj){if (wyj==-1) cout<<"liczba spoza zakresy CTable"<<endl;}

    return 0;
    }


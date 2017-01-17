//
// Created by pivekk on 20.12.2016.
//

#ifndef LISTA1_OSOBA_H
#define LISTA1_OSOBA_H
#include <iostream>
using namespace std;
class Osoba {
    string imie;
    int *wiek;
public:
    Osoba(){imie="";
        wiek=new int ();
    };
    Osoba (const int age,string name){
        imie=name;
     wiek= new int (age);
    };
    Osoba (const Osoba &otherOsoba)
    {
        this->imie=otherOsoba.imie;
        wiek= new int (otherOsoba.getVal());
    }
    ~Osoba(){
        delete wiek;
    };
    int getVal()const { int *wy=this->wiek;
        return *wy;}
    Osoba& operator = (const Osoba &other){
        *this->wiek=*other.wiek;
        this->imie= other.imie;
        return *this;
    };

    string toString (){ return imie+" "+std::to_string(this->getVal());};

};


#endif //LISTA1_OSOBA_H

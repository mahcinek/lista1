//
// Created by pivekk on 20.12.2016.
//

#ifndef LISTA1_OSOBA_H
#define LISTA1_OSOBA_H
#include <iostream>
using namespace std;
class Osoba {
    string imie;
    int wiek;
public:
    Osoba(){};
    Osoba (int age,string name):wiek(age),imie(name){};
    Osoba (Osoba &otherOsoba)
    {
        this->imie=otherOsoba.imie;
        this->wiek=otherOsoba.wiek;
    }
    ~Osoba(){};

    string toString (){ return imie+" "+std::to_string(wiek);};

};


#endif //LISTA1_OSOBA_H

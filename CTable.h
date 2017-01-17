//
// Created by qwerty on 2016-10-11.
//

#ifndef LISTA1_CTABLE_H
#define LISTA1_CTABLE_H

#include <iostream>
#include <string>

using namespace std;
template <class T>
class CTable {
private:
    string s_name;
    T *i_Table;
    int table_length;
    T DEFAULT_VALUE;
public:
    CTable(){
        table_length =5;
        this->s_name = "Tablica";
        i_Table = new T[5];
       //std::cout << "bezp:" <<s_name <<endl;
    };
    CTable(int size, string s_name)
    {
        this->table_length=size;
        this->s_name=s_name;
        i_Table = new T[size];
    }
    CTable (int size,string s_name,T defValue){
        this->table_length=size;
        this->s_name=s_name;
        i_Table = new T[size];
        this->DEFAULT_VALUE=defValue;
        for (int i=0;i<table_length;i++)
            i_Table[i]=defValue;
    };
    CTable(string s_name)
    {
        this->s_name = s_name;
        std::cout << "parametr:" << s_name <<endl;
    };
    CTable(const CTable &pcOther){
        s_name = pcOther.s_name+"_copy";
        table_length = pcOther.table_length;
        i_Table = new int[table_length];
        DEFAULT_VALUE=pcOther.DEFAULT_VALUE;

        int tmp_val = 0;
        for (int i = 0; i < table_length; i++)
        {
            tmp_val=pcOther.getValue(i);
            i_Table[i] = tmp_val;
        }
        //cout << "kopiuj: " << pcOther.s_name<<endl;
    };
    string getName(){
        return s_name;
    };
    void setName(string s_name){
        this->s_name = s_name;
    };
    //string getFullInfo();
    void setTableLength(int table_length) {
        delete[] i_Table;
        i_Table = new int[table_length];
        this->table_length = table_length;

    };
    bool setValue(T value, int place){
        if (place >= table_length||place<0) {
            string s ="Podany element jest spoza zakresu CTable index " + to_string(place) + " tablica ma miejsca od 0 do " +
                      to_string(table_length - 1);
            throw s;
        }else
        {
            i_Table[place] = value;
            return true;
        }

    };

    bool setValueptr(T* value, int place){
        if (place >= table_length||place<0) {
            string s ="Podany element jest spoza zakresu CTable index " + to_string(place) + " tablica ma miejsca od 0 do " +
                      to_string(table_length - 1);
            throw s;
        }else
        {
            i_Table[place] = *value;
            return true;
        }

    };
    T getValue(int place)const
    {
        if (place >= table_length||place<0) {
            string s ="Podany element jest spoza zakresu CTable index " + to_string(place) + " tablica ma miejsca od 0 do " +
                      to_string(table_length - 1);
            throw s;
        }
        else
        {
            return  i_Table[place];

        }
    };
    T getValuepoint(int place)const
    {
        if (place >= table_length||place<0) {
            string s ="Podany element jest spoza zakresu CTable index " + to_string(place) + " tablica ma miejsca od 0 do " +
                      to_string(table_length - 1);
            throw s;
        }
        else
        {
            return  *i_Table[place];

        }
    };
    int getTableLength(){
        return table_length;
    };
    bool clear (int iPos){
        for (int i=0;i<table_length;i++)
            i_Table[i]=DEFAULT_VALUE;
    };
    bool del();
    bool setSize(int iSize){
        int* pomTable=new int [iSize];
        for (int i=0;i<iSize||i<table_length;i++)
        {
            pomTable[i]=i_Table[i];
        }
        if (iSize>table_length)
        {
            for (int i=table_length;i<iSize;i++)
                pomTable[i]= DEFAULT_VALUE;
        }
        int * pomTablePointer=i_Table;
        i_Table=pomTable;
        delete[](pomTablePointer);
    };
    ~CTable(){
       // cout << "usuwam:" << s_name;
        delete[] i_Table;
    };
};

#endif //LISTA1_CTABLE_H

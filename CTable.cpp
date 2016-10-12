//
// Created by qwerty on 2016-10-11.
//

#include <iostream>
#include "CTable.h"
#include <string>
#include <sstream>

using namespace std;

template <typename T>
string ToString(T val)
{
    stringstream stream;
    stream << val;
    return stream.str();
}
CTable::CTable()
{
    table_length =5;
    this->s_name = "Tablica";
    i_Table = new int[5];
    for (int i=0;i<table_length;i++)
        i_Table[i]=-1;
    std::cout << "bezp:" <<s_name <<endl;
}

CTable::CTable(string s_name)
{
    this->s_name = s_name;
    std::cout << "parametr:" << s_name <<endl;
}

CTable::CTable(const CTable & pcOther)
{
    s_name = pcOther.s_name+"_copy";
    table_length = pcOther.table_length;
    i_Table = new int[table_length];

    int tmp_val = 0;

    for (int i = 0; i < table_length; i++)
    {
        pcOther.getValue(&tmp_val, i);
        i_Table[i] = tmp_val;
    }
    cout << "kopiuj: " << pcOther.s_name<<endl;
}
bool CTable:: clear (int iPos)
{
    for (int i=0;i<table_length;i++)
        i_Table[i]=DEFAULT_VALUE;
}

bool CTable::del()
{
    this->~CTable();
}

string CTable::getName()
{
    return s_name;
}

void CTable::setName(string s_name)
{
    this->s_name = s_name;
}


void CTable::setTableLength(int table_length)
{
    delete[] i_Table;
    i_Table = new int[table_length];
    this->table_length = table_length;

}

bool CTable::setValue(int value, int place)
{
    if (place >= table_length)
        return false;
    else
    {
        i_Table[place] = value;
        return true;
    }

}
bool CTable::setSize (int iSize)
{
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
}

bool CTable::getValue(int * ptr_value, int place)const
{
    if (place >= table_length)
        return false;
    else
    {
        *ptr_value = *(i_Table + place);
        return true;
    }
}

int CTable::getTableLength()
{
    return table_length;
}

CTable::~CTable()
{
    cout << "usuwam:" << s_name;
    delete[] i_Table;
}



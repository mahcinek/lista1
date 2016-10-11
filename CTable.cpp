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
    table_length = 10;
    this->s_name = "Tablica";
    i_Table = new int[10];
    std::cout << "bezp:" <<s_name <<endl;
}

CTable::CTable(string s_name)
{
    this->s_name = s_name;
    std::cout << "parametr:" << s_name;
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
    cout << "kopiuj: " << pcOther.s_name;
}

string CTable::getName()
{
    return s_name;
}

void CTable::setName(string s_name)
{
    this->s_name = s_name;
}

//string CTable::getFullInfo()
//{
//    std::string values="";
//    using namespace std;
//    for (int i = 0; i < table_length; i++) //zamienianie wartosci w tabliczy na stringa
//    {
//        if (i > 0)values += ",";
//        values += ToString(i_Table[i]);
//    }
//    int a = 20;
//    std::string s = ToString(a);
//
//    string Info = s_name + " " + "Dlugosc "+ToString(table_length)+" Values: "+values;
//    return Info;
//}

void CTable::setTableLength(int table_length) //ustalanie tylko wielkości tablicy? bez przepisywania argumentów!!
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



//
// Created by qwerty on 2016-10-11.
//

#ifndef LISTA1_CTABLE_H
#define LISTA1_CTABLE_H

#include <iostream>

using namespace std;

class CTable {
private:
    string s_name;
    int* i_Table;
    int table_length;
    int DEFAULT_VALUE = -1;
public:
    CTable();
    CTable(string s_name);
    CTable(const CTable &pcOther);
    string getName();
    void setName(string s_name);
    //string getFullInfo();
    void setTableLength(int table_length);
    bool setValue(int value, int place);
    bool getValue(int *ptr_value, int place)const;
    int getTableLength();
    bool clear (int iPos);
    bool del();
    bool setSize(int iSize);
    ~CTable();
};


#endif //LISTA1_CTABLE_H

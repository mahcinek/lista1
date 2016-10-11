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
public:
    CTable();
    CTable(string s_name);
    CTable(const CTable &pcOther);
    string getName();
    void setName(string s_name);
    string getFullInfo();
    void setTableLength(int table_length);
    bool setValue(int value, int place);
    bool getValue(int *ptr_value, int place)const;
    int getTableLength();


    ~CTable();
};


#endif //LISTA1_CTABLE_H

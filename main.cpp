#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <iterator>
#include "CTable.h"


int main() {
    using namespace std;
    vector<string> vstrings;

    int iVectorSize;
    cout<<"podaj ilosc CTabel"<<endl;
    cin>>iVectorSize;
    vector<CTable *> vCtable (iVectorSize, nullptr);
    //int a=1;
    //for (int i=0;i<iVectorSize;i++)
     //vCtable.push_back(nullptr);
   // string sCommnad=vstrings[0];


    //if (vstrings.size()==3)
    //{
      // iVal2=atoi(vstrings[2].c_str());
    //}
    bool menu = true;
    while (menu) {
        string command;
        cout << "Podaj komende:" << endl;
        std::cin.sync();
        std::getline( std::cin, command );
        int iVal1 = -1;
        int iVal2 = -1;
//        istringstream iss(command);
//        string s;
        stringstream ss(command);
        istream_iterator<string> begin(ss);
        istream_iterator<string> end;
        vector<string> vstrings(begin, end);
        copy(vstrings.begin(), vstrings.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
        string sCommnad = vstrings[0];


        if (sCommnad == "createDef") {
            if (vstrings.size()>=1)
            { iVal1 = atoi(vstrings[1].c_str()); }
            if (iVal1 >= 0) {
                if (iVal1 < iVectorSize)
                    vCtable[iVal1]= new CTable ();
                    else cout<<"Nieprawidlowe miejsce"<<endl;}
            vstrings.clear();
            continue;
            }
            else if (sCommnad == "create") {
            if (vstrings.size()>=3)
            { iVal1 = atoi(vstrings[1].c_str()); }
            if (iVal1 >= 0) {
                if (iVal1 < iVectorSize){
                    vCtable[iVal1]= new CTable (vstrings[3]);
                    vCtable[iVal1]->setTableLength(atoi(vstrings[2].c_str()));}
                else cout<<"Nieprawidlowe miejsce"<<endl;}
            vstrings.clear();
            continue;
            }
            else if (sCommnad == "createCopy") {
            if (vstrings.size()>=1)
            { iVal1 = atoi(vstrings[1].c_str()); }
            iVal2 = atoi(vstrings[2].c_str());
            if (vCtable[iVal2]== nullptr)
            {
                cout<<"Nie ma takiego obiektu"<<endl;
                continue;
            }
            if (iVal1 >= 0) {
                if (iVal1 < iVectorSize){
                    vCtable[iVal1]= new CTable ( *vCtable[iVal2]);}
                else cout<<"Nieprawidlowe miejsce"<<endl;}
            vstrings.clear();
            continue;
        }
            else if (sCommnad == "setValue") {
            if (vstrings.size()>=2)
            { iVal1 = atoi(vstrings[1].c_str()); }
            if (vCtable[iVal1]== nullptr)
            {
                cout<<"Nie ma takiego obiektu"<<endl;
                continue;
            }
            if (iVal1 >= 0) {
                if (iVal1 < iVectorSize){
                    iVal2 = atoi(vstrings[2].c_str());
                    vCtable[iVal1]->setValue(atoi(vstrings[3].c_str()),iVal2);
                }
                else cout<<"Nieprawidlowe miejsce"<<endl;}
            vstrings.clear();
            continue;
        }
            else if (sCommnad == "getValue") {if (vstrings.size()>=2)
            { iVal1 = atoi(vstrings[1].c_str()); }
            if (vCtable[iVal1]== nullptr)
            {
                cout<<"Nie ma takiego obiektu"<<endl;
                continue;
            }
            if (iVal1 >= 0) {
                if (iVal1 < iVectorSize){
                    iVal2 = atoi(vstrings[2].c_str());
                    int iOdp;
                    vCtable[iVal1]->getValue(&iOdp,iVal2);
                    cout<<"Wynik: "<<iOdp<<endl;
                }
                else cout<<"Nieprawidlowe miejsce"<<endl;}
            vstrings.clear();
            continue;}
            else if (sCommnad == "setName") {if (vstrings.size()>=2)
            { iVal1 = atoi(vstrings[1].c_str()); }
            if (vCtable[iVal1]== nullptr)
            {
                cout<<"Nie ma takiego obiektu"<<endl;
                continue;
            }
            if (iVal1 >= 0) {
                if (iVal1 < iVectorSize){
                    vCtable[iVal1]->setName(vstrings[2]);
                }
                else cout<<"Nieprawidlowe miejsce"<<endl;}
            vstrings.clear();
            continue;}
            else if (sCommnad == "getName") {

            if (vstrings.size() >= 1)
                    iVal1 = atoi(vstrings[1].c_str());
            if(vCtable[iVal1]== nullptr) {cout<<"Nullowy obiekt"<<endl;
                continue;}
                cout <<"Nazwa to:" <<vCtable[iVal1]->getName()<<endl;
            }
        else if (sCommnad == "delete") {
            if (vstrings.size() >= 1)
                iVal1 = atoi(vstrings[1].c_str());
            if (vCtable[iVal1]== nullptr)
            {
                cout<<"Nie ma takiego obiektu"<<endl;
                continue;
            }
            cout << vCtable[iVal1]->del()<<endl;
            vCtable[iVal1]= nullptr;
            continue;
        }
        else if (sCommnad == "clear") {
            if (vstrings.size() >= 1)
                iVal1 = atoi(vstrings[1].c_str());
            if (vCtable[iVal1]== nullptr)
            {
                cout<<"Nie ma takiego obiektu"<<endl;
                continue;
            }
            cout << vCtable[iVal1]->clear(iVal1);
            continue;
        }
        else if (sCommnad == "setSize") {
            if (vstrings.size() >= 1)
                iVal1 = atoi(vstrings[1].c_str());
            if (vCtable[iVal1]== nullptr)
            {
                cout<<"Nie ma takiego obiektu"<<endl;
                continue;
            }
            iVal2=atoi(vstrings[2].c_str());
            cout << vCtable[iVal1]->setSize(iVal2)<<endl;
            continue;
        }
        else if (sCommnad == "exit") { menu = false; }
            else { cout << "Bledna komenda"<<endl; }
        vstrings.clear();
       }

    return 0;
    }


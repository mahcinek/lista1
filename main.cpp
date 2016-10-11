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
        std::stringstream ss(command);
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end;
        std::vector<std::string> vstrings(begin, end);
        std::copy(vstrings.begin(), vstrings.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
        string sCommnad = vstrings[0];


        if (sCommnad == "createDef") {
            if (vstrings.size()>=1)
            { iVal1 = atoi(vstrings[1].c_str()); }
            if (iVal1 > 0) {
                if (iVal1 < iVectorSize)
                    vCtable[iVal1]= new CTable ();
                    else cout<<"Nieprawidlowe miejsce"<<endl;}
            vstrings.clear();
            continue;
            }
            else if (sCommnad == "create") {
            if (vstrings.size()>=3)
            { iVal1 = atoi(vstrings[1].c_str()); }
            if (iVal1 > 0) {
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
            if (iVal1 > 0) {
                if (iVal1 < iVectorSize){
                    iVal2 = atoi(vstrings[2].c_str());
                    vCtable[iVal1]= new CTable ( *vCtable[iVal2]);}
                else cout<<"Nieprawidlowe miejsce"<<endl;}
            vstrings.clear();
            continue;
        }
            else if (sCommnad == "setValue") {
            if (vstrings.size()>=2)
            { iVal1 = atoi(vstrings[1].c_str()); }
            if (iVal1 > 0) {
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
            if (iVal1 > 0) {
                if (iVal1 < iVectorSize){
                    iVal2 = atoi(vstrings[2].c_str());
                    int iOdp;
                    vCtable[iVal1]->getValue(&iOdp,iVal2);
                    cout<<iOdp<<endl;
                }
                else cout<<"Nieprawidlowe miejsce"<<endl;}
            vstrings.clear();
            continue;}
            else if (sCommnad == "setName") {if (vstrings.size()>=2)
            { iVal1 = atoi(vstrings[1].c_str()); }
            if (iVal1 > 0) {
                if (iVal1 < iVectorSize){
                    vCtable[iVal1]->setName(vstrings[2]);
                }
                else cout<<"Nieprawidlowe miejsce"<<endl;}
            vstrings.clear();
            continue;}
            else if (sCommnad == "getName") {
                if (vstrings.size() >= 1)
                    iVal1 = atoi(vstrings[1].c_str());
                cout << vCtable[iVal1]->getName();
            } else if (sCommnad == "exit") { menu = false; }
            else { cout << "Bledna komenda"; }
        vstrings.clear();
       }

    return 0;
    }


//
// Created by youssef on 11/30/2024.
//

#ifndef PROJECT_SECONDARYINDEX_DOCTOR_H
#define PROJECT_SECONDARYINDEX_DOCTOR_H
#include <bits/stdc++.h>
using namespace std;

class SecondaryIndex_Doctor {
    map<string, list<string>> index;
public:
    void add(const string& Name, string id) ;
    void Write_Index_To_File() ;
    void Load_Index_From_File() ;
    list<string> get(const  string& Name) ;
    void display() ;
};


#endif //PROJECT_SECONDARYINDEX_DOCTOR_H

//
// Created by youssef on 11/30/2024.
//

#ifndef PROJECT_PRIMARYINDEX_DOCTOR_H
#define PROJECT_PRIMARYINDEX_DOCTOR_H
#include <bits/stdc++.h>
using namespace std;

class PrimaryIndex_Doctor {
    map<string, int> index;

public:
    void add(const string& key, int RNN) ;

    int get(const string& key) ;

    void Write_Index_To_File() ;

    void Load_Index_From_File() ;

    void display() ;
};


#endif //PROJECT_PRIMARYINDEX_DOCTOR_H

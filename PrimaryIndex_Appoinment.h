//
// Created by youssef on 11/30/2024.
//

#ifndef PROJECT_PRIMARYINDEX_APPOINMENT_H
#define PROJECT_PRIMARYINDEX_APPOINMENT_H
#include <bits/stdc++.h>
#include "Index.h"

using namespace std;

class PrimaryIndex_Appointment : public Index {
    map<string, int> index;
public:
    void add(const string& key, int RNN) override;

    int get(const string& key) override;

    void Write_Index_To_File() override;

    void Load_Index_From_File() override;

    void display() override;
};


#endif //PROJECT_PRIMARYINDEX_APPOINMENT_H

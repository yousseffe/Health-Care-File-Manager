//
// Created by youssef on 12/3/2024.
//

#ifndef HEALTH_CARE_FILE_MANAGER_INDEX_H
#define HEALTH_CARE_FILE_MANAGER_INDEX_H
#include <bits/stdc++.h>
using namespace std;
class Index {
public:
    virtual void add(const string& key, int RNN) = 0;
    virtual int get(const string& key) = 0;
    virtual void Write_Index_To_File() = 0;
    virtual void Load_Index_From_File() = 0;
    virtual void display() = 0;
};
#endif //HEALTH_CARE_FILE_MANAGER_INDEX_H

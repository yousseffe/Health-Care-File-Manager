

#ifndef FILE_DOCTORPRIMARYINDEX_H
#define FILE_DOCTORPRIMARYINDEX_H
#include "bits/stdc++.h"
#include "PrimaryIndex.h"

using namespace std;
class DoctorPrimaryIndex : public PrimaryIndex{
public:
    string id;


    DoctorPrimaryIndex(int id, int index){
        this->id = id;
        this->index = index;
    }
    DoctorPrimaryIndex(string record) {
        stringstream ss(record);
        string length;
        getline(ss,length,'|');
        getline(ss , this->id , '|');
        string indexStr;
        getline(ss , indexStr , '|');
        this->index = stoi(indexStr);
    }
    string toString() override {
        string record = this->id + "|" + to_string(this->index);
        return to_string(record.length()+1) + "|" + record;
    }
};
#endif //FILE_DOCTORPRIMARYINDEX_H

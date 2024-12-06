

#ifndef FILE_APPOINTMENTPRIMARYINDEX_H
#define FILE_APPOINTMENTPRIMARYINDEX_H
#include "bits/stdc++.h"
using namespace std;

class AppointmentPrimaryIndex : public PrimaryIndex
{
public:
    string id;
    AppointmentPrimaryIndex(string id, int index) : id(id) { this->index = index; }

    AppointmentPrimaryIndex(string record)
    {
        stringstream ss(record);
        string length;
        getline(ss, length, '|');
        getline(ss, this->id, '|');
        string indexStr;
        getline(ss, indexStr, '|');
        this->index = stoi(indexStr);
    }

    string toString() override
    {
        string record = this->id + "|" + to_string(this->index);
        return to_string(record.length() + 1) + "|" + record;
    }
};
#endif // FILE_APPOINTMENTPRIMARYINDEX_H

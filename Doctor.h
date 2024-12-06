//
// Created by youssef on 12/5/2024.
//
#ifndef FILE_DOCTOR_H
#define FILE_DOCTOR_H
#include "Entity.h"

class Doctor : public Entity
{
public:
    string Name;
    string Address;

    Doctor(string id, string name, string address) : Name(name), Address(address)
    {
        this->ID = id;
    }
    Doctor(string record)
    {
        stringstream ss(record);
        string length;
        getline(ss, length, '|');
        getline(ss, this->ID, '|');
        getline(ss, this->Name, '|');
        getline(ss, this->Address, '|');
    }

    string toString() override
    {
        string record = this->ID + "|" + this->Name + "|" + this->Address;
        return to_string(record.length() + 1) + "|" + record;
    }
    void display() override
    {
        cout << setw(15) << ID << setw(30) << Name << setw(30) << Address << endl;
    }
};
#endif // FILE_DOCTOR_H

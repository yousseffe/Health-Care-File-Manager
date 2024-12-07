//
// Created by youssef on 12/5/2024.
//
#ifndef FILE_APPOINTMENT_H
#define FILE_APPOINTMENT_H
#include "../General/entity.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
class Appointment : public Entity
{
public:
    string DoctorID, date;
    Appointment(string id, string doctorID, string data) : DoctorID(doctorID), date(data) { this->ID = id; }
    Appointment(string record)
    {
        stringstream ss(record);
        string length;
        getline(ss, length, '|');
        getline(ss, this->ID, '|');
        getline(ss, this->DoctorID, '|');
        getline(ss, this->date, '|');
    }

    string toString() override
    {
        string record = this->ID + "|" + this->DoctorID + "|" + this->date;
        return to_string(record.length() + 1) + "|" + record;
    }
    void display() override
    {
        cout << setw(15) << ID << setw(30) << date << setw(15) << DoctorID << endl;
    }
};
#endif // FILE_APPOINTMENT_H
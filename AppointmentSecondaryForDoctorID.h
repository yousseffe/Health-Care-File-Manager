#ifndef FILE_APPOINTMENTSECONDARYFORDOCTORID_H
#define FILE_APPOINTMENTSECONDARYFORDOCTORID_H
#include "bits/stdc++.h"
using namespace std;
class AppointmentSecondaryForDoctorID
{
public:
    string DoctorID;
    list<string> AppointmentsID;
    AppointmentSecondaryForDoctorID(string doctorID, list<string> appointmentsID) : DoctorID(doctorID), AppointmentsID(appointmentsID) {}
    AppointmentSecondaryForDoctorID(string record)
    {
        stringstream ss(record);
        string length;
        getline(ss, length, '|');
        getline(ss, this->DoctorID, '|');
        string id;
        while (getline(ss, id, '|'))
        {
            AppointmentsID.push_back(id);
        }
    }
    string toString()
    {
        string record = DoctorID;
        for (string id : AppointmentsID)
        {
            record += "|" + id;
        }
        return to_string(record.length() + 1) + "|" + record;
    }
};
#endif // FILE_APPOINTMENTSECONDARYFORDOCTORID_H

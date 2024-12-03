//
// Created by youssef on 11/26/2024.
//

#ifndef PROJECT_APPOINTMENT_H
#define PROJECT_APPOINTMENT_H

#include <bits/stdc++.h>
#include "Record.h"

using namespace std;
class Appointment : public Record {
public:
    // size + el null
    char appointmentID[16]{};
    char appointmentDate[31]{};
    char doctorID[16]{};

    Appointment(const string& id = "", const string& date = "", const string& docID = "");
    Appointment(string& id, string& date, string& docID);
    void setAppointmentID(const string& id);
    void setAppointmentDate(const string& date);
    void setDoctorID(const string& docID);

    string toDelimitedString() const override;
    void fromDelimitedString(const string& str) override;
};


#endif //PROJECT_APPOINTMENT_H

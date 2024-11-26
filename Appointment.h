//
// Created by youssef on 11/26/2024.
//

#ifndef PROJECT_APPOINTMENT_H
#define PROJECT_APPOINTMENT_H

#include <bits/stdc++.h>
using namespace std;
class Appointment {
public:
    // size + el null
    char appointmentID[16]{};
    char appointmentDate[31]{};
    char doctorID[16]{};

    Appointment(const string& id = "", const std::string& date = "", const std::string& docID = "");
    Appointment(string& id, string& date, string& docID);
    void setAppointmentID(const std::string& id);
    void setAppointmentDate(const std::string& date);
    void setDoctorID(const std::string& docID);

    std::string toDelimitedString() const;
};


#endif //PROJECT_APPOINTMENT_H

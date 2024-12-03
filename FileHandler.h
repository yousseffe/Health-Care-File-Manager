//
// Created by youssef on 11/26/2024.
//

#ifndef PROJECT_FILEHANDLER_H
#define PROJECT_FILEHANDLER_H
#include <bits/stdc++.h>
using namespace std;
#include "Doctor.h"
#include "Appointment.h"

void addDoctor(const Doctor& doctor);
void updateDoctor(const string& doctorID, const string& newName, const string& newAddress);
void deleteDoctor(const string& doctorID);
void readDoctorsFromFile(const string& filename);

void addAppointment(const Appointment& appointment);
void updateAppointment(const string& appointmentID, const string& newDate);
void deleteAppointment(const string& appointmentID);
void readAppointmentsFromFile(const string& filename);


#endif //PROJECT_FILEHANDLER_H

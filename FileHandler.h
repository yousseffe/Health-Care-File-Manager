//
// Created by youssef on 11/26/2024.
//

#ifndef PROJECT_FILEHANDLER_H
#define PROJECT_FILEHANDLER_H
#include <bits/stdc++.h>
using namespace std;
#include "Doctor.h"
#include "Appointment.h"

void writeDoctorToFile(const Doctor& doctor, const string& filename);
void readDoctorsFromFile(const string& filename);

void writeAppointmentToFile(const Appointment& appointment, const string& filename);
void readAppointmentsFromFile(const string& filename);


#endif //PROJECT_FILEHANDLER_H

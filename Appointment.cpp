#include "Appointment.h"

Appointment::Appointment(const string& id, const string& date, const string& docID) {
    setAppointmentID(id);
    setAppointmentDate(date);
    setDoctorID(docID);
}

void Appointment::setAppointmentID(const string& id) {
    strncpy(appointmentID, id.c_str(), 15);
    appointmentID[15] = '\0';
}

void Appointment::setAppointmentDate(const string& date) {
    strncpy(appointmentDate, date.c_str(), 30);
    appointmentDate[30] = '\0';
}

void Appointment::setDoctorID(const string& docID) {
    strncpy(doctorID, docID.c_str(), 15);
    doctorID[15] = '\0';
}
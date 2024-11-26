#include "Doctor.h"
#include "Appointment.h"
#include "FileHandler.h"

int main() {
    Doctor doc1("DOC001", "Dr. John Smith", "123 Main St.");
    Doctor doc2("DOC002", "Dr. Alice Johnson", "456 Oak Ave.");

    writeDoctorToFile(doc1, "doctors.txt");
    writeDoctorToFile(doc2, "doctors.txt");

    cout << "Doctors:\n";
    readDoctorsFromFile("doctors.txt");

    Appointment appt1("APT001", "2024-11-30", "DOC001");
    Appointment appt2("APT002", "2024-12-01", "DOC002");

    writeAppointmentToFile(appt1, "appointments.txt");
    writeAppointmentToFile(appt2, "appointments.txt");

    cout << "\nAppointments:\n";
    readAppointmentsFromFile("appointments.txt");

    return 0;
}
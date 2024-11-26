#include "FileHandler.h"

void writeDoctorToFile(const Doctor& doctor, const string& filename) {
    ofstream file(filename, ios::app | ios::binary);
    if (file.is_open()) {
        file.write(doctor.doctorID, 15);
        file.write("|", 1);
        file.write(doctor.doctorName, 30);
        file.write("|", 1);
        file.write(doctor.address, 30);
        file.write("\n", 1);
        file.close();
    } else {
        cerr << "Unable to open file for writing." << endl;
    }
}

// Read all doctor records from a file
void readDoctorsFromFile(const string& filename) {
    ifstream file(filename, ios::in | ios::binary);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cerr << "Unable to open file for reading." << endl;
    }
}

// Write an appointment record to a file
void writeAppointmentToFile(const Appointment& appointment, const string& filename) {
    ofstream file(filename, ios::app | ios::binary);
    if (file.is_open()) {
        file.write(appointment.appointmentID, 15);
        file.write("|", 1);
        file.write(appointment.appointmentDate, 30);
        file.write("|", 1);
        file.write(appointment.doctorID, 15);
        file.write("\n", 1);
        file.close();
    } else {
        cerr << "Unable to open file for writing." << endl;
    }
}

// Read all appointment records from a file
void readAppointmentsFromFile(const string& filename) {
    ifstream file(filename, ios::in | ios::binary);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cerr << "Unable to open file for reading." << endl;
    }
}
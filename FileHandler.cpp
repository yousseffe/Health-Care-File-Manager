#include "FileHandler.h"
#include "PrimaryIndex_Appoinment.h"
#include "PrimaryIndex_Doctor.h"
#include "SecondaryIndex_Doctor.h"

void writeDoctorToFile(const Doctor& doctor, const string& filename) {
    fstream file(filename, ios::app | ios::binary);
    PrimaryIndex_Doctor indexDoctor;
    SecondaryIndex_Doctor secondaryIndexDoctor;
    secondaryIndexDoctor.Load_Index_From_File();
    indexDoctor.Load_Index_From_File();

    if (file.is_open()) {
        file.write(doctor.doctorID, 15);
        file.write("|", 1);
        file.write(doctor.doctorName, 30);
        file.write("|", 1);
        file.write(doctor.address, 30);
        file.write("\n", 1);
        file.seekg(0, ios::end);
        int RRN =  file.tellg()/78 ;
        indexDoctor.add(doctor.doctorID , RRN);
        secondaryIndexDoctor.add(doctor.doctorName , doctor.doctorID);
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
    fstream file(filename, ios::app | ios::binary);
    PrimaryIndex_Appointment primaryIndexAppointment;
    primaryIndexAppointment.Load_Index_From_File();
    if (file.is_open()) {
        file.write(appointment.appointmentID, 15);
        file.write("|", 1);
        file.write(appointment.appointmentDate, 30);
        file.write("|", 1);
        file.write(appointment.doctorID, 15);
        file.write("\n", 1);
        file.seekg(0 , ios::end);
        primaryIndexAppointment.add(appointment.appointmentID , file.tellg()/63 );
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
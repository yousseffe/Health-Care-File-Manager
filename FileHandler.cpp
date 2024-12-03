#include "FileHandler.h"
#include "PrimaryIndex_Appoinment.h"
#include "PrimaryIndex_Doctor.h"
#include "SecondaryIndex_Doctor.h"
vector<int> availListDoctors;
vector<int> availListAppointments;
int getFileRecordCount(const string& filename, int recordSize) {
    ifstream file(filename, ios::binary | ios::ate);
    return file.tellg() / recordSize;
}

void addDoctor(const Doctor& doctor) {
    PrimaryIndex_Doctor indexDoctor;
    indexDoctor.Load_Index_From_File();

    if (indexDoctor.get(doctor.doctorID) != -1) {
        cout << "Doctor with ID " << doctor.doctorID << " already exists.\n";
        return;
    }

    fstream file("Doctors.txt", ios::in | ios::out | ios::app);
    int RNN = -1;
    if (!availListDoctors.empty()) {
        RNN = availListDoctors.back();
        availListDoctors.pop_back();
        file.seekp(RNN * 78, ios::beg);
    } else {
        file.seekp(0, ios::end);
        RNN = getFileRecordCount("Doctors.txt", 78);
    }

    file.write(doctor.toDelimitedString().c_str(), 78);
    file.close();

    indexDoctor.add(doctor.doctorID, RNN);
    indexDoctor.Write_Index_To_File();
}

// Update an existing doctor record
void updateDoctor(const string& doctorID, const string& newName, const string& newAddress) {
    PrimaryIndex_Doctor indexDoctor;
    indexDoctor.Load_Index_From_File();

    int RNN = indexDoctor.get(doctorID);
    if (RNN == -1) {
        cout << "Doctor with ID " << doctorID << " not found.\n";
        return;
    }

    fstream file("Doctors.txt", ios::in | ios::out);
    file.seekp(RNN * 78, ios::beg);

    Doctor doctor;
    doctor.setDoctorID(doctorID);
    doctor.setDoctorName(newName);
    doctor.setAddress(newAddress);

    file.write(doctor.toDelimitedString().c_str(), 78);
    file.close();
}

void deleteDoctor(const string& doctorID) {
    PrimaryIndex_Doctor indexDoctor;
    indexDoctor.Load_Index_From_File();

    int RNN = indexDoctor.get(doctorID);
    if (RNN == -1) {
        cout << "Doctor with ID " << doctorID << " not found.\n";
        return;
    }

    fstream file("Doctors.txt", ios::in | ios::out);
    file.seekp(RNN * 78, ios::beg);
    file.put('*');
    file.close();

    availListDoctors.push_back(RNN);
    indexDoctor.add(doctorID, -1);
    indexDoctor.Write_Index_To_File();
}
void addAppointment(const Appointment& appointment) {
    PrimaryIndex_Appointment indexAppointment;
    indexAppointment.Load_Index_From_File();

    if (indexAppointment.get(appointment.appointmentID) != -1) {
        cout << "Appointment with ID " << appointment.appointmentID << " already exists.\n";
        return;
    }

    fstream file("Appointments.txt", ios::in | ios::out | ios::app);
    int RNN = -1;
    if (!availListAppointments.empty()) {
        RNN = availListAppointments.back();
        availListAppointments.pop_back();
        file.seekp(RNN * 63, ios::beg);
    } else {
        file.seekp(0, ios::end);
        RNN = getFileRecordCount("Appointments.txt", 63);
    }

    file.write(appointment.toDelimitedString().c_str(), 63);
    file.close();

    indexAppointment.add(appointment.appointmentID, RNN);
    indexAppointment.Write_Index_To_File();
}

void updateAppointment(const string& appointmentID, const string& newDate) {
    PrimaryIndex_Appointment indexAppointment;
    indexAppointment.Load_Index_From_File();

    int RNN = indexAppointment.get(appointmentID);
    if (RNN == -1) {
        cout << "Appointment with ID " << appointmentID << " not found.\n";
        return;
    }

    fstream file("Appointments.txt", ios::in | ios::out);
    file.seekp(RNN * 63, ios::beg);

    Appointment appointment;
    appointment.setAppointmentID(appointmentID);
    appointment.setAppointmentDate(newDate);

    file.write(appointment.toDelimitedString().c_str(), 63);
    file.close();
}

void deleteAppointment(const string& appointmentID) {
    PrimaryIndex_Appointment indexAppointment;
    indexAppointment.Load_Index_From_File();

    int RNN = indexAppointment.get(appointmentID);
    if (RNN == -1) {
        cout << "Appointment with ID " << appointmentID << " not found.\n";
        return;
    }

    fstream file("Appointments.txt", ios::in | ios::out);
    file.seekp(RNN * 63, ios::beg);
    file.put('*');  // Mark record as deleted
    file.close();

    availListAppointments.push_back(RNN);
    indexAppointment.add(appointmentID, -1);
    indexAppointment.Write_Index_To_File();
}
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
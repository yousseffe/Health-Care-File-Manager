
#ifndef FILE_FILEMANAGER_H
#define FILE_FILEMANAGER_H

#include "Doctor.h"
#include "Appointment.h"
#include "DoctorPrimaryIndex.h"
#include "AppointmentPrimaryIndex.h"

class FileManager
{
public:
    static vector<int> availableListDoctor;
    static vector<int> availableListAppointment;
    static vector<Doctor> doctors;
    static vector<Appointment> appointments;
    static map<int, int> doctorPrimaryIndex;
    static map<int, int> appointmentsPrimaryIndex;
    static map<string, list<string>> doctorSecondaryIndexForName;
    static map<string, list<string>> appointmentsSecondaryIndexForDoctorID;

    static void initialize();

    // CRUD
    static void addDoctors(Doctor doctor);
    static void addAppointments(Appointment appointment);
    static void deleteDoctor(string id);
    static void deleteAppointment(string id);
    static void updateDoctor(string doctorID, string newName, string newSpecialization);
    static void updateAppointment(string appointmentID, string newDoctorID, string newDate);

    // load files
    static void loadDoctorsFromFile();
    static void loadAppointmentsFromFile();
    static void loadDoctorPrimaryIndex();
    static void loadAppointmentsPrimaryIndex();
    static void loadDoctorsNameSecondaryIndex();
    static void loadAppointmentDoctorIDSecondaryIndex();
    static void loadAvailableListDoctor();
    static void loadAvailableListAppointment();
    // create index
    static void createDoctorPrimaryIndex();
    static void createAppointmentsPrimaryIndex();
    // save files
    static void saveDoctorPrimaryIndexFile();
    static void saveAppointmentPrimaryIndexFile();
    static void saveDoctorsNameSecondaryIndexFile();
    static void saveAppointmentDoctorIDSecondaryIndexFile();
    static void saveAvailableListDoctor();
    static void saveAvailableListAppointment();

    // display
    static void displayAppointments();
    static void displayDoctors();
};

#endif // FILE_FILEMANAGER_H

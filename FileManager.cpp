
#include "FileManager.h"
#include "DoctorSecondaryIndexForName.h"
#include "AppointmentSecondaryForDoctorID.h"

vector<int> FileManager::availableListDoctor = {};
vector<int> FileManager::availableListAppointment = {};
vector<Appointment> FileManager::appointments = {};
vector<Doctor> FileManager::doctors = {};
map<int,int> FileManager::doctorPrimaryIndex;
map<int,int> FileManager::appointmentsPrimaryIndex;
map<string , list<string>> FileManager::doctorSecondaryIndexForName;
map<string , list<string>> FileManager::appointmentsSecondaryIndexForDoctorID;

void FileManager::addDoctors(Doctor doctor) {
    fstream file("doctors.txt", ios ::in | ios::out);
    if (!file.is_open()) throw runtime_error("Failed to open file");
    int normalizedID = stoi(doctor.ID);
    if (doctorPrimaryIndex.find(normalizedID) != doctorPrimaryIndex.end() ) throw runtime_error("Doctor already exists");
    if (!availableListDoctor.empty()){
        int location = availableListDoctor.back();
        availableListDoctor.pop_back();
        file.seekp(location , ios::beg);
        file << doctor.toString() << endl;
        createDoctorPrimaryIndex();

    } else {
        doctors.push_back(doctor);
        file.seekg(0, ios::end);
        int location = file.tellp();
        cout<< location<<endl;
        doctorPrimaryIndex[normalizedID] = location ;
        doctorSecondaryIndexForName[doctor.Name].push_back(doctor.ID);
        file << doctor.toString() << endl;
    }
    saveDoctorPrimaryIndexFile();
    saveDoctorsNameSecondaryIndexFile();
    file.close();
}
void FileManager::addAppointments(Appointment appointment) {
    fstream file("appointments.txt", ios::app | ios ::in);
    if (!file.is_open()) throw runtime_error("Failed to open file");
    int normalizedID = stoi(appointment.ID);
    if (appointmentsPrimaryIndex.find(normalizedID) != appointmentsPrimaryIndex.end()) throw runtime_error("Appointment already exists");
    if(!availableListAppointment.empty()){
        int location = availableListAppointment.back();
        availableListAppointment.pop_back();
        file.seekp(location , ios::beg);
        file << appointment.toString() << endl;
        createAppointmentsPrimaryIndex();
    } else{
        appointments.push_back(appointment);
        file.seekg(0, ios::end);
        int location = file.tellp();
        appointmentsPrimaryIndex[normalizedID] = location;
        appointmentsSecondaryIndexForDoctorID[appointment.DoctorID].push_back(appointment.ID);
        file << appointment.toString() << endl;
    }
    saveAppointmentPrimaryIndexFile();
    saveAppointmentDoctorIDSecondaryIndexFile();
    file.close();

}
void FileManager::deleteDoctor(string id) {
    int normalizedID = stoi(id);
    auto it = doctorPrimaryIndex.find(normalizedID);
    if (it == doctorPrimaryIndex.end()) {
        cout << "Warning: Doctor with ID " << id << " does not exist." << endl;
        return;
    }

    fstream file("doctors.txt", ios::in | ios::out);
    if (!file.is_open()) throw runtime_error("Failed to open file");

    file.seekp(it->second);
    file << "*";
    availableListDoctor.push_back(it->second);

    doctorPrimaryIndex.erase(it);
    for (auto& entry : doctorSecondaryIndexForName) {
        entry.second.remove(id);
    }

    saveDoctorPrimaryIndexFile();
    saveDoctorsNameSecondaryIndexFile();
    saveAvailableListDoctor();
    file.close();

}
void FileManager::deleteAppointment(string id) {
    int normalizedID = stoi(id);
    auto it = appointmentsPrimaryIndex.find(normalizedID);
    if (it == appointmentsPrimaryIndex.end()) {
        cout << "Warning: appointment with ID " << id << " does not exist." << endl;
        return;
    }

    fstream file("appointments.txt", ios::in | ios::out);
    if (!file.is_open()) throw runtime_error("Failed to open file");

    file.seekp(it->second);
    file << "*";
    availableListAppointment.push_back(it->second);

    appointmentsPrimaryIndex.erase(it);
    for (auto& entry : appointmentsSecondaryIndexForDoctorID) {
        entry.second.remove(id);
    }
    saveAppointmentPrimaryIndexFile();
    saveAppointmentDoctorIDSecondaryIndexFile();
    saveAvailableListAppointment();
    file.close();

}
void FileManager::updateDoctor( string doctorID,  string newName = "",  string address = "") {
    int normalizedID = stoi(doctorID);
    auto it = doctorPrimaryIndex.find(normalizedID);
    if (it == doctorPrimaryIndex.end()) {
        cout << "Warning: doctor with ID " << doctorID << " does not exist." << endl;
        return;
    }
    fstream file("doctors.txt", ios::in | ios::out | ios::binary);
    if (!file.is_open()) {
        throw runtime_error("Unable to open doctor file for updating.");
    }
    file.seekp(it->second , ios::beg);
    string line;
    getline(file,line , '\r');
    Doctor doctor(line);
    if (newName != ""){
        doctorSecondaryIndexForName[doctor.Name].remove(doctorID);
        doctor.Name = newName;
        doctorSecondaryIndexForName[doctor.Name].push_back(doctorID);
    }
    if (address != ""){
        doctor.Address = address;
    }
    file.seekp(it->second);
    file << doctor.toString();
    file.close();
    saveDoctorsNameSecondaryIndexFile();
    createDoctorPrimaryIndex();
    saveDoctorPrimaryIndexFile();
}
void FileManager::updateAppointment(string appointmentID, string newDoctorID= "", string newDate= "") {
    int normalizedID = stoi(appointmentID);
    auto it = appointmentsPrimaryIndex.find(normalizedID);
    if (it == appointmentsPrimaryIndex.end()) {
        cout << "Warning: appointment with ID " << appointmentID << " does not exist." << endl;
        return;
    }
    fstream file("appointments.txt", ios::in | ios::out | ios::binary);
    if (!file.is_open()) {
        throw runtime_error("Unable to open appointment file for updating.");
    }
    file.seekp(it->second , ios::beg);
    string line;
    getline(file,line , '\r');
    Appointment appointment(line);
    if (newDoctorID != ""){
        if (newDoctorID.size() != appointment.DoctorID.size()) throw runtime_error("doctor ID cannot be changed.");
        doctorSecondaryIndexForName[appointment.DoctorID].remove(appointmentID);
        appointment.DoctorID = newDoctorID;
        doctorSecondaryIndexForName[appointment.DoctorID].push_back(appointmentID);

    }
    if (newDate != ""){
        if (newDate.size() != appointment.date.size()) throw runtime_error("date cannot be changed.");
        appointment.date = newDate;
    }
    file.seekp(it->second);
    file << appointment.toString() ;
    file.close();
    saveAppointmentDoctorIDSecondaryIndexFile();
}
void FileManager::displayDoctors() {
    cout <<left << setw(15) << "ID" << setw(30) << "Name" << setw(30) << "Address" << endl;
    for ( auto &doctor: doctors) {
       doctor.display();
    }
}
void FileManager::displayAppointments() {
    cout << left << setw(15) << "ID" << setw(30) << "Doctor ID" << setw(30) << "Date" << endl;
    for ( auto &appointment: appointments) {
        appointment.display();
    }
}
void FileManager::loadDoctorsFromFile() {
    ifstream file("doctors.txt");
    if (!file.is_open()) throw runtime_error("Failed to open file");
    string line;
    getline(file , line , '\n');
    while (getline(file, line , '\n')) {
            Doctor doctor(line);
            doctors.push_back(doctor);
    }
    file.close();
}
void FileManager::loadAppointmentsFromFile() {
    ifstream file("appointments.txt");
    if (!file.is_open()) throw runtime_error("Failed to open file");
    string line;
    getline(file , line , '\n');
    while (getline(file, line , '\n')) {
        Appointment appointment(line);
        appointments.push_back(appointment);
    }
    file.close();
}
void FileManager::loadDoctorPrimaryIndex() {
    ifstream file("doctorsPrimaryIndex.txt");
    if (!file.is_open()) throw runtime_error("Failed to open file");
    string line;
    while (getline(file, line)) {
        DoctorPrimaryIndex doctorIndexRecord(line);
        int normalizedID = stoi(doctorIndexRecord.id);
        doctorPrimaryIndex[normalizedID] = doctorIndexRecord.index;
    }
    file.close();

}
void FileManager::loadAppointmentsPrimaryIndex() {
    ifstream file("appointmentsPrimaryIndex.txt");
    if (!file.is_open()) throw runtime_error("Failed to open file");
    string line;
    while (getline(file, line)) {
        AppointmentPrimaryIndex appointmentIndexRecord(line);
        int normalizedID = stoi(appointmentIndexRecord.id);
        appointmentsPrimaryIndex[normalizedID] = appointmentIndexRecord.index;
    }
    file.close();

}
void FileManager::loadDoctorsNameSecondaryIndex() {
    ifstream file("doctorsNameSecondaryIndex.txt");
    if (!file.is_open()) throw runtime_error("Failed to open file");
    string line;
    while (getline(file, line)) {
        DoctorSecondaryIndexForName doctorIndexRecord(line);
        for (auto &id : doctorIndexRecord.DoctorsID) {
            doctorSecondaryIndexForName[doctorIndexRecord.Name].push_back(id);
        }
    }
    file.close();
}
void FileManager::loadAppointmentDoctorIDSecondaryIndex() {
    ifstream file("appointmentsDocotorIDSecondaryIndex.txt");
    if (!file.is_open()) throw runtime_error("Failed to open file");
    string line;
    while (getline(file, line)) {
        AppointmentSecondaryForDoctorID appointmentIndexRecord(line);
        for (auto &id : appointmentIndexRecord.AppointmentsID) {
            appointmentsSecondaryIndexForDoctorID[appointmentIndexRecord.DoctorID].push_back(id);
        }
    }
}
void FileManager::loadAvailableListDoctor() {
    availableListDoctor = {};
    ifstream file("doctorsAvailableList.txt");
    if (!file.is_open()) throw runtime_error("Failed to open file");
    string line;
    getline(file , line , '\n');
    if (line[0] != ' '){
        for (int i = 0; i < line.length(); ++i) {
            if (line[i] != '|') {
                availableListDoctor.push_back((line[i] - '0'));
            }
        }
    }
    file.close();
}
void FileManager::loadAvailableListAppointment() {
    availableListAppointment = {};
    ifstream file("AppointmentAvailableList.txt");
    if (!file.is_open()) throw runtime_error("Failed to open file");
    string line;
    getline(file , line , '\n');
    if (line[0] != ' '){
        for (int i = 0; i < line.length(); ++i) {
            if (line[i] != '|') {
                availableListAppointment.push_back((line[i] - '0'));
            }
        }
    }
    file.close();
}
void FileManager::createDoctorPrimaryIndex() {
    doctorPrimaryIndex = {};
    fstream file("doctors.txt", ios::in | ios::out);
    if (!file.is_open()) throw runtime_error("Failed to open file");
    string line;
    int location = 0;
    while (getline(file, line , '\n')) {
        Doctor doctor(line);
        int normalizedID = stoi(doctor.ID);
        doctorPrimaryIndex[normalizedID] = location;
        location += line.length() + 2;
    }
    file.close();
}
void FileManager::createAppointmentsPrimaryIndex() {
    fstream file("appointments.txt", ios::in | ios::out);
    if (!file.is_open()) throw runtime_error("Failed to open file");
    string line;
    int i = 1;
    int location = 0;
    while (getline(file, line , '\n')) {
        Appointment appointment(line);
        int normalizedID = stoi(appointment.ID);
        appointmentsPrimaryIndex[normalizedID] = location;
        location +=line.length()+2 ;
    }
    file.close();
}
void FileManager::saveDoctorsNameSecondaryIndexFile() {
    ofstream file("doctorsNameSecondaryIndex.txt");
    if (!file.is_open()) throw runtime_error("Failed to open index file");

    for (auto &indexRecord : doctorSecondaryIndexForName) {
        if (indexRecord.second.empty()) continue;
        DoctorSecondaryIndexForName indexForName(indexRecord.first , indexRecord.second);
        file<<indexForName.toString() <<endl;
    }
    file.close();
}
void FileManager::saveAppointmentDoctorIDSecondaryIndexFile() {
    ofstream file("appointmentsDocotorIDSecondaryIndex.txt");
    if (!file.is_open()) throw runtime_error("Failed to open index file");
    for (auto &indexRecord : appointmentsSecondaryIndexForDoctorID) {
        if (indexRecord.second.empty()) continue;
        AppointmentSecondaryForDoctorID indexForDoctorID(indexRecord.first , indexRecord.second);
        file<<indexForDoctorID.toString() << endl;
    }
    file.close();
}
void FileManager::saveDoctorPrimaryIndexFile() {
    ofstream file("doctorsPrimaryIndex.txt");
    if (!file.is_open()) throw runtime_error("Failed to open index file");
    for (auto &indexRecord : doctorPrimaryIndex) {
        string size = to_string(indexRecord.first) + '|' + to_string(indexRecord.second);
        file << size.length()+1 << '|' << size << endl;
    }
    file.close();
}
void FileManager::saveAppointmentPrimaryIndexFile() {
    ofstream file("appointmentsPrimaryIndex.txt");
    if (!file.is_open()) throw runtime_error("Failed to open index file");
    for (auto &indexRecord : appointmentsPrimaryIndex) {
        string size = to_string(indexRecord.first) + '|' + to_string(indexRecord.second);
        file << size.length()+1 << '|' << size << endl;
    }
    file.close();
}
void FileManager::saveAvailableListDoctor() {
    ofstream file("doctorsAvailableList.txt", ios::in | ios::out);
    if (!file.is_open()) throw runtime_error("Failed to open file");

    file.seekp(0, ios::beg);
    for (int location :availableListDoctor) {
        file << location << "|";
    }
    file << endl;
    file.close();
}
void FileManager::saveAvailableListAppointment() {
    ofstream file("AppointmentAvailableList.txt", ios::in | ios::out);
    if (!file.is_open()) throw runtime_error("Failed to open file");

    file.seekp(0, ios::beg);
    for (auto location :availableListAppointment) {
        file << location << "|";
    }
    file << endl;
    file.close();
}
void FileManager::initialize() {
    loadDoctorsFromFile();
    loadAppointmentsFromFile();
    loadAppointmentsPrimaryIndex();
    loadDoctorPrimaryIndex();
    loadAppointmentDoctorIDSecondaryIndex();
    loadDoctorsNameSecondaryIndex();
    loadAvailableListDoctor();
    loadAvailableListAppointment();
}

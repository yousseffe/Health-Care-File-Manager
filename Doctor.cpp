
#include "Doctor.h"

Doctor::Doctor(const string& id, const string& name, const string& addr) {
    setDoctorID(id);
    setDoctorName(name);
    setAddress(addr);
}

void Doctor::setDoctorID(const string& id) {
    strncpy(doctorID, id.c_str(), 15);
    doctorID[15] = '\0';
}

void Doctor::setDoctorName(const string& name) {
    strncpy(doctorName, name.c_str(), 30);
    doctorName[30] = '\0';
}

void Doctor::setAddress(const string& addr) {
    strncpy(address, addr.c_str(), 30);
    address[30] = '\0';
}

string Doctor::toDelimitedString() const {
    return string(doctorID) + "|" + string(doctorName) + "|" + string(address) + "\n";
}
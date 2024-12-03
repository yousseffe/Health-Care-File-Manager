
#ifndef PROJECT_DOCTOR_H
#define PROJECT_DOCTOR_H
#include <bits/stdc++.h>
#include "Record.h"

using namespace std;

class Doctor : public Record {
public:
    // size + el null
    char doctorID[16]{};
    char doctorName[31]{};
    char address[31]{};

    Doctor( const string& id = "", const  string& name = "", const string& addr = "");

    void setDoctorID(const string& id);
    void setDoctorName(const string& name);
    void setAddress(const string& addr);

    string toDelimitedString() const override;
    void fromDelimitedString(const string& str) override ;
};


#endif //PROJECT_DOCTOR_H

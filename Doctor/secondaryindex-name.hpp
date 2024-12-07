
#ifndef FILE_DOCTORSECONDARYINDEXFORNAME_H
#define FILE_DOCTORSECONDARYINDEXFORNAME_H
#include <iostream>
#include <sstream>
#include <list>
using namespace std;
class DoctorSecondaryIndexForName
{
public:
    string Name;
    list<string> DoctorsID;

    DoctorSecondaryIndexForName(string name, list<string> doctorsID) : Name(name), DoctorsID(doctorsID) {}
    DoctorSecondaryIndexForName(string record)
    {
        stringstream ss(record);
        string length;
        getline(ss, length, '|');
        getline(ss, this->Name, '|');
        string id;
        while (getline(ss, id, '|'))
        {
            DoctorsID.push_back(id);
        }
    }

    string toString()
    {
        string record = Name;
        for (string id : DoctorsID)
        {
            record += "|" + id;
        }
        return to_string(record.length() + 1) + "|" + record;
    }
};
#endif // FILE_DOCTORSECONDARYINDEXFORNAME_H
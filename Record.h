#ifndef HEALTH_CARE_FILE_MANAGER_RECORD_H
#define HEALTH_CARE_FILE_MANAGER_RECORD_H
#include <bits/stdc++.h>
using namespace std;
class Record {
public:
    virtual string toDelimitedString() const = 0;
    virtual void fromDelimitedString(const string& str) = 0;
};
#endif //HEALTH_CARE_FILE_MANAGER_RECORD_H

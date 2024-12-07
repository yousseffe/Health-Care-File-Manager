

#ifndef FILE_PRIMARYINDEX_H
#define FILE_PRIMARYINDEX_H
#include <string>
using namespace std;
class PrimaryIndex
{
public:
    int index;

    virtual string toString() = 0;
};
#endif
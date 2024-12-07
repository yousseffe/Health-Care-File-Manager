#ifndef FILE_ENTITY_H
#define FILE_ENTITY_H
#include <string>
using namespace std;
class Entity
{
public:
    string ID;

    virtual string toString() = 0;
    virtual void display() = 0;
};
#endif // FILE_ENTITY_H
#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

/*!
    \brief Parent class. Shows inheritance

    Inheritance is shown based on it
    and working with virtual functions
*/
class Person
{
public:
    Person(string inName, int inAge);

protected:
    string name;
    int age;
};

#endif // PERSON_H

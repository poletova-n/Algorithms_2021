#pragma once
#include "String.h"

class Person {
private:
    String *m_firstName;
    String *m_lastName;
    String *m_yearOfBirth;
public:
    Person();
    Person(String, String, String);
    ~Person();
    String getFirstName();
    String getLastName();
    String getYearOfBirth();
    void setFirstName(const String&);
    void setLastName(const String&);
    void setYearOfBirth(const String&);
    int compareFNames(const Person&);
    int compareLNames(const Person&);
    int compareYBirth(const Person&);
    friend bool checkData(const Person&);
    friend bool operator>(const Person&, const Person&);
};




#ifndef ALGORITHMS_2021_PERSON_H
#define ALGORITHMS_2021_PERSON_H

#endif //ALGORITHMS_2021_PERSON_H

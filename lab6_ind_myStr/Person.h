
#ifndef MAIN_CPP_PERSON_H
#define MAIN_CPP_PERSON_H

#include <string>
#include <iostream>
#include "String.h"

using std::string;

class Person {
public:
    Person() {}
    Person(String person);

    String getFirstName() { return firstName_; }
    String getSecondName() { return secondName_; }
    String getDateOfBirth() { return dateOfBirth; }

    static bool isValidInfo(String str);

    static bool compFistName(Person o1, Person o2);
    static bool compSecondName(Person o1, Person o2);
    static bool compDateOfBirth(Person o1, Person o2);

    static bool isValidFirstName(String firstName);
    static bool isValidSecondName(String secondName);
    static bool isValidYear(String dateOfBirth);
private:
    String firstName_;
    String secondName_;
    String dateOfBirth;
};


#endif //MAIN_CPP_PERSON_H

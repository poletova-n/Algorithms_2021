#ifndef MAIN_CPP_PERSON_H
#define MAIN_CPP_PERSON_H

#include <string>
#include <iostream>

using std::string;

class Person {
public:
    Person() {}
    Person(string person);

    string getFirstName() { return firstName_; }
    string getSecondName() { return secondName_; }
    string getDateOfBirth() { return dateOfBirth; }

    static bool isValidInfo(string str);

    static bool compFistName(Person o1, Person o2);
    static bool compSecondName(Person o1, Person o2);
    static bool compDateOfBirth(Person o1, Person o2);

    static bool isValidFirstName(string firstName);
    static bool isValidSecondName(string secondName);
    static bool isValidYear(string dateOfBirth);
private:
    string firstName_;
    string secondName_;
    string dateOfBirth;

};


#endif //MAIN_CPP_PERSON_H

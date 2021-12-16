#pragma once
#include <string>
#include <iostream>

class Person {
private:
    std::string* m_firstName;
    std::string* m_lastName;
    std::string* m_yearOfBirth;
public:
    Person();
    Person(std::string, std::string, std::string);
    ~Person();
    std::string getFirstName();
    std::string getLastName();
    std::string getYearOfBirth();
    void setFirstName(const std::string&);
    void setLastName(const std::string&);
    void setYearOfBirth(const std::string&);
    int compareFNames(const Person&);
    int compareLNames(const Person&);
    int compareYBirth(const Person&);
    friend bool checkData(const Person&);
};


#ifndef ALGORITHMS_2021_PERSON_H
#define ALGORITHMS_2021_PERSON_H

#endif //ALGORITHMS_2021_PERSON_H

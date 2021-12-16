#include "Person.h"
#include <cstring>
#include <ctime>

Person::Person() {
    m_firstName = new std::string;
    m_lastName = new std::string;
    m_yearOfBirth = new std::string;
}

Person::Person(std::string lName, std::string fName, std::string yBirth) {
    m_firstName = new std::string(fName);
    m_lastName = new std::string(lName);
    m_yearOfBirth = new std::string(yBirth);
}

Person::~Person() {
    delete m_firstName, m_lastName, m_yearOfBirth;
}

std::string Person::getFirstName() {
    return *m_firstName;
}

std::string Person::getLastName() {
    return *m_lastName;
}

std::string Person::getYearOfBirth() {
    return *m_yearOfBirth;
}

void Person::setFirstName(const std::string& str) {
    if (m_firstName != nullptr)
        *m_firstName = str;
    else
        std::cout << "Ошибка!\n";
}

void Person::setLastName(const std::string& str) {
    if (m_lastName != nullptr)
        *m_lastName = str;
    else
        std::cout << "Ошибка!\n";
}

void Person::setYearOfBirth(const std::string& str) {
    if (m_yearOfBirth != nullptr)
        *m_yearOfBirth = str;
    else
        std::cout << "Ошибка!\n";
}

int Person::compareFNames(const Person& pers) {
    return strcmp(m_firstName->c_str(), pers.m_firstName->c_str());
}

int Person::compareLNames(const Person& pers) {
    return strcmp(m_lastName->c_str(), pers.m_lastName->c_str());
}

int Person::compareYBirth(const Person& pers) {
    return strcmp(m_yearOfBirth->c_str(), pers.m_yearOfBirth->c_str());
}

bool checkData(const Person& pers) {
    int fnSize = pers.m_firstName->length();
    int lnSize = pers.m_lastName->length();
    int bdSize = pers.m_yearOfBirth->length();
    int year = atoi(pers.m_yearOfBirth->c_str());

    std::time_t t = std::time(nullptr);
    std::tm* const pTInfo = std::localtime(&t);

    if (bdSize != 4)return false;
    for (int i = 0; i < 4; i++) {
        if (year > 1900 + pTInfo->tm_year || year <= 0)return false;
        if ((*pers.m_yearOfBirth)[i] < 48 || (*pers.m_yearOfBirth)[i] > 57)return false;
    }

    if (fnSize > 10 || fnSize < 2)return false;
    if ((*pers.m_firstName)[0] > 90 || (*pers.m_firstName)[0] < 65)return false;
    for (int i = 1; i < fnSize - 1; i++) {
        if ((*pers.m_firstName)[i] < 97 || (*pers.m_firstName)[i] > 122)return false;
    }

    if (lnSize > 20 || lnSize < 3)return false;
    if ((*pers.m_lastName)[0] > 90 || (*pers.m_lastName)[0] < 65)return false;
    for (int i = 1; i < lnSize - 1; i++) {
        if ((*pers.m_lastName)[i] < 97 || (*pers.m_lastName)[i] > 122) {
            if (i != lnSize) {
                if ((*pers.m_lastName)[i] != '-' || ((*pers.m_lastName)[i] == '-' && (*pers.m_lastName)[i + 1] == '-'))return false;
            }
            else return false;
        }
    }
    return true;
}

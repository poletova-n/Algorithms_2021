#define _CRT_SECURE_NO_WARNINGS
#include "Person.h"
#include <ctime>

Person::Person() {
    m_firstName = new String();
    m_lastName = new String();
    m_yearOfBirth = new String();
}

Person::Person(String fName, String lName, String date) {
    m_firstName = new String(&fName);
    m_lastName = new String(&lName);
    m_yearOfBirth = new String(&date);
}

String Person::getFirstName() {
    return m_firstName;
}

String Person::getLastName() {
    return m_lastName;
}

String Person::getYearOfBirth() {
    return m_yearOfBirth;
}

void Person::setFirstName(const String& str) {
    if (m_firstName)delete m_firstName;
    m_firstName = new String(&str);
}

void Person::setLastName(const String& str) {
    if(m_lastName != nullptr)delete m_lastName;
    m_lastName = new String(&str);
}

void Person::setYearOfBirth(const String& str) {
    if (m_yearOfBirth)delete m_yearOfBirth;
    m_yearOfBirth = new String(&str);
}

int Person::compareFNames(const Person& pers) {
    return m_firstName->compare(pers.m_firstName);
}

int Person::compareLNames(const Person& pers) {
    return m_lastName->compare(pers.m_lastName);
}

int Person::compareYBirth(const Person& pers) {
    char* y1 = m_yearOfBirth->getCString();
    char* y2 = pers.m_yearOfBirth->getCString();
    for (int i = 0; i < 4; i++) {
        if (y1[i] > y2[i])return 1;
        if(y1[i] < y2[i])return -1;
    }
    return 0;
}

bool checkData(const Person &pers) {
    int fnSize = getSize(pers.m_firstName);
    int lnSize = getSize(pers.m_lastName);
    int bdSize = getSize(pers.m_yearOfBirth);
    int year = atoi(pers.m_yearOfBirth->getCString());

    std::time_t t = std::time(nullptr);
    std::tm* const pTInfo = std::localtime(&t);

    if (bdSize != 5)return false;
    for (int i = 0; i < 4; i++) {
        if(year > 1900 + pTInfo->tm_year || year <= 0)return false;
        if ( (*pers.m_yearOfBirth)[i] < 48 || (*pers.m_yearOfBirth)[i] > 57 )return false;
    }

    if (fnSize > 11 || fnSize < 3)return false;
    if ( (*pers.m_firstName)[0] > 90 || (*pers.m_firstName)[0] < 65 )return false;
    for (int i = 1; i < fnSize-1; i++) {
        if ( (*pers.m_firstName)[i] < 97 || (*pers.m_firstName)[i] > 122 )return false;
    }

    if (lnSize > 21 || lnSize < 4)return false;
    if ((*pers.m_lastName)[0] > 90 || (*pers.m_lastName)[0] < 65)return false;
    for (int i = 1; i < lnSize-1; i++) {
        if ( (*pers.m_lastName)[i] < 97 || (*pers.m_lastName)[i] > 122 ) {
            if (i != lnSize) {
                if ( (*pers.m_lastName)[i] != '-' || ((*pers.m_lastName)[i] == '-' && (*pers.m_lastName)[i + 1] == '-') )return false;
            }
            else return false;
        }
    }
    return true;
}

bool operator>(const Person& pers1, const Person& pers2) {
    if (pers1.m_firstName->compare(pers2.m_firstName) == 1)
        return true;

    if (pers1.m_yearOfBirth->compare(pers2.m_yearOfBirth) == 1)
        return true;

    if (pers1.m_lastName->compare(pers2.m_lastName) == 1)
        return true;

    return false;
}

Person::~Person() {
    delete m_firstName, m_lastName, m_yearOfBirth;
    m_firstName = nullptr;
    m_lastName = nullptr;
    m_yearOfBirth = nullptr;
}

#include "Person.h"

bool Person::isValidSecondName(String secondName) {
    if (secondName.length() < 3 || secondName.length() > 20) {
        return false;
    }
    for (int i = 0; i < secondName.length(); i++) {
        if (!std::isalpha(secondName[i]) && secondName[i] != '-') {
            return false;
        }
    }
    return true;
}

bool Person::isValidInfo(String str) {
    String info[3];
    int counter = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ' ') {
            info[counter] += str[i];
        }
        else {
            counter++;
            while (i < str.size() && str[i] == ' ') {
                i++;
            }
            i--;
        }
    }

    if (isValidFirstName(info[0]) && isValidSecondName(info[1]) && isValidYear(info[2])) {
        return true;
    }
    else {
        return false;
    }
}

bool Person::compFistName(Person o1, Person o2)
{
    return o1.firstName_ > o2.firstName_;
}

bool Person::compSecondName(Person o1, Person o2)
{
    return o1.secondName_ > o2.secondName_;
}

bool Person::compDateOfBirth(Person o1, Person o2)
{
    return o1.dateOfBirth > o2.dateOfBirth;
}

bool Person::isValidFirstName(String firstName) {
    if (firstName.length() < 2 || firstName.length() > 10) {
        return false;
    }
    for (int i = 0; i < firstName.length(); i++) {
        if (!std::isalpha(firstName[i]) && firstName[i] != '-') {
            return false;
        }
    }
    return true;
}

bool Person::isValidYear(String dateOfBirth) {
    if (dateOfBirth.length() != 4) {
        return false;
    }

    for (int i = 0; i < 4; i++) {
        if (!std::isdigit(dateOfBirth[i])) {
            return false;
        }
    }
    return true;
}

Person::Person(String person) {
    String info[3];
    int counter = 0;
    for (int i = 0; i < person.size(); i++) {
        if (person[i] != ' ') {
            info[counter] += person[i];
        }
        else {
            counter++;
            while (i < person.size() && person[i] == ' ') {
                i++;
            }
            i--;
        }
    }
    info[0][0] = toupper(info[0][0]);
    info[1][0] = toupper(info[1][0]);
    firstName_ = info[0];
    secondName_ = info[1];
    dateOfBirth = info[2];
}
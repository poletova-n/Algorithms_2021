#include <istream>
#include <iostream>
#include <fstream>
#include "Person.h"

std::fstream& operator>>(std::fstream& input, Person& subscriber) {
    input >> subscriber._secondName;
    input >> subscriber._firstName;
    input >> subscriber._year;
    return input;
}

std::fstream& operator<<(std::fstream& output, Person& subscriber) {
    output << subscriber._secondName << " ";
    output << subscriber._firstName << " ";
    output << subscriber._year << std::endl;;
    return output;
}

void Person::Folder::setInfo(String info) {
    this->_info = info;
}

int Person::Folder::compare(Person::Folder folder) {
    return _info.compare(folder._info);
}

std::fstream& operator>>(std::fstream& input, Person::Folder& folder) {
    String inputString;
    input >> inputString;
    if (folder.isPatternCorrect(inputString)) {
        folder.setInfo(inputString);
    }
    else {
        folder.printError();
    }
    return input;
}

std::fstream& operator<<(std::fstream& output, Person::Folder& folder) {
    String string = folder.getInfo();
    output << string;
    return output;
}

bool operator>(Person& subscriber, Person& anotherSubscriber) {

    int answer = subscriber._secondName.compare(anotherSubscriber._secondName);

    if (answer != 2) { return answer; }

    answer = subscriber._firstName.compare(anotherSubscriber._firstName);

    if (answer != 2) { return answer; }

    answer = subscriber._year.compare(anotherSubscriber._year);

    if (answer != 2) { return  answer; }
}

const Person::FirstNameFolder& Person::getFirstName() const {
    return _firstName;
}

const Person::SecondNameFolder& Person::getSecondName() const {
    return _secondName;
}

const Person::YearNumberFolder Person::getYear() const {
    return _year;
}

bool Person::Folder::isPatternCorrect(String& string) {
    return false;
}

void Person::Folder::printError() {
    throw ERROR_PATTERN_NOT_CORRECT;
}

const String Person::Folder::getInfo() const {
    return _info;
}

bool Person::YearNumberFolder::isPatternCorrect(String& string) {
    int length = string.length();
    if (length != 4) return false;
    for (int i = 0; i < length; ++i) {
            if (string.at(i) < '0' && string.at(i) > '9') return false;
    }
    return true;
}

void Person::YearNumberFolder::printError() {
    throw ERROR_PATTERN_NOT_CORRECT;
}

bool Person::FirstNameFolder::isPatternCorrect(String& string) {
    return (string.at(0) >= 'A' && string.at(0) <= 'Z' && string.length() >= 2);
}

void Person::FirstNameFolder::printError() {
    throw ERROR_PATTERN_NOT_CORRECT;
}


bool Person::SecondNameFolder::isPatternCorrect(String& string) {
    int length = string.length();
    int defCount = 0;
    if (length < 3 || length > 20 || string.at(0) == '-'
        || string.at(length - 1) == '-'
        || string.at(0) < 'A' || string.at(0) > 'Z') return false;
    for (int i = 1; i < length - 1; ++i) {
        if (string.at(i) == '-')
        {
            if (defCount == 0) {
                defCount++;
            }
            else {
                return false;
            }
        }
        else if (string.at(i) < 'a' || string.at(i) > 'z') return false;
    }
    return true;
}

void Person::SecondNameFolder::printError() {
    throw ERROR_PATTERN_NOT_CORRECT;
}
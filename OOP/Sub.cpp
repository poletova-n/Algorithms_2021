#include <istream>
#include <iostream>
#include <fstream>
#include <utility>
#include <sstream>
#include "Sub.h"

std::fstream& operator>>(std::fstream& input, Sub& subscriber) {

    std::string stringInput;
    std::getline(input, stringInput);
    std::string stringInputSplited[4] = { "", "", "", "" };
    int cur = 0;

    stringInputSplited[0] += stringInput[0];
    for (int i = 1; i < stringInput.length(); ++i) {
        if (stringInput[i] != ' ') {
            if (stringInput[i - 1] == ' ') cur++;
            stringInputSplited[cur] += stringInput[i];
        }
    }
    subscriber.setSecondName(stringInputSplited[0]);
    subscriber.setFirstName(stringInputSplited[1]);
    subscriber.setCode(stringInputSplited[2]);
    subscriber.setPhone(stringInputSplited[3]);
    return input;
}

std::fstream& operator<<(std::fstream& output, Sub& subscriber) {
    std::string outputString = subscriber.getCode() + " " + subscriber.getSecondName() + " " + subscriber.getFirstName() + " " + subscriber.getPhone();
    output << outputString << std::endl;
    return output;
}

bool operator>(Sub& subscriber, Sub& anotherSubscriber) {

    int answer = subscriber.getCode().compare(anotherSubscriber.getCode());

    if (answer != 0) { return (answer + 1) / 2; }

    answer = subscriber.getSecondName().compare(anotherSubscriber.getSecondName());

    if (answer != 0) { return (answer + 1) / 2; }

    answer = subscriber.getFirstName().compare(anotherSubscriber.getFirstName());

    if (answer != 0) { return (answer + 1) / 2; }

    answer = subscriber.getPhone().compare(anotherSubscriber.getPhone());

    if (answer != 0) { return (answer + 1) / 2; }
    
    return false;
}

const std::string& Sub::getFirstName() const {
    return _firstName;
}

const std::string& Sub::getSecondName() const {
    return _secondName;
}

const std::string& Sub::getPhone() const {
    return _phone;
}

const std::string& Sub::getCode() const {
    return _code;
}

void Sub::setFirstName(const std::string& firstName) {
    if (isFirstNameCorrect(firstName)) _firstName = firstName;
    else throw INVALID_FIRST_NAME;
}

void Sub::setSecondName(const std::string& secondName) {
    if (isSecondNameCorrect(secondName)) _secondName = secondName;
    else throw INVALID_SECOND_NAME;
}

void Sub::setPhone(const std::string& phone) {
    if (isPhoneCorrect(phone)) _phone = phone;
    else throw INVALID_PHONE;
}

void Sub::setCode(const std::string& code) {
    if (isCodeCorrect(code)) _code = code;
    else throw INVALID_CODE;
}

Sub::Sub(const std::string& firstName, const std::string& secondName, const std::string& phone,
    const std::string& code) : _firstName(firstName), _secondName(secondName), _phone(phone),
    _code(code) {}

bool Sub::isFirstNameCorrect(const std::string& string) {
    return (string.at(0) >= 'A' && string.at(0) <= 'Y' && string.at(1) == '.' && string.length() == 2);
}

bool Sub::isSecondNameCorrect(const std::string& string) {
    int length = string.length();
    int defCount = 0;
    if (length < 3 || length > 20 || string.at(0) == '-'
        || string.at(length - 1) == '-'
        || string.at(0) < 'A' || string.at(0) > 'Y') return false;
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
        else if (string.at(i) < 'a' || string.at(i) > 'y') return false;
    }
    return true;
}

bool Sub::isCodeCorrect(const std::string& string) {
    if (string.length() != 3) return false;
    for (int i = 0; i < string.length(); ++i) {
        if (string.at(i) < '0' || string.at(i) > '9') return false;
    }
    return true;
}

bool Sub::isPhoneCorrect(const std::string& string) {

    int length = string.length();
    if (length != 16) return false;
    if (string.at(0) != '+' || string.at(2) != '(' || string.at(6) != ')'
        || string.at(13) != '-' || string.at(10) != '-') return false;
    for (int i = 1; i < length; ++i) {
        if (i != 2 && i != 6 && i != 13 && i != 10) {
            if (string.at(i) < '0' && string.at(i) > '9') return false;
        }
    }
    return true;
}
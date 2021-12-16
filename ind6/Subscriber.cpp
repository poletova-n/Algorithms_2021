#include <istream>
#include <iostream>
#include <fstream>
#include "Subscriber.h"

std::fstream &operator>>(std::fstream &input, Subscriber &subscriber) {
    input >> subscriber._secondName;
    input >> subscriber._firstName;
    input >> subscriber._code;
    input >> subscriber._phone;
    return input;
}

std::fstream &operator<<(std::fstream &output, Subscriber &subscriber) {
    output << subscriber._secondName << " ";
    output << subscriber._firstName << " ";
    output << subscriber._code << " ";
    output << subscriber._phone << std::endl;;
    return output;
}

void Subscriber::Folder::setInfo(String info) {
    this->_info = info;
}

int Subscriber::Folder::compare(Subscriber::Folder folder) {
    return _info.compare(folder._info);
}

std::fstream &operator>>(std::fstream &input, Subscriber::Folder &folder) {
    String inputString;
    input >> inputString;
    if(folder.isPatternCorrect(inputString)) {
        folder.setInfo(inputString);
        //std::cout << "s";
    } else {
        folder.printError();
    }
    return input;
}

std::fstream &operator<<(std::fstream &output, Subscriber::Folder &folder) {
    String string = folder.getInfo();
    output << string;
    return output;
}

bool operator>(Subscriber &subscriber, Subscriber &anotherSubscriber) {

    int answer = subscriber._secondName.compare(anotherSubscriber._secondName);

    if(answer != 2){return answer;}

    answer = subscriber._firstName.compare(anotherSubscriber._firstName);

    if(answer != 2){return answer;}

    answer = subscriber._code.compare(anotherSubscriber._code);

    if( answer != 2){return answer;}

    answer =  subscriber._phone.compare(anotherSubscriber._phone);

    if( answer != 2){return  answer;}
}

const Subscriber::FirstNameFolder &Subscriber::getFirstName() const {
    return _firstName;
}

const Subscriber::SecondNameFolder &Subscriber::getSecondName() const {
    return _secondName;
}

const Subscriber::PhoneNumberFolder Subscriber::getPhone() const {
    return _phone;
}

const Subscriber::TariffCodeFolder Subscriber::getCode() const {
    return _code;
}

bool Subscriber::Folder::isPatternCorrect(String &string) {
    return false;
}

void Subscriber::Folder::printError() {
    throw ERROR_PATTERN_NOT_CORRECT;
}

const String Subscriber::Folder::getInfo() const {
    return _info;
}

bool Subscriber::PhoneNumberFolder::isPatternCorrect(String &string) {
    int length = string.length();
    if(length != 16) return false;
    if(string.at(0) != '+' || string.at(2) != '(' || string.at(6) != ')'
       || string.at(13) != '-' || string.at(10) != '-') return false;
    for (int i = 1; i < length; ++i) {
        if(i != 2 && i != 6 && i != 13 && i != 10){
            if(string.at(i) < '0' && string.at(i) > '9') return false;
        }
    }
    return true;
}

void Subscriber::PhoneNumberFolder::printError() {
    throw ERROR_PATTERN_NOT_CORRECT;
}

bool Subscriber::TariffCodeFolder::isPatternCorrect(String &string) {
    if (string.length() != 3) return false;
    for (int i = 0; i < string.length(); ++i) {
        if (string.at(i) < '0' || string.at(i) > '9') return false;
    }
    return true;
}

void Subscriber::TariffCodeFolder::printError() {
    throw ERROR_PATTERN_NOT_CORRECT;
}

bool Subscriber::FirstNameFolder::isPatternCorrect(String &string) {
    return (string.at(0) >= 'A' && string.at(0) <= 'Y'
        & string.at(1) == '.' && string.length() == 2);
}

void Subscriber::FirstNameFolder::printError() {
    throw ERROR_PATTERN_NOT_CORRECT;
}


bool Subscriber::SecondNameFolder::isPatternCorrect(String &string) {
    int length = string.length();
    int defCount = 0;
    if (length < 3 || length > 20 || string.at(0) == '-'
        || string.at(length - 1) == '-'
            || string.at(0) < 'A' || string.at(0) > 'Y') return false;
    for (int i = 1; i < length - 1; ++i) {
        if(string.at(i) == '-')
        {
            if(defCount == 0) {
                defCount++;
            } else {
                return false;
            }
        }
        else if(string.at(i) < 'a' || string.at(i) > 'y') return false;
    }
    return true;
}

void Subscriber::SecondNameFolder::printError() {
    throw ERROR_PATTERN_NOT_CORRECT;
}

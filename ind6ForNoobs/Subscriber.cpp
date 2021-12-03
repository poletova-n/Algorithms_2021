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
    return _info.compare(folder.getInfo());
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

    //std::cout << subscriber._secondName.compare(anotherSubscriber._secondName);

    if(subscriber._secondName.compare(anotherSubscriber._secondName) != 2){
        return subscriber._secondName.compare(anotherSubscriber._secondName);
    }
    if(subscriber._firstName.compare(anotherSubscriber._firstName) != 2)
    {
        return subscriber._firstName.compare(anotherSubscriber._firstName);
    }
    if(subscriber._code.compare(anotherSubscriber._code) != 2)
    {
        return subscriber._code.compare(anotherSubscriber._code);
    }
    if( subscriber._phone.compare(anotherSubscriber._phone) != 2)
    {
        return  subscriber._phone.compare(anotherSubscriber._phone);
    }
}

const Subscriber::FirstNameFolder &Subscriber::getFirstName() const {
    return _firstName;
}

const Subscriber::SecondNameFolder &Subscriber::getSecondName() const {
    return _secondName;
}

const Subscriber::PhoneNumberFolder &Subscriber::getPhone() const {
    return _phone;
}

const Subscriber::TariffCodeFolder &Subscriber::getCode() const {
    return _code;
}

bool Subscriber::Folder::isPatternCorrect(String &string) {
    return false;
}

String Subscriber::Folder::getInfo() const {
    return this->_info;
}

void Subscriber::Folder::printError() {
    throw ERROR_PATTERN_NOT_CORRECT;
}

bool Subscriber::PhoneNumberFolder::isPatternCorrect(String &string) {
    int length = string.getLength();
    if(length != 16) return false;
    if(string.get(0) != '+' || string.get(2) != '(' || string.get(6) != ')'
       || string.get(13) != '-' || string.get(10) != '-') return false;
    for (int i = 1; i < length; ++i) {
        if(i != 2 && i != 6 && i != 13 && i != 10){
            if(string.get(i) < '0' && string.get(i) > '9') return false;
        }
    }
}

void Subscriber::PhoneNumberFolder::printError() {
    throw ERROR_PATTERN_NOT_CORRECT;
}

bool Subscriber::TariffCodeFolder::isPatternCorrect(String &string) {
    if (string.getLength() != 3) return false;
    for (int i = 0; i < string.getLength(); ++i) {
        if (string.get(i) < '0' || string.get(i) > '9') return false;
    }
    return true;
}

int Subscriber::TariffCodeFolder::compare(Subscriber::Folder folder) {
    return this->getInfo().compare(folder.getInfo());
}

void Subscriber::TariffCodeFolder::printError() {
    throw ERROR_PATTERN_NOT_CORRECT;
}

bool Subscriber::FirstNameFolder::isPatternCorrect(String &string) {
    return (string.get(0) >= 'A' && string.get(0) <= 'Y'
        & string.get(1) == '.' && string.getLength() == 2);
}

void Subscriber::FirstNameFolder::printError() {
    throw ERROR_PATTERN_NOT_CORRECT;
}


bool Subscriber::SecondNameFolder::isPatternCorrect(String &string) {
    int length = string.getLength();
    int defCount = 0;
    if (length < 3 || length > 20 || string.get(0) == '-'
        || string.get(length - 1) == '-'
            || string.get(0) < 'A' || string.get(0) > 'Y') return false;
    for (int i = 1; i < length - 1; ++i) {
        if(string.get(i) == '-')
        {
            if(defCount == 0) {
                defCount++;
            } else {
                return false;
            }
        }
        else if(string.get(i) < 'a' || string.get(i) > 'y') return false;
    }
    return true;
}

void Subscriber::SecondNameFolder::printError() {
    throw ERROR_PATTERN_NOT_CORRECT;
}

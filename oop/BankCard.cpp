#include "BankCard.h"

#include <iostream>

#include <string>

namespace laba6 {

    BankCard::BankCard(const std::string& name, const std::string& surname, const std::string& num, const std::string& date) :

            name_(name), num_(num), date_(date), surname_(surname) {};

    std::string BankCard::getName() const {

        return name_;

    }

    std::string BankCard::getSurname() const {

        return surname_;

    }

    std::string BankCard::getNum() const {

        return num_;

    }

    std::string BankCard::getDate() const {

        return date_;

    }

    std::ostream& operator<< (std::ostream& stream, const BankCard& bc) {

        return stream << bc.getName() << " " << bc.getSurname() << "\n" << bc.getNum() << "\n" << bc.getDate();

    }

}
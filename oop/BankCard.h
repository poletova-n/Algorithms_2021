#ifndef BANKCARD_H

#define BANKCARD_H

#include <string>

namespace laba6 {

    class BankCard {

    private:

        std::string name_;

        std::string surname_;

        std::string num_;

        std::string date_;

    public:

        BankCard() = default;

        BankCard(const std::string& name, const std::string& surname, const std::string& num, const std::string& date);

        BankCard(const BankCard& bc) = default;

        ~BankCard() = default;

        std::string getName() const;

        std::string getSurname() const;

        std::string getNum() const;

        std::string getDate() const;

    };

    std::ostream& operator<< (std::ostream& stream, const BankCard& bc);

}

#endif
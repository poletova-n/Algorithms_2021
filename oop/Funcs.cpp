#include "funcs.h"

#include "BankCard.h"

namespace laba6 {

    void sortByName(BankCard* cards, int N) {

        for (int i = 1; i < N; i++)

            for (int j = i; j > 0 && cards[j - 1].getName() > cards[j].getName(); j--)

                std::swap(cards[j - 1], cards[j]);

    }

    void sortByNum(BankCard* cards, int N) {

        for (int i = 1; i < N; i++)

            for (int j = i; j > 0 && cards[j - 1].getNum() > cards[j].getNum(); j--)

                std::swap(cards[j - 1], cards[j]);

    }

    void sortByDate(BankCard* cards, int N) {

        for (int i = 1; i < N; i++)

            for (int j = i; j > 0 &&

                            cards[j - 1].getDate().substr(3, 2) > cards[j].getDate().substr(3, 2);

                 j--)

                std::swap(cards[j - 1], cards[j]);

        for (int i = 1; i < N; i++)

            for (int j = i; j > 0 &&

                            cards[j - 1].getDate().substr(0, 2) > cards[j].getDate().substr(0, 2)

                            && cards[j - 1].getDate().substr(3, 2) == cards[j].getDate().substr(3, 2);

                 j--)

                std::swap(cards[j - 1], cards[j]);

    }

    int countCard(const BankCard* cards, int N) {

        int count = 0;

        for (int i = 0; i < N; i++)

            if (cards[i].getDate().substr(3, 2) == "21")

                count++;

        return count;

    }

    bool isEqualSurnamesAndUnequalNames(const BankCard* cards, int N) {

        bool out = false;

        for (int i = 0; i < N && !out; i++)

            for (int j = i; j < N && !out; j++)

                if (cards[i].getSurname() == cards[j].getSurname() &&

                    cards[i].getName() != cards[j].getName())

                    out = true;

        return out;

    }

}
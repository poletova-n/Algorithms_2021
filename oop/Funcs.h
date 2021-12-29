#ifndef FUNCS_H

#define FUNCS_H

#include "BankCard.h"

namespace laba6 {

    void sortByName(BankCard* cards, int N);

    void sortByNum(BankCard* cards, int N);

    void sortByDate(BankCard* cards, int N);

    int countCard(const BankCard* cards, int N);

    bool isEqualSurnamesAndUnequalNames(const BankCard* cards, int N);

}

#endif
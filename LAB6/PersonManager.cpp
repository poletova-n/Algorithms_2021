#include <iostream>
#include "PersonManager.h"
#include "Person.h"


int PersonManager::getNumberOfUniqSecondNames(Person*& subscribers, int length) {
    int answer = 0;
    for (int i = 0; i < length; i++) {
        bool foundDup = false;
        for (int j = 0; j < length; j++) {
            if (i != j) {
                if (subscribers[j].getSecondName().getInfo().compare(subscribers[i].getSecondName().getInfo()) == 2) {
                    foundDup = true;
                    break;
                }
            }
        }
        if (!foundDup) answer++;
    }
    return answer;
}

int PersonManager::getNumberOfTheSameFIOs(Person*& subscribers, int length) {
    int answer = 0;
    for (int i = 0; i < length; i++) {
        bool foundDup = false;
        for (int j = 0; j < length; j++) {
            if (i != j) {
                if (subscribers[j].getSecondName().getInfo().compare(subscribers[i].getSecondName().getInfo()) == 2 &&
                    subscribers[j].getFirstName().getInfo().compare(subscribers[i].getFirstName().getInfo()) == 2) {
                    answer++;
                    break;
                }
            }
        }
    }
    return answer;
}
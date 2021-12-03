#ifndef ALGORITHMS_2021_SUBSCRIBERSMANAGER_H
#define ALGORITHMS_2021_SUBSCRIBERSMANAGER_H

#include "ArrayManager.h"
#include "Person.h"

class PersonManager : public ArrayManager {

public:

    PersonManager() = delete;

    static int getNumberOfUniqSecondNames(Person*& subscribers, int length);

    static int getNumberOfTheSameFIOs(Person*& subscribers, int length);

};


#endif //ALGORITHMS_2021_SUBSCRIBERSMANAGER_H
#ifndef ALGORITHMS_2021_SUBSCRIBERSMANAGER_H
#define ALGORITHMS_2021_SUBSCRIBERSMANAGER_H

#include "ArrayManager.h"
#include "Subscriber.h"

class SubscribersManager : public ArrayManager {

public:

    SubscribersManager() = delete;

    static int getNumberOfUniqTrafficCodes(Subscriber * &subscribers, int length);

    static int getNumberOfDiffPhonesOnOneTrafficCode(Subscriber * &subscribers, int length);

};


#endif //ALGORITHMS_2021_SUBSCRIBERSMANAGER_H

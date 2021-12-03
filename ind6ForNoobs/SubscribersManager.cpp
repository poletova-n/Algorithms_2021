#include "SubscribersManager.h"
#include "Subscriber.h"


int SubscribersManager::getNumberOfDiffPhonesOnOneTrafficCode(Subscriber * &subscribers, int length){
    int answer = 0;
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            if(i != j && subscribers[j].getCode().getInfo().compare(subscribers[i].getCode().getInfo()) == 2){
                if(subscribers[j].getPhone().getInfo().compare(subscribers[i].getPhone().getInfo()) != 2) {
                    answer++;
                    break;
                }
            }
        }
    }
    return answer;
}

int SubscribersManager::getNumberOfUniqTrafficCodes(Subscriber * &subscribers, int length){
    int answer = 0;
    bool current;
    for (int i = 0; i < length; ++i) {
        current = true;
        for (int j = 0; j < length; ++j) {
            if(i != j){
                if(subscribers[j].getCode().getInfo().compare(subscribers[i].getCode().getInfo()) == 2){
                    current = false;
                    break;
                }
            }
        }
        if(current) answer++;
    }
    return answer;
}
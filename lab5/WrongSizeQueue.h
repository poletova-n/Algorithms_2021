//
// Created by Foko on 15.05.2022.
//

#ifndef ONE_WAY_LIST_WRONGSIZEQUEUE_H
#define ONE_WAY_LIST_WRONGSIZEQUEUE_H

#include <exception>
#include <string>

class WrongSizeQueue: public std::exception {
private:
    std::string msg = "Wrong queue size.";
public:
    WrongSizeQueue () = default;
    const char* what() const noexcept override {
        return msg.c_str();
    }
};


#endif //ONE_WAY_LIST_WRONGSIZEQUEUE_H

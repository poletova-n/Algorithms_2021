//
// Created by Администратор on 26.02.2022.
//

#ifndef ALGORITHMS_2021_WRONGSTACKSIZE_H
#define ALGORITHMS_2021_WRONGSTACKSIZE_H


#include <exception>
#include <iostream>

class WrongStackSize : public std::exception {

public:

    WrongStackSize() : reason_("Wrong stack size") {}

    [[nodiscard]] const char * what() const override { return reason_; }

private:

    const char * reason_;
};
#endif //ALGORITHMS_2021_WRONGSTACKSIZE_H

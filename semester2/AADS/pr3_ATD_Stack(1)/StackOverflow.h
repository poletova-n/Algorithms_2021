#ifndef ALGORITHMS_2021_STACKOVERFLOW_H
#define ALGORITHMS_2021_STACKOVERFLOW_H

#include <exception>

class StackOverflow : public std::exception {

public:

    StackOverflow() : reason_("Stack Overflow") {}

    [[nodiscard]] const char * what() const override { return reason_; }

private:

    const char * reason_;
};


#endif //ALGORITHMS_2021_STACKOVERFLOW_H

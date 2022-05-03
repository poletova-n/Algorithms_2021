#ifndef ALGORITHMS_2021_STACKUNDERFLOW_H
#define ALGORITHMS_2021_STACKUNDERFLOW_H


#include <exception>

class StackUnderflow : public std::exception {

public:

    StackUnderflow() : reason_("Stack Underflow") {}

    [[nodiscard]] const char * what() const override { return reason_; }

private:

    const char * reason_;
};


#endif //ALGORITHMS_2021_STACKUNDERFLOW_H

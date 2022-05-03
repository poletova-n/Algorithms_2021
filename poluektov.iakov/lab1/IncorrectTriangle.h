#ifndef ALGORITHMS_2021_INCORRECTTRIANGLE_H
#define ALGORITHMS_2021_INCORRECTTRIANGLE_H

#include <exception>

class IncorrectTriangle : public std::exception {

public:

    IncorrectTriangle() : reason_("Incorrect triangle!") {}

    [[nodiscard]] const char * what() const override { return reason_; }

private:

    const char * reason_;
};

#endif //ALGORITHMS_2021_INCORRECTTRIANGLE_H

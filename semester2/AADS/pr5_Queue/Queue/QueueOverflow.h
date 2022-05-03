#ifndef ALGORITHMS_2021_QUEUEOVERFLOW_H
#define ALGORITHMS_2021_QUEUEOVERFLOW_H

#include <exception>

class QueueOverflow : public std::exception {

public:

    QueueOverflow() : reason_("Queue Overflow") {}

    [[nodiscard]] const char * what() const override { return reason_; }

private:

    const char * reason_;
};

#endif //ALGORITHMS_2021_QUEUEOVERFLOW_H

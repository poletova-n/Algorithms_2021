//
// Created by Администратор on 22.03.2022.
//

#ifndef ALGORITHMS_2021_QUEUEUNDERFLOW_H
#define ALGORITHMS_2021_QUEUEUNDERFLOW_H

class QueueUnderflow : public std::exception {

public:

    QueueUnderflow() : reason_("Queue Underflow") {}

    [[nodiscard]] const char * what() const override { return reason_; }

private:

    const char * reason_;
};

#endif //ALGORITHMS_2021_QUEUEUNDERFLOW_H

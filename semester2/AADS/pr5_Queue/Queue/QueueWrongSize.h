#ifndef ALGORITHMS_2021_QUEUEWRONGSIZE_H
#define ALGORITHMS_2021_QUEUEWRONGSIZE_H

class QueueWrongSize : public std::exception {

public:

    QueueWrongSize() : reason_("Queue Wrong Size") {}

    [[nodiscard]] const char * what() const override { return reason_; }

private:

    const char * reason_;
};


#endif //ALGORITHMS_2021_QUEUEWRONGSIZE_H

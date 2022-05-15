//
// Created by Foko on 15.05.2022.
//

#include <exception>
#include <string>

class QueueUnderflow: public std::exception {
private:
    std::string msg = "Queue underflow.";
public:
    QueueUnderflow () = default;
    const char * what() const noexcept override {
        return msg.c_str();
    }
};
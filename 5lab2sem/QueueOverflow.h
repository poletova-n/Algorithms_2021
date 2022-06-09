#include <exception>
#include <iostream>
#include <string>

class QueueOverflow : public std::exception
{
public:
    QueueOverflow() : m_error("\nQueue Overflow!\n") {}
    const char* what() const noexcept { return m_error.c_str(); }
private:
    const std::string m_error;
};
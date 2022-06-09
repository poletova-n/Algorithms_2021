#include <exception>
#include <iostream>
#include <string>

class QueueUnderflow : public std::exception
{
public:
    QueueUnderflow() : m_error("\nQueue underflow!\n") {}
    const char* what() const noexcept { return m_error.c_str(); }
private:
    const std::string m_error;
};
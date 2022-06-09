#include <exception>
#include <iostream>
#include <string>

class QueueWrongSize : public std::exception
{
public:
    QueueWrongSize() : m_error("\nQueue wrong size!\n") {}
    const char* what() const noexcept { return m_error.c_str(); }
private:
    const std::string m_error;
};
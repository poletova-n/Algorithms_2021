#ifndef CLASS_STRING
#define CLASS_STRING

#include <iostream>

class String {
public:
    String();
    String(const char* str);
    String(const String& source);
    String(String&& source) noexcept;
    ~String();
    String& operator=(const String& source);
    String& operator=(String&& source) noexcept;
    String& operator+=(const char& extraChar);
    char& operator[](const size_t& index) const;
    friend std::istream& getline(std::istream& in, String& destination);
    int compare(const String& str) const;
    friend std::ostream& operator<< (std::ostream& out, const String& str);
    size_t size() const;
    void swap(String& other);
    operator const char* () const;
private:
    size_t size_;
    size_t capacity_;
    char* pointer_;
};

#endif
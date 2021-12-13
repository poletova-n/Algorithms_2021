#include "String.h"

String::String() {
    capacity_ = 2;
    length_ = 0;
    string_ = new char[capacity_];
}

String::String(const char* string) {
    string_ = strdup(string);
    length_ = strlen(string);
    resize(length_ * 2);
}

String::String(const String& string) : capacity_(string.capacity_), length_(string.length_) {
    string_ = new char[string.capacity_];
    for (int i = 0; i < string.length_; i++) {
        string_[i] = string.string_[i];
    }
}

String::String(String&& string) : capacity_(string.capacity_), length_(string.length_), string_(string.string_) {
    string.capacity_ = 0;
    string.length_ = 0;
    string.string_ = nullptr;
}

String& String::operator=(const String& string)
{
    if (&string == this) {
        return *this;
    }
    length_ = string.length_;
    capacity_ = string.capacity_;
    string_ = new char[string.capacity_];
    for (int i = 0; i < string.length_; i++) {
        string_[i] = string.string_[i];
    }

    return *this;
}

String& String::operator=(String&& string)
{
    length_ = string.length_;
    capacity_ = string.capacity_;
    string_ = string.string_;

    string.capacity_ = 0;
    string.length_ = 0;
    string.string_ = nullptr;
    return *this;
}

String& String::operator+=(const String& string)
{
    if ((length_ + string.length_) >= capacity_) {
        resize((length_ + string.length_) * 2);
    }

    for (int i = 0; i < string.length_; i++) {
        string_[length_] = string.string_[i];
        length_++;
    }
    return *this;
}

String& String::operator+=(const char& ch)
{
    if ((length_ + 1) >= capacity_) {
        resize(capacity_ * 2);
    }
    string_[length_] = ch;
    length_++;
    return *this;
}

bool String::operator==(const String& ch)
{
    if (length_ != ch.length_) {
        return false;
    }

    for (int i = 0; i < length_; i++) {
        if (string_[i] != ch.string_[i]) {
            return false;
        }
    }
    return true;
}

std::ostream& String::operator<<(std::ostream& out)
{
    for (int i = 0; i < this->length_; i++) {
        out << this->string_[i];
    }
    return out;
}

bool String::operator>(const String& str)
{
    return strcmp(this->string_, str.string_) > 0;
}

char& String::operator[](const int index)
{
    return string_[index];
}

void String::resize(int size)
{
    char* arr = new char[size];
    for (int i = 0; i < length_; i++) {
        arr[i] = string_[i];
    }
    string_ = arr;
    capacity_ = size;
}

std::ostream& operator<<(std::ostream& out, const String& string)
{
    for (int i = 0; i < string.length_; i++) {
        out << string.string_[i];
    }
    return out;
}
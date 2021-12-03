#ifndef ALGORITHMS_2021_STRING_H
#define ALGORITHMS_2021_STRING_H

class String {
public:

    String();

    String(const char input[]);

    [[nodiscard]] char* getCharArray() const;

    [[nodiscard]] int length() const;

    void setCharArray(char* charArray);

    void setLength(int length);

    String getInfo();

    char at(int index) const;

    String(const String& input);

    void toString();

    String(String&& input) noexcept;

    ~String() = default;

    int compare(const String& input) const;

    String& operator=(const String& input);

    String& operator+=(char& input);

    String& operator=(String&& input) noexcept;

    friend std::fstream& operator<<(std::fstream& output, String& string);

    friend std::fstream& operator>>(std::fstream& input, String& string);

    friend std::istream& operator>>(std::istream& input, String& string);

    friend std::ostream& operator<<(std::ostream& output, String& string);

private:
    char* _charArray{};
    int _length;
};


#endif //ALGORITHMS_2021_STRING_H
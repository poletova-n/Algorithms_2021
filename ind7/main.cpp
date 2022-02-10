#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <string>

#ifndef CLASS_STRING
#define CLASS_STRING
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


#ifndef BANKCARD_H
#define BANKCARD_H
#include <string>
class BankCard {
private:
    std::string name_;
    std::string surname_;
    std::string num_;
    std::string date_;
public:
    BankCard() = default;
    BankCard(const std::string& name, const std::string& surname, const std::string& num, const std::string& date);
    BankCard(const BankCard& bc) = default;
    ~BankCard() = default;
    std::string getName() const;
    std::string getSurname() const;
    std::string getNum() const;
    std::string getDate() const;
};
std::ostream& operator<< (std::ostream& stream, const BankCard& bc);
#endif



#ifndef FUNCS_H
#define FUNCS_H
void sortByName(BankCard* cards, int N);
void sortByNum(BankCard* cards, int N);
void sortByDate(BankCard* cards, int N);
int countSurname(const BankCard* cards, int N);
bool isEqualSurnamesAndNames(const BankCard* cards, int N);
#endif
BankCard::BankCard(const std::string& name, const std::string& surname, const std::string& num, const std::string& date) :
        name_(name), num_(num), date_(date), surname_(surname) {};
std::string BankCard::getName() const {
    return name_;
}
std::string BankCard::getSurname() const {
    return surname_;
}
std::string BankCard::getNum() const {
    return num_;
}
std::string BankCard::getDate() const {
    return date_;
}
std::ostream& operator<< (std::ostream& stream, const BankCard& bc) {
    return stream << bc.getName() << " " << bc.getSurname() << "\n" << bc.getNum() << "\n" << bc.getDate();
}


int main() {
    std::string file1;
    std::cout << "Enter source file name:\n";
    std::cin >> file1;
    std::ifstream file(file1);
    if (file.is_open()) {
        int n = 0;

        std::string n_s;
        std::getline(file, n_s);
        n = stoi(n_s);
        BankCard* cards = new BankCard[n];
        for (int i = 0; i < n; i++) {
            std::string name, num, date;
            std::getline(file, name);
            std::getline(file, num);
            std::getline(file, date);
            int j = name.find_first_of(' ');
            cards[i] = BankCard(name.substr(j + 1, name.length()),
                                name.substr(0, j), num, date);
        }
        for (int i = 0; i < n; i++) {
            std::cout << cards[i] << "\n";
        }
        std::string file2;
        std::cout << "Enter output file name:\n";
        std::cin >> file2;
        std::ofstream fout(file2);
        sortByNum(cards, n);
        std::cout << "==============================================\n";
        for (int i = 0; i < n; i++) {
            fout << cards[i] << "\n";
        }
        fout << "Number of different surnames " << countSurname(cards, n) << "\n";
        fout << "Equal names and surnames?: "
             << (isEqualSurnamesAndNames(cards, n) ? "Yes" : "No") << "\n";
        int ccount=0;
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                if (cards[i].getSurname() == cards[j].getSurname() &&
                    cards[i].getName() == cards[j].getName())
                {
                    ccount +=2;
                    fout << cards[i] << "\n" << cards[j] << "\n";
                }
        fout<<"number of equals "<< ccount <<"\n";
        fout.close();
        if (!fout) {
            std::cerr << "output file error\n";
        }
        file.close();
        if (!file) {
            std::cerr << "source file error\n";
        }
    }
    else {
        std::cerr << "can not open the file.\n";
    }
}

void sortByName(BankCard* cards, int N) {
    for (int i = 1; i < N; i++)
    {
        int minPosition = i;
        std::string tmp;
        for (int j = i+1; j < N; j++)
            minPosition = i;
        for (int j = i + 1; j < N; j++)
            if (cards[minPosition].getName() > cards[j].getName())
                minPosition = j;
        tmp = cards[minPosition].getName();
        cards[minPosition].getName() = cards[i].getName();
        cards[i].getName() = tmp;
    }
}
void sortByNum(BankCard* cards, int N) {
    for (int i = 1; i < N; i++)
    {
        int minPosition = i;
        std::string tmp;
        for (int j = i+1; j < N; j++)
            minPosition = i;
        for (int j = i + 1; j < N; j++)
            if (cards[minPosition].getNum() > cards[j].getNum())
                minPosition = j;
        tmp = cards[minPosition].getNum();
        cards[minPosition].getNum() = cards[i].getNum();
        cards[i].getNum() = tmp;
    }
}
void sortByDate(BankCard* cards, int N) {
    for (int i = 1; i < N; i++)
    {
        int minPosition = i;
        std::string tmp;
        for (int j = i+1; j < N; j++)
            minPosition = i;
        for (int j = i + 1; j < N; j++)
            if (cards[j - 1].getDate().substr(3, 2) > cards[j].getDate().substr(3, 2))
                minPosition = j;
        tmp = cards[minPosition].getDate().substr(3, 2);
        cards[minPosition].getDate().substr(3, 2) = cards[i].getDate().substr(3, 2);
        cards[i].getDate().substr(3, 2) = tmp;
    }
    for (int i = 1; i < N; i++)
    {
        int minPosition = i;
        std::string tmp;
        for (int j = i+1; j < N; j++)
            minPosition = i;
        for (int j = i + 1; j < N; j++)
            if (cards[j - 1].getDate().substr(0, 2) > cards[j].getDate().substr(0, 2)
                && cards[j - 1].getDate().substr(3, 2) == cards[j].getDate().substr(3, 2))
                minPosition = j;
        tmp = cards[minPosition].getDate().substr(3, 2);
        cards[minPosition].getDate().substr(3, 2) = cards[i].getDate().substr(3, 2);
        cards[i].getDate().substr(3, 2) = tmp;
    }
}
int countSurname(const BankCard* cards, int N) {
    int count = N;
    for (int i = 0; i < N; i++)
        for (int j = i+1; j < N; j++)
            if (cards[i].getSurname() == cards[j].getSurname())
                count-=1;
    return count;
}
bool isEqualSurnamesAndNames(const BankCard* cards, int N) {

    bool flag = false;
    for (int i = 0; i < N && !flag; i++)
        for (int j = i+1; j < N && !flag; j++)
            if (cards[i].getSurname() == cards[j].getSurname() &&
                cards[i].getName() == cards[j].getName())
                flag = true;
    return flag;
}
String::String() :
        size_(0),
        capacity_(size_ + 1),
        pointer_(new char[capacity_])
{}
String::String(const char* str)
{
    size_ = 0;
    while (str[size_] != '\0') {
        ++size_;
    }
    capacity_ = size_ + 1;
    pointer_ = new char[capacity_];

    for (unsigned int i = 0; i < capacity_; ++i) {
        pointer_[i] = str[i];
    }
}

String::String(const String& source) :
        size_(source.size_),
        capacity_(size_ + 1),
        pointer_(new char[capacity_])
{
    strcpy_s(pointer_, capacity_, source.pointer_);
}

String::String(String&& source) noexcept :
        pointer_(source.pointer_),
        size_(source.size_),
        capacity_(source.capacity_)
{
    source.pointer_ = nullptr;
    source.size_ = 0;
    source.capacity_ = 0;
}

String::~String()
{
    delete[] pointer_;
}

String& String::operator=(const String& source)
{
    if (this != &source)
    {
        String temp(source);
        swap(temp);
    }
    return *this;
}

String& String::operator=(String&& source) noexcept
{
    if (this != &source)
    {
        swap(source);
    }
    return *this;
}

String& String::operator+=(const char& extraChar)
{
    String temp;
    temp.size_ = size_ + 1;
    temp.capacity_ = capacity_ + 1;
    temp.pointer_ = new char[temp.capacity_];
    if (capacity_ > 1) {
        strcpy_s(temp.pointer_, capacity_, pointer_);
    }
    temp.pointer_[temp.capacity_ - 2] = extraChar;
    temp.pointer_[temp.capacity_ - 1] = '\0';

    swap(temp);

    return *this;
}

int String::compare(const String& str) const
{
    for (unsigned int i = 0; i < (size_ < str.size_ ? size_ : str.size_); i++) {
        if (pointer_[i] > str[i]) {
            return 1;
        }
        else if (pointer_[i] < str[i]) {
            return -1;
        }
    }

    if (size_ < str.size_) {
        return -1;
    }
    else if (size_ > str.size_) {
        return 1;
    }


    return 0;
}

char& String::operator[](const size_t& index) const
{
    if (index >= size_) {
        throw std::out_of_range("IndexError: String index out of range");
    }
    return pointer_[index];
}

size_t String::size() const
{
    return size_;
}

void String::swap(String& other)
{
    std::swap(pointer_, other.pointer_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
}

String::operator const char* () const
{
    return pointer_;
}

std::istream& getline(std::istream& in, String& destination)
{
    destination = String();
    bool isSomethingIn = false;
    char ch = 1;
    while (ch != '\n' && ch != '\0' && (ch = in.get()) != EOF)
    {
        isSomethingIn = true;
        if (ch == '\n')
        {
            //destination += '\0';
            break;
        }
        else {
            destination += ch;
        }
    }

    if (!isSomethingIn) {
        destination = " ";
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const String& str)
{
    out << str.pointer_;
    return out;
}

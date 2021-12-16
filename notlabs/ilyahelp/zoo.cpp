#include <iostream>
#include <fstream>
#include <string>



const char* ERROR_FILE_OPEN = "Ошибка в открытии файла! FO";
const char* ERROR_NAME = "В ФИО допустимо максимум 2 пробела! PP";
const char* ERROR_NAME1 = "ФИО указано не с заглавных букв! N1";
const char* ERROR_NAME2 = "ФИО должно содержать только русские буквы! RR";
const char* ERROR_NAME3 = "В ФИО присутствуют лишнии заглавные буквы! FZ";
const char* ERROR_NUMBER_CARD = "В номере карте должны быть только числа! CH";
const char* ERROR_NUMBER_CARD1 = "Номер карты должен содержать в себе 16 чисел! CHK";
const char* ERROR_VALID_CARD = "Срок годности не должен содержать буквы! SG";
const char* ERROR_VALID_CARD1 = "Срок годности должен содержать 5 символов! SG5";

class MyString
{
private:
    char* str_;
public:
    MyString() {
        str_ = new char;
    }

    MyString(const char* str) {
        int size = strlen(str);
        str_ = new char[size + 1];
        for (int i = 0; i < size; ++i) {
            str_[i] = str[i];
        }
        str_[size] = '\0';
    }

    MyString(const MyString& one) {
        int newSize = strlen(one.str_);
        delete str_;
        str_ = new char[newSize + 1];
        for (int i = 0; i < newSize; i++)
        {
            str_[i] = one.str_[i];
        }
        str_[newSize] = '\0';
    }

    MyString& operator = (const MyString& other) {
        if (this != &other) {
            if (str_ != nullptr) {
                delete str_;
            }

            int newSize = strlen(other.str_);
            str_ = new char[newSize + 1];
            for (int i = 0; i < newSize; i++)
            {
                str_[i] = other.str_[i];
            }
            str_[newSize] = '\0';
        }
        return *this;
    }

    ~MyString() = default;

    char* getStr_() { return str_; }
    bool compareTo(MyString& other);
    friend std::ostream& operator << (std::ostream& out, const MyString& one);
};

bool MyString::compareTo(MyString& other) {
    bool check = true;
    for (int i = 0; i < strlen(str_); i++) {
        if (str_[i] != other.str_[i]) {
            check = false;
            break;
        }
    }
    return check;
}

std::ostream& operator << (std::ostream& out, const MyString& one) {
    out << one.str_;
    return out;
}


class BankCard
{
private:
    int position_name;
    int position_numberCard;
    int position_validity;
    MyString* Name;
    MyString* NumberCard;
    MyString* Valid;
public:
    BankCard() :position_name(0), position_numberCard(0), position_validity(0) {
        Name = new MyString; NumberCard = new MyString; Valid = new MyString;
    }



    BankCard(const BankCard& other) {
        position_name = other.position_name;
        position_numberCard = other.position_numberCard;
        position_validity = other.position_validity;

        int lengthName = strlen(other.Name->getStr_());
        delete Name;
        MyString* Name = new MyString;
        for (int i = 0; i < lengthName; i++) {
            Name->getStr_()[i] = other.Name->getStr_()[i];
        } Name->getStr_()[lengthName] = '\0';

        int lengthNumberCard = strlen(other.NumberCard->getStr_());
        delete NumberCard;
        MyString* masNumberCard = new MyString;
        for (int i = 0; i < lengthNumberCard; i++) {
            NumberCard->getStr_()[i] = other.NumberCard->getStr_()[i];
        } NumberCard->getStr_()[lengthNumberCard] = '\0';

        int lengthValid = strlen(other.Valid->getStr_());
        delete Valid;
        MyString* Valid = new MyString;
        for (int i = 0; i < lengthValid; i++) {
            Valid->getStr_()[i] = other.Valid->getStr_()[i];
        } Valid->getStr_()[lengthValid] = '\0';
    }


    void findWord(MyString& str) {
        int length = strlen(str.getStr_());
        int cntSpace = 0;  // подсчёт пробелов
        int cntCapsLetter = 0;  // подсчёт заглавных букв в ФИО
        int startName = position_name;

        if ((str.getStr_()[position_name] < 'A') or
            (str.getStr_()[position_name]) > 'Z') {
            std::cout << str.getStr_()[position_name];
            throw ERROR_NAME1; // проверка 1 заглавной буквы в имени
        }

        for (int i = 0; i < length; ++i) {
            if (str.getStr_()[position_name] != '\n') {
                /*if (((str.getStr_()[position_name] >= 'a') and (str.getStr_()[position_name]) <= 'z') or
                    ((str.getStr_()[position_name] >= 'A') and (str.getStr_()[position_name]) <= 'Z')) {
                    throw ERROR_NAME2; // проверка на английские буквы
                }*/

                if (((str.getStr_()[position_name] >= 'A')) and ((str.getStr_()[position_name]) <= 'Z')) { // подсчёт заглавных букв
                    cntCapsLetter++;
                }

                if (str.getStr_()[position_name] == ' ') { // проверка на заглавную букву
                    if ((str.getStr_()[position_name + 1] < 'A') or
                        (str.getStr_()[position_name + 1] > 'Z')) throw ERROR_NAME1;
                    cntSpace++;
                }
                position_name++;
                Name->getStr_()[i] = str.getStr_()[i];
            }
            else {
                position_numberCard = ++position_name;
                position_name = startName;
                Name->getStr_()[i] = '\0';
                break;
            }
        }
        if (cntSpace != 2)      throw ERROR_NAME;
        if (cntCapsLetter != 3) throw ERROR_NAME3;


        int startNumberCard = position_numberCard;
        int cntNumber = 0; // для проверки 16 чисел
        bool isNumber = true; // для проверки, что введена не буква
        for (int i = 0; i < length; ++i) {
            if (str.getStr_()[position_numberCard] != '\n') {
                if ((str.getStr_()[position_numberCard] >= '0') and (str.getStr_()[position_numberCard] <= '9')) {
                    cntNumber++;
                    NumberCard->getStr_()[i] = str.getStr_()[position_numberCard++];
                }
                else if (str.getStr_()[position_numberCard] == ' ') {
                    NumberCard->getStr_()[i] = str.getStr_()[position_numberCard++];
                }
                else {
                    isNumber = false;
                    if (isNumber == false) throw ERROR_NUMBER_CARD;
                }
            }
            else {
                position_validity = ++position_numberCard;
                position_numberCard = startNumberCard;
                NumberCard->getStr_()[i] = '\0';
                break;
            }
        } if (cntNumber != 16) throw ERROR_NUMBER_CARD1;


        isNumber = true;
        int cntSymbols = 0;
        int startValid = position_validity;

        for (int i = 0; i < length; ++i) {
            if (str.getStr_()[position_validity] != '\0') {
                if (cntSymbols == 5) {
                    Valid->getStr_()[i] = '\0';
                    break;
                }
                if ((str.getStr_()[position_validity] >= '0') and (str.getStr_()[position_validity] <= '9')) {
                    cntSymbols++;
                    Valid->getStr_()[i] = str.getStr_()[position_validity++];
                }
                else if (str.getStr_()[position_validity] == '/') {
                    Valid->getStr_()[i] = str.getStr_()[position_validity++];
                    cntSymbols++;
                }
                else {
                    isNumber = false;
                    if (isNumber == false) throw ERROR_VALID_CARD; // если в сроке годности есть буква
                }
            }
            else {
                Valid->getStr_()[i] = '\0';
                break;
            }
        } if (cntSymbols != 5) throw ERROR_VALID_CARD1; // если символов в сроке годности не 5
    }

    MyString* getName() { return Name; }
    MyString* getNumberCard() { return NumberCard; }
    MyString* getValid() { return Valid; }

    ~BankCard() = default;
};


int main()
{
    setlocale(LC_ALL, "Russian");

    std::ifstream file;
    file.open("BankCards.txt");

    try {
        if (!file.is_open()) throw ERROR_FILE_OPEN;
    }
    catch (const std::string& ex)
    {
        file.close();
        std::cerr << ex << std::endl;
    }

    try
    {
        const int cntCards = 1;
        char* word = new char[256];
        int iterator = 0;
        while (!file.eof()) {
            word[iterator++] = file.get();
        } word[--iterator] = NULL;
        word[iterator] = '\0';
        MyString MainWord(word);
        int positionWords = 0;
        int cntStr = 0;

        BankCard* BankCards = new BankCard[cntCards];
        MyString* Words = new MyString[cntCards];

        for (int i = 0; i < cntCards; ++i) {
            for (int j = 0; j < strlen(word); ++j) {
                if (MainWord.getStr_()[positionWords] == '\0') {
                    Words[i].getStr_()[j] = '\0';
                    break;
                }
                if (cntStr == 3) {
                    Words[i].getStr_()[j - 1] = '\0';
                    break;
                }
                if (MainWord.getStr_()[positionWords] == '\n') {
                    cntStr++;
                    Words[i].getStr_()[j] = MainWord.getStr_()[positionWords++];
                    continue;
                }
                Words[i].getStr_()[j] = MainWord.getStr_()[positionWords++];
            }
            cntStr = 0;
            BankCards[i].findWord(Words[i]);
        }

        delete[] word;
        delete[] BankCards;
        delete[] Words;
    }
    catch (const char* ex)
    {
        std::cerr << ex;
    }

    return 0;
}
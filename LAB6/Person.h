#ifndef ALGORITHMS_2021_SUBSCRIBER_H
#define ALGORITHMS_2021_SUBSCRIBER_H
#include "String.h"

class Person {

public:

    class Folder {
    public:

        Folder() = default;

        void setInfo(String info);

        const String getInfo() const;

        virtual int compare(Folder folder);

        friend std::fstream& operator>>(std::fstream& input, Folder& folder);

        friend std::fstream& operator<<(std::fstream& input, Folder& folder);

        virtual bool isPatternCorrect(String& string);

        virtual void printError();

    private:
        String _info;

        const char* ERROR_PATTERN_NOT_CORRECT = "Error:";
    };

    class YearNumberFolder : public Folder {
    public:

        bool isPatternCorrect(String& string) override;

        void printError() override;

    private:
        const char* ERROR_PATTERN_NOT_CORRECT = "Error: year number not correct.";
    };

    class FirstNameFolder : public Folder {
    public:

        bool isPatternCorrect(String& string) override;

        void printError() override;

    private:
        const char* ERROR_PATTERN_NOT_CORRECT = "Error: first name not correct.";
    };

    class SecondNameFolder : public Folder {
    public:

        bool isPatternCorrect(String& string) override;

        void printError() override;

    private:
        const char* ERROR_PATTERN_NOT_CORRECT = "Error: second name not correct.";
    };

    Person() = default;

    [[nodiscard]] const FirstNameFolder& getFirstName() const;

    [[nodiscard]] const SecondNameFolder& getSecondName() const;

    [[nodiscard]] const YearNumberFolder getYear() const;

    friend std::fstream& operator<<(std::fstream& output, Person& subscriber);

    friend std::fstream& operator>>(std::fstream& input, Person& subscriber);

    friend bool operator>(Person& subscriber, Person& anotherSubscriber);

private:

    FirstNameFolder _firstName;
    SecondNameFolder _secondName;
    YearNumberFolder _year;

};

#endif //ALGORITHMS_2021_SUBSCRIBER_H
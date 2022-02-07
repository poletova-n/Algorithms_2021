#ifndef ALGORITHMS_2021_SUBSCRIBER_H
#define ALGORITHMS_2021_SUBSCRIBER_H

class Subscriber {

public:

    class Folder{
    public:

        Folder() = default;

        void setInfo(std::string info);

        [[nodiscard]] std::string getInfo() const;

        virtual int compare(Folder folder);

        friend std::fstream& operator>>(std::fstream& input, Folder &folder);

        friend std::fstream& operator<<(std::fstream& input, Folder &folder);

        virtual bool isPatternCorrect(std::string &string);

        virtual void printError();

    private:
        std::string _info;

        const char * ERROR_PATTERN_NOT_CORRECT = "Error:";
    };

    class PhoneNumberFolder : public Folder {
    public:

        bool isPatternCorrect(std::string &string) override;

        void printError() override;

    private:
        const char * ERROR_PATTERN_NOT_CORRECT = "Error: phone number not correct.";
    };

    class TariffCodeFolder: public Folder{
    public:

        bool isPatternCorrect(std::string &string) override;

        int compare(Folder folder) override;

        void printError() override;

    private:
        const char * ERROR_PATTERN_NOT_CORRECT = "Error: traffic code not correct.";
    };

    class FirstNameFolder: public Folder{
    public:

        bool isPatternCorrect(std::string &string) override;

        void printError() override;

    private:
        const char * ERROR_PATTERN_NOT_CORRECT = "Error: first name not correct.";
    };

    class SecondNameFolder: public Folder{
    public:

        bool isPatternCorrect(std::string &string) override;

        void printError() override;

    private:
        const char * ERROR_PATTERN_NOT_CORRECT = "Error: second name not correct.";
    };

    Subscriber() = default;

    [[nodiscard]] const FirstNameFolder &getFirstName() const;

    [[nodiscard]] const SecondNameFolder &getSecondName() const;

    [[nodiscard]] const PhoneNumberFolder &getPhone() const;

    [[nodiscard]] const TariffCodeFolder &getCode() const;

    friend std::fstream& operator<<(std::fstream& output, Subscriber &subscriber);

    friend std::fstream& operator>>(std::fstream& input, Subscriber &subscriber);

    friend bool operator>(Subscriber &subscriber, Subscriber &anotherSubscriber);

private:

    FirstNameFolder _firstName;
    SecondNameFolder _secondName;
    PhoneNumberFolder _phone;
    TariffCodeFolder _code;

};


#endif //ALGORITHMS_2021_SUBSCRIBER_H

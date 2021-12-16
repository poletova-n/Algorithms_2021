#ifndef ALGORITHMS_2021_SUBSCRIBER_H
#define ALGORITHMS_2021_SUBSCRIBER_H

class Subscriber {

public:



    Subscriber() = default;

    Subscriber(const std::string &firstName, const std::string &secondName, const std::string &phone,
               const std::string &code);


    [[nodiscard]] const std::string &getFirstName() const;

    [[nodiscard]] const std::string &getSecondName() const;

    [[nodiscard]] const std::string &getPhone() const;

    [[nodiscard]] const std::string &getCode() const;

    void setFirstName(const std::string &firstName);

    void setSecondName(const std::string &secondName);

    void setPhone(const std::string &phone);

    void setCode(const std::string &code);



    bool isFirstNameCorrect(const std::string &string);

    bool isSecondNameCorrect(const std::string &string);

    bool isCodeCorrect(const std::string &string);

    bool isPhoneCorrect(const std::string &string);



    friend std::fstream& operator<<(std::fstream& output, Subscriber &subscriber);

    friend std::fstream& operator>>(std::fstream& input, Subscriber &subscriber);

    friend bool operator>(Subscriber &subscriber, Subscriber &anotherSubscriber);

private:

    std::string _firstName;
    std::string _secondName;
    std::string _phone;
    std::string _code;

    const char* INVALID_FIRST_NAME = "Invalid first name.";
    const char* INVALID_SECOND_NAME = "Invalid second name.";
    const char* INVALID_PHONE = "Invalid phone.";
    const char* INVALID_CODE = "Invalid traffic code.";

};


#endif //ALGORITHMS_2021_SUBSCRIBER_H

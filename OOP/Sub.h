#ifndef SUB_H
#define SUB_H

class Sub {

public:


    Sub() = default;


    Sub(const std::string& firstName, const std::string& secondName, const std::string& phone,
        const std::string& code);


    const std::string& getFirstName() const;

    const std::string& getSecondName() const;

    const std::string& getPhone() const;

    const std::string& getCode() const;

    void setFirstName(const std::string& firstName);

    void setSecondName(const std::string& secondName);

    void setPhone(const std::string& phone);

    void setCode(const std::string& code);



    bool isFirstNameCorrect(const std::string& string);

    bool isSecondNameCorrect(const std::string& string);

    bool isCodeCorrect(const std::string& string);

    bool isPhoneCorrect(const std::string& string);



    friend std::fstream& operator<<(std::fstream& output, Sub& subscriber);

    friend std::fstream& operator>>(std::fstream& input, Sub& subscriber);

    friend bool operator>(Sub& subscriber, Sub& anotherSubscriber);


    ~Sub() = default;

private:

    std::string _firstName;
    std::string _secondName;
    std::string _phone;
    std::string _code;

    const char* INVALID_FIRST_NAME = "Error - Invalid first name.";
    const char* INVALID_SECOND_NAME = "Error - Invalid second name.";
    const char* INVALID_PHONE = "Error -Invalid phone.";
    const char* INVALID_CODE = "Error -Invalid traffic code.";

};


#endif //SUB_H
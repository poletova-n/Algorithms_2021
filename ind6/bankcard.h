#include "strings.h"

class BankCard {
public: // TODO: сделать private
	String CardholderName;
	String CardholderSurname;
	String CardNumber;
	String CardExpireMonth;
	String CardExpireYear;
	[[maybe_unused]] int BankType;
public:
	explicit BankCard (char* source_str);
	// TODO: функцию проверки валидности длина имени, фамилии, номера карты и дат).
	~BankCard () = default;
	friend bool compare_order(BankCard& card1, BankCard& card2);
};

#include "utils.cpp"
#include "bankcard.cpp"
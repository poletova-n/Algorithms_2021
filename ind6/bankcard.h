#include "utils.cpp"
#include "string.h"


class BankCard {
public: // TODO: сделать private
	String CardholderName;
	String CardholderSurname;
	String CardNumber;
	String CardExpireMonth;
	String CardExpireYear;
	int    BankType;
public:
	explicit BankCard (char* source_str) {
		isSpaces(source_str);

		char* pos = source_str;
		if (isWord(source_str)) {
			this->CardholderSurname = std::move(strcopy(pos, source_str - pos));
		} else {
			throw "WRONG PATTERN: NO CARDHOLDER SURNAME.";
		}

		isSpaces(source_str);
		pos = source_str;
		if (isWord(source_str)) {
			this->CardholderName = std::move(strcopy(pos, source_str - pos));
		} else {
			throw "WRONG PATTERN: NO CARDHOLDER NAME.";
		}

		isSpaces(source_str);
		pos = source_str;
		if (isNumber(source_str)) {
			this->CardNumber = std::move(strcopy(pos, source_str - pos));
		} else {
			throw "WRONG PATTERN: NO CARD NUMBER.";
		}

		isSpaces(source_str);
		pos = source_str;
		if (isNumber(source_str)) {
			this->CardExpireMonth = std::move(strcopy(pos, source_str - pos));
		} else {
			throw "WRONG PATTERN: NO CARD EXPIRE MONTH.";
		}
		if (isSlash(source_str)) {
			throw "WRONG PATTERN: MISSED SLASH.";
		}

		pos = source_str;
		if (isNumber(source_str)) {
			this->CardExpireYear = std::move(strcopy(pos, source_str - pos));
		} else {
			throw "WRONG PATTERN: NO CARD EXPIRE YEAR.";
		}

		if (*source_str != '\0') {
			throw "WRONG PATTERN.";
		}

		this->BankType = this->CardNumber[0] ^ 0x30;
	}

	~BankCard () {
		;
	}

	friend bool compare_order(BankCard& card1, BankCard& card2);
};

bool compare_order(BankCard& card1, BankCard& card2) {

}
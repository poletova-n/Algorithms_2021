//
// Created by reenie on 06.12.2021.
//

#include "utils.cpp"


class BankCard {
public: // TODO: сделать private
	String CardholderName;
	String CardholderSurname;
	String CardNumber;
	String CardExpireDate;
	int    BankType;



public:
	explicit BankCard (char* source_str) {
		isSpaces(source_str);

		char* pos = source_str;
		isWord(source_str);
		this->CardholderSurname = strcopy(pos, source_str - pos);

		isSpaces(source_str);
		pos = source_str;
		isWord(source_str);
		this->CardholderName = strcopy(pos, source_str - pos);

		isSpaces(source_str);
		pos = source_str;
		isNumber(source_str);
		this->CardNumber = strcopy(pos, source_str - pos);

		isSpaces(source_str);
		pos = source_str;
		isDate(source_str);
		this->CardExpireDate = strcopy(pos, source_str - pos);

		isSpaces(source_str);

		if (*source_str != '\0') {
			throw "WRONG PATTERN";
		}

		this->BankType = this->CardNumber[0] ^ 0x30;
	}

	~BankCard () {
		;
	}
};


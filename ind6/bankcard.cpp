#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-exception-baseclass"
BankCard::BankCard (char* source_str) {
	isSpaces(source_str);

	char* pos = source_str;
	if (isWord(source_str)) {
		this->CardholderSurname = (String) strcopy(pos, source_str - pos);
	} else {
		throw "WRONG PATTERN: NO CARDHOLDER SURNAME.";
	}

	isSpaces(source_str);
	pos = source_str;
	if (isWord(source_str)) {
		this->CardholderName = (String) strcopy(pos, source_str - pos);
	} else {
		throw "WRONG PATTERN: NO CARDHOLDER NAME.";
	}

	isSpaces(source_str);
	pos = source_str;
	if (isNumber(source_str)) {
		this->CardNumber = (String)strcopy(pos, source_str - pos);
	} else {
		throw "WRONG PATTERN: NO CARD NUMBER.";
	}

	isSpaces(source_str);
	pos = source_str;
	if (isNumber(source_str)) {
		this->CardExpireMonth = (String) strcopy(pos, source_str - pos);
	} else {
		throw "WRONG PATTERN: NO CARD EXPIRE MONTH.";
	}
	if (!isSlash(source_str)) {
		throw "WRONG PATTERN: MISSED SLASH.";
	}

	pos = source_str;
	if (isNumber(source_str)) {
		this->CardExpireYear = (String) strcopy(pos, source_str - pos);
	} else {
		throw "WRONG PATTERN: NO CARD EXPIRE YEAR.";
	}

	isSpaces(source_str);

	if (*source_str != '\0') {
		throw "WRONG PATTERN.";
	}

	this->BankType = this->CardNumber[0] ^ 0x30;
}

bool compare_order(BankCard& card1, BankCard& card2) {
	int pos = card1.CardholderSurname.compare(card2.CardholderSurname);
	if (pos < 0) { // сравнение для фамилии
		return true;
	} else if (pos > 0) {
		return false;
	} else {
		pos = card1.CardholderName.compare(card2.CardholderName);
		if (pos < 0) { // сравнение для имени
			return true;
		} else if (pos > 0) {
			return false;
		} else {
			pos = card1.CardExpireYear.compare(card2.CardExpireYear);
			if (pos < 0) { // сравнение для даты (по году)
				return true;
			} else if (pos > 0) {
				return false;
			} else {
				pos = card1.CardExpireMonth.compare(card2.CardExpireMonth);
				if (pos < 0) { // сравнение для даты (по месяцу)
					return true;
				} else if (pos > 0) {
					return false;
				} else {
					pos = card1.CardNumber.compare(card2.CardNumber);
					if (pos < 0) { // сравнение по номеру карты
						return true;
					} else {
						return false; // при полном совпадении ничего не меняется.
					}
				}
			}
		}
	}
}
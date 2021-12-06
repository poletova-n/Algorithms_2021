char* strcopy(char*& str, size_t length) {
	char* temp = new char[length];
	for (size_t i = 0; i < length; i++) {
		temp[i] = str[i];
	}
	temp[length] = '\0';
	return temp;
}

bool isSpace(char*& str) {
	if (*str == ' ') {
		str++;
		return true;
	} else {
		return false;
	}
}

bool isSpaces(char*& str) {
	if (isSpace(str)) {
		isSpaces(str);
		return true;
	} else {
		return true;
	}
}

bool isLetter (char*& str) {
	if (('a' <= *str && *str <= 'z') || ('A' <= *str && *str <= 'Z')) {
		str++;
		return true;
	} else {
		return false;
	}
}

bool isWord (char*& str) {
	if (isLetter(str)) {
		isWord(str);
		return true;
	} else {
		return false;
	}
}

bool isDigit(char*& str) {
	if ('0' <= *str && *str <= '9') {
		str++;
		return true;
	} else {
		return false;
	}
}

bool isNumber (char*& str) {
	if (isDigit(str)) {
		isNumber(str);
		return true;
	} else {
		return false;
	}
}

bool isDate(char*& str) {
	if (isDigit(str) && isDigit(str)) {
		if (*str == '/') {
			str++;
			if (isDigit(str) && isDigit(str)) {
				return true;
			} else {
				return false;
			}
		} else {
			return false;
		}
	} else {
		return false;
	}
}
String::String() { // конструктор по умолчанию
	this->_raw_string = new char;
	*(this->_raw_string) = '\0';
	this->length = 0;
}

String::String (const char* str) { // конструктор по умолчанию от char*
	if (str == nullptr) {
		return;
	}

	size_t i = 0;
	while (str[i] != '\0') { // поиск длины строки
		i++;
	}

	this->_raw_string = new char[i]; // выделение памяти на строку
	for (size_t j = 0; j < i; j++) {
		this->_raw_string[j] = str[j]; // поэлементное копирование
	}
	this->_raw_string[i] = '\0'; // терминальный символ в конце

	this->length = i; // запись длины
}

String::String (const String& str) { // конструктор копирования
	this->_raw_string = new char[str.length];
	for (size_t i = 0; i < str.length; i++) {
		this->_raw_string[i] = str._raw_string[i];
	}
	this->_raw_string[str.length] = '\0';
	this->length = str.length;
}

String::String(String &&str) noexcept { // конструктор перемещения
	if (this == &str) {
		return;
	} else {
		this->_raw_string = str._raw_string;
		this->length = str.length;
		str._raw_string = nullptr;
		str.length = 0;
	}
}

String::~String () { // деструктор
	delete[] this->_raw_string;
}

char& String::operator[] (size_t index) {
	return this->_raw_string[index]; // добавить проверку индексов?
}

int32_t String::compare (String& str) {
	size_t i = 0;
	while ((i < this->length) && (i < str.length)) {
		if ((*this)[i] < str[i]) {
			return -1;
		} else if ((*this)[i] > str[i]) {
			return  1;
		} else {
			i++;
		}
	}
	if (this->length < str.length) {
		return -1;
	} else if (this->length > str.length) {
		return  1;
	} else {
		return 0;
	}
}

std::ostream& operator<< (std::ostream& out, const String& str) {
	out << str._raw_string;
	return out;
}

String& String::operator=(const String& str) { // оператор присваивания копированием
	if (this == &str) {
		return *this;
	} else {
		delete[] this->_raw_string;
		this->_raw_string = new char[str.length];
		for (size_t i = 0; i < str.length; i++) {
			(*this)._raw_string[i] = str._raw_string[i];
		}
		(*this)[str.length] = '\0';
		this->length = str.length;
		return *this;
	}
}

String& String::operator=(String&& str) noexcept { // оператор присваивания перемещением
	if (this == &str) {
		return *this;
	} else {
		delete[] this->_raw_string;
		this->_raw_string = str._raw_string;
		this->length = str.length;

		str._raw_string = nullptr;
		str.length = 0;
		return *this;
	}
}
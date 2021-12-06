String::String() { // конструктор по умолчанию
	this->_raw_string = new char;
	*(this->_raw_string) = '\0';
	this->length = 0;
}

String::String (const char* str) { // конструктор по умолчанию от char*

	size_t i = 0;

	if (str != nullptr) {
		std::cout << "New String obj at " << this << " of \"" << str << "\" in init constructor\n";
		while (str[i] != '\0') { // поиск длины строки
			i++;
		}
	} else {
		std::cout << "New String obj at " << this << " of NULL in init constructor\n";
	}

	this->_raw_string = new char[i]; // выделение памяти на строку
	for (size_t j = 0; j < i; j++) {
		this->_raw_string[j] = str[j]; // поэлементное копирование
	}
	this->_raw_string[i] = '\0'; // терминальный символ в конце

	this->length = i; // запись длины
}

String::String (const String& str) { // конструктор копирования
	std::cout << "New String obj at " << this << " of \"" << str << "\" in copy constructor\n";
	this->_raw_string = new char[str.length];
	for (size_t i = 0; i < str.length; i++) {
		this->_raw_string[i] = str._raw_string[i];
	}
	this->_raw_string[str.length] = '\0';
	this->length = str.length;
}

String::String(String &&str) noexcept { // конструктор перемещения
	std::cout << "New String obj at " << this << " of \"" << str << "\" in move constructor\n";
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
	if (this->_raw_string != nullptr)
		std::cout << "String of \"" << this->_raw_string << "\" destructor. " << this << "\n";
	else
		std::cout << "String of \"NULL\" destructor. " << this << "\n";
	delete[] this->_raw_string;
}

char& String::operator[] (size_t index) {
	return this->_raw_string[index];
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
	std::cout << "operator<< with str \"";
	printf("%s", str._raw_string);
	std::cout << "\" at " << &str << "\n";
	return out;
}

String& String::operator=(const String& str) { // оператор присваивания копированием
	std::cout << "temporary obj str in operator=copy overload at " << &str << " of:\n\t" << str << "\n";
	std::cout << "new obj this in operator=copy overload at " << this << " of:\n\t" << *this << "\n";
	if (this == &str) {
		return *this;
	} else {
		delete[] this->_raw_string;
		this->_raw_string = new char[str.length];
		for (size_t i = 0; i < str.length; i++) {
			(*this)[i] = str._raw_string[i];
		}
		(*this)[str.length] = '\0';
		this->length = str.length;
		return *this;
	}
}

String& String::operator=(String&& str) noexcept { // оператор присваивания перемещением
	std::cout << "temporary obj str in operator=move overload at " << &str << " of:\n\t" << str;
	std::cout << "new obj this in operator=move overload at " << this << " of:\n\t" << *this;
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
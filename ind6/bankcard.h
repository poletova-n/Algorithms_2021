//
// Created by reenie on 06.12.2021.
//

class BankCard {
public: // TODO: сделать private
	String CardholderName;
	String CardholderSurname;
	String CardNumber;
	String CardExpireDate;
	int    BankType;



public:
	explicit BankCard (char* source_str) {
		while (*source_str == ' ') { // пропуск незначащих нулей
			source_str++;
		}

		size_t i = 0; // поиск длины подстроки
		char* pos = source_str; // позиция первого символа подстроки
		while (*source_str != '\0' && *source_str != ' ') {
			source_str++; // перемещение до первого пробела
			i++; // увеличение длины искомой подстроки
		}
		char* buff = new char[i+1]; // выделение памяти под копию подстроки
		for (size_t j = 0; j < i; j++) {
			buff[j] = pos[j]; // копирование. pos[j] == *(source_str - i + j)
		}
		buff[i] = '\0'; // терминальный символ

		this->CardholderSurname = buff; // копирующее присваивание

		while (*source_str == ' ') { // пропуск незначащих нулей
			source_str++;
		}

		i = 0; // поиск длины подстроки
		pos = source_str; // позиция первого символа подстроки
		while (*source_str != '\0' && *source_str != ' ') {
			source_str++; // перемещение до первого пробела
			i++; // увеличение длины искомой подстроки
		}
		buff = new char[i+1]; // выделение памяти под копию подстроки
		for (size_t j = 0; j < i; j++) {
			buff[j] = pos[j]; // копирование. pos[j] == *(source_str - i + j)
		}
		buff[i] = '\0'; // терминальный символ

		this->CardholderName = buff; // копирующее присваивание

		while (*source_str == ' ') { // пропуск незначащих нулей
			source_str++;
		}

		i = 0; // поиск длины подстроки
		pos = source_str; // позиция первого символа подстроки
		while (*source_str != '\0' && *source_str != ' ') {
			source_str++; // перемещение до первого пробела
			i++; // увеличение длины искомой подстроки
		}
		buff = new char[i+1]; // выделение памяти под копию подстроки
		for (size_t j = 0; j < i; j++) {
			buff[j] = pos[j]; // копирование. pos[j] == *(source_str - i + j)
		}
		buff[i] = '\0'; // терминальный символ

		this->CardNumber = buff; // копирующее присваивание


		while (*source_str == ' ') { // пропуск незначащих нулей
			source_str++;
		}
		i = 0; // поиск длины подстроки
		pos = source_str; // позиция первого символа подстроки
		while (*source_str != '\0' && *source_str != ' ') {
			source_str++; // перемещение до первого пробела
			i++; // увеличение длины искомой подстроки
		}
		buff = new char[i+1]; // выделение памяти под копию подстроки
		for (size_t j = 0; j < i; j++) {
			buff[j] = pos[j]; // копирование. pos[j] == *(source_str - i + j)
		}
		buff[i] = '\0'; // терминальный символ

		this->CardExpireDate = buff; // копирующее присваивание

		this->BankType = this->CardNumber[0] ^ 0x30;
	}

	~BankCard () {
		std::cout << "BankCard object at " << this << " destructor.";
	}
};

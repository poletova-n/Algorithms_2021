#include <iostream>
#include <string>


bool sign(std::string& str); // функция, отвечающая за проверку знака после 'E' или 'e'
bool findE(std::string& str);  // функция, отвечающая за проверку цифр до знака знака 'E' или 'e'
bool checkNumber(std::string& str); // функция, отвечающая за проверку цифр до знака '.' или ',' или 'E' или 'e'
bool afterSign(std::string& str); // функция, отвечающая за проверку цифр просле знака '+'


int main()
{
	setlocale(LC_ALL, "Russian");
	std::string number;
	std::cin >> number;

	if ((((number[0] == '+') or (number[0] == '-')) or ((number[0] >= '0') and (number[0] <= '9')))) // проверка первого символа на знак
	{
		number.erase(number.begin()); // убираем знак 
		std::cout << checkNumber(number);
	}
	else std::cout << false;


	return 0;
}


bool sign(std::string& str) {
	return ((str[0] == '+') or (str[0] == '-')) ? str.erase(str.begin()), afterSign(str) : false;
}

bool checkNumber(std::string& str) {
	int iterator = 0;
	if ((str[iterator] >= '0') and (str[iterator] <= '9')) {
		iterator++;
		str.erase(str.begin());
		return checkNumber(str);
	}
	else if (((str[iterator] == '.') or (str[iterator] == ',')) and (str[iterator + 1] != 'E') and (str[iterator + 1] != 'e')) {
		str.erase(str.begin());
		return findE(str); // если встречается запятая, ищем числа после точки
	}
	else if ((str[iterator] == 'E') or (str[iterator] == 'e')) {
		str.erase(str.begin());
		return sign(str);  // если встречается 'e', ищем числа после 'e'
	}
	else return false;

}


bool findE(std::string& str) {
	int iterator = 0;
	if ((str[iterator] >= '0') and (str[iterator] <= '9')) {
		iterator++;
		str.erase(str.begin());
		return findE(str);
	}
	else if ((str[iterator] == 'E') or (str[iterator] == 'e')) {
		str.erase(str.begin());
		return sign(str);
	}
	else return false;
}

bool afterSign(std::string& str)
{
	int iterator = 0;
	if ((str[iterator] >= '0') and (str[iterator] <= '9')) {
		if (str.length() == 1) return true;
		iterator++;
		str.erase(str.begin());
		return afterSign(str);
	}
	else return false;
}
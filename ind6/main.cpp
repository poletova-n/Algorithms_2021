#include "string.h"
#include "bankcard.h"

int main () {
	try {
		BankCard card("  Vladimir   Strollov 5111000011110000   01/22        ");
		std::cout << card.CardholderSurname << "\n";
		std::cout << card.CardholderName << "\n";
		std::cout << card.CardNumber << "\n";
		std::cout << card.CardExpireDate << "\n";
		std::cout << card.BankType << "\n";
	} catch (const char*& error) {
		std::cerr << error << "\n";
	} catch (const std::exception& error) {
		std::cerr << error.what() << "\n";
	} catch (...) {
		std::cerr << "UNKNOWN ERROR.\n";
	}

	return 0;
}

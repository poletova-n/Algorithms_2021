#include <iostream>
#include <vector>
#include <fstream>
#include "bankcard.h"

int main () {
	std::ifstream ifile("input.txt");
	std::vector<BankCard> cards;
	while (ifile.is_open() && !ifile.eof())
		try {
			char* temp = new char[128];
			ifile.getline(temp, 128);
			cards.emplace_back(temp);
		} catch (const char*& error) {
			std::cerr << error << "\n";
		} catch (const std::exception& error) {
			std::cerr << error.what() << "\n";
		} catch (...) {
			std::cerr << "UNKNOWN ERROR.\n";
		}

	for (size_t i = 1; i < cards.size()-1; i++) {
		for (size_t j = 1; j < cards.size()-i; j++) {
			if (!compare_order(cards[j-1], cards[j])) {
				std::swap(cards[j-1], cards[j]);
			}
		}
	}

	for (BankCard& card: cards) {
		std::cout << card.CardholderSurname << " " << card.CardholderName << " " << card.CardNumber << " ";
		std::cout << card.CardExpireMonth << "/" << card.CardExpireYear << "\n";
	}
	return 0;
}

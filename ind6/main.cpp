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

	for (size_t i = 1; i < cards.size(); i++) {
		for (size_t j = 1; j < cards.size()-i; j++) {
			if (!compare_order(cards[j-1], cards[j])) {
				std::swap(cards[j-1], cards[j]);
			}
		}
	}

	size_t counter = 0;
	bool flag = false;
	for (size_t i = 1; i < cards.size(); i++) {
		if (cards[i-1].CardholderSurname.compare(cards[i].CardholderSurname) == 0 &&
			cards[i-1].CardholderName.compare(cards[i].CardholderName) == 0) {
			flag = true;
		} else {
			counter += flag;
			flag = false;
		}
	}

	for (BankCard& card: cards) {
		std::cout << card.CardholderSurname << " " << card.CardholderName << " ";
		std::cout << card.CardExpireMonth << "/" << card.CardExpireYear << " ";
		std::cout << card.CardNumber << "\n";
	}
	std::cout << counter << "\n";

	for (size_t i = 1; i < cards.size(); i++) {
		for (size_t j = 1; j < cards.size()-i; j++) {
			if (cards[j-1].CardNumber.compare(cards[j].CardNumber) > 0) {
				std::swap(cards[j-1], cards[j]);
			}
		}
	}

	size_t type_counter = 0;
	size_t max_counter = 0;
	for (size_t i = 1; i < cards.size(); i++) {
		if (cards[i-1].BankType == cards[i].BankType) {
			type_counter++;
		} else {
			max_counter = (max_counter < type_counter) ? type_counter : max_counter;
			type_counter = 0;
		}
	}

	std::cout << max_counter << "\n";
	return 0;
}

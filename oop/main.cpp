#include <iostream>

#include <fstream>

#include <string>

#include "BankCard.h"

#include "funcs.h"

int main() {


    std::string file1;

    std::cout << "Enter source file name:\n"; // ../file1.txt

    std::cin >> file1;

    std::ifstream file(file1);

    if (file.is_open()) {

        int n = 0;


        std::string n_s;

        std::getline(file, n_s);

        n = stoi(n_s);

        laba6::BankCard* cards = new laba6::BankCard[n];

        for (int i = 0; i < n; i++) {

            std::string name, num, date;

            std::getline(file, name);

            std::getline(file, num);

            std::getline(file, date);

            int j = name.find_first_of(' ');

            cards[i] = laba6::BankCard(name.substr(j + 1, name.length()),

                                       name.substr(0, j), num, date);

        }

        for (int i = 0; i < n; i++) {

            std::cout << cards[i] << "\n";

        }

        std::string file2;

        std::cout << "Enter output file name:\n"; // ../file2.txt

        std::cin >> file2;

        std::ofstream fout(file2);

        sortByNum(cards, n);

        std::cout << "==============================================\n";

        for (int i = 0; i < n; i++) {

            fout << cards[i] << "\n";

        }

        fout << "Number of cards that expire this year: " << countCard(cards, n) << "\n";

        fout << "Are there cardholders with the same surname?: "

             << (isEqualSurnamesAndUnequalNames(cards, n) ? "Yes" : "No") << "\n";

        fout.close();

        if (!fout) {

            std::cerr << "output file error\n";

        }

        file.close();

        if (!file) {

            std::cerr << "source file error\n";

        }

    }

    else {

        std::cerr << "can not open the file.\n";

    }

}
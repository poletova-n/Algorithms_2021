
#include <iostream>

#include <fstream>

#include <exception>

namespace laba4 {

    void function(char* destination, const char* source);

}


void laba4::function(char* destination, const char* source) {

    char s0 = 'a', s1 = 'a';

    std::cout << "Enter a character that need to be replaced: ";

    std::cin >> s0;

    std::cout << "Enter a character to which you need to replace: ";

    std::cin >> s1;

    for (int i = 0; source[i] != '\0'; i++) {

        if (source[i] == s0) {

            destination[i] = s1;

        }

        else {

            destination[i] = source[i];

        }

    }

}


int main() {


    std::ifstream file("../file.txt");

    try {

        if (file.is_open()) {

            int n = 0;

            file >> n;

            if (file.fail()) {

                throw std::logic_error("something wrong with the file");

            }

            char* source = new char[n + 1];

            file >> std::noskipws;

            for (int i = 0; i < n; i++) {

                file >> source[i];

                if (source[i] == '\n') i--;

            }

            source[n] = '\0';

            std::cout << source << std::endl;

            char* destination = new char[n + 1];

            destination[n] = '\0';

            laba4::function(destination, source);

            std::cout << destination;

            std::ofstream file2("../file2.txt");

            if (file2.is_open()) {

                file2 << destination;

                file2.close();

            }

            else {

                throw std::logic_error("could not open file2.txt");

            }

        }

        else {

            throw std::logic_error("could not open file.txt");

        }

    }

    catch (const std::logic_error& error) {

        std::cerr << error.what();

    }

    file.close();

    return 0;

}
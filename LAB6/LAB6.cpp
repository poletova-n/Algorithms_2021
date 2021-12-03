#include <iostream>
#include <fstream>
#include "String.h"
#include "Person.h"
#include "ArrayManager.h"
#include "PersonManager.h"

const char* ERROR_INCORRECT_INPUT_FILE_NAME = "Error: input file not found.";

const char* ERROR_INCORRECT_OUTPUT_FILE_NAME = "Error: output file not found.";

const char* ERROR_INCORRECT_LENGTH = "Error: length must be integer greater than 0.";

int main() {
    try {

        char inputAddress[40];
        char outputAddress[40];
        int length;

        std::cout << "Input name of file with information:"; std::cin >> inputAddress;
        std::cout << "Input name of file for output:"; std::cin >> outputAddress;

        std::fstream input(inputAddress);
        if (!input.is_open()) throw ERROR_INCORRECT_INPUT_FILE_NAME;

        input >> length;
        if (input.fail() || input.peek() != 10 || length < 1)
        {
            throw ERROR_INCORRECT_LENGTH;
        }

        Person* subscribers = new Person[length];

        PersonManager::readArray(subscribers, length, input);
        input.close();

        PersonManager::sortArray(subscribers, length);

        std::fstream output(outputAddress);
        if (!output.is_open()) throw ERROR_INCORRECT_OUTPUT_FILE_NAME;
        PersonManager::writeArray(subscribers, length, output);
        output.close();

        std::cout << "Number of unique second names:" << PersonManager::getNumberOfUniqSecondNames(subscribers, length) << std::endl;
        std::cout << "Number of the same FIO:" << PersonManager::getNumberOfTheSameFIOs(subscribers, length);
    }
    catch (const char* error)
    {
        system("cls");
        std::cerr << std::endl << error << std::endl;
        exit(1);
    }
    return 0;
}
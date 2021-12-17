#include <iostream>
#include <fstream>
#include <string>
#include "Sub.h"
#include "ArrayFile.h"

const char* ERROR_INCORRECT_INPUT_FILE_NAME = "Error - input file not found.";

const char* ERROR_INCORRECT_OUTPUT_FILE_NAME = "Error - output file not found.";

const char* ERROR_NO_INFO_INPUT = "Error -  no info in input file";

const char* ERROR_INCORRECT_LENGTH = "Error - length more than 0.";

std::string bestSoldCode(Sub*& subscribers, int length);

int countCodes(Sub*& subscribers, int length);

int main() {
    setlocale(LC_ALL, "");
    try {

        char inputSize[40];
        char outputSize[40];
        int size;

        std::cout << "Name of input file - "; std::cin >> inputSize;
        std::cout << "Name of output file -"; std::cin >> outputSize;

        std::fstream input(inputSize);
        if (!input.is_open()) throw ERROR_INCORRECT_INPUT_FILE_NAME;

        input >> size;
        if (input.fail() || (input.peek() != 10 && !input.eof()) || size < 1 || input.eof())
        {
            if (input.eof()) throw ERROR_NO_INFO_INPUT;
            throw ERROR_INCORRECT_LENGTH;
        }

        int startPos = 1;
        char cur;

        input.seekg(0);

        do {
            input >> std::noskipws;
            startPos++;
            input >> cur;
        } while (cur != '\n');

        input.seekg(startPos);

        int numberOfLines = 0;

        while (!input.eof()) {
            input >> std::noskipws;
            input >> cur;
            if (cur == '\n' || input.eof()) numberOfLines++;
        }

        size = std::min(numberOfLines, size);

        input.close();

        input.open(inputSize);
        if (!input.is_open()) throw ERROR_INCORRECT_INPUT_FILE_NAME;

        input.seekg(startPos);

        Sub* subscribers = new Sub[size];

        MyArray::readMyArray(subscribers, size, input);
        input.close();

        MyArray::sortMyArray(subscribers, size);

        std::fstream output(outputSize);
        if (!output.is_open()) throw ERROR_INCORRECT_OUTPUT_FILE_NAME;
        MyArray::writeMyArray(subscribers, size, output);
        output.close();
        std::cout << "Most popular tariff -  ";
        std::cout << bestSoldCode(subscribers, size) << std::endl;
        std::cout << "Number of tariffs -  ";
        std::cout << countCodes(subscribers, size);

        return 0;
    }
    catch (const char* error)
    {
        std::cerr << std::endl << error << std::endl;
        exit(1);
    }
}

std::string bestSoldCode(Sub*& subscribers, int length) {
    std::string answer = "";
    int cur = 0; int max = std::numeric_limits<int>::min();
    for (int i = 0; i < length; ++i) {
        cur = 0;
        for (int j = 0; j < length; ++j) {
            if (j != i && subscribers[i].getCode() == subscribers[j].getCode()) {
                cur++;
            }
        }
        if (cur > max) {
            max = cur;
            answer = subscribers[i].getCode();
        }
    }
    return answer;
}

int countCodes(Sub*& subscribers, int length) {
    int answer = 0;
    std::string codes = "";
    for (int i = 0; i < length; ++i) {
        if (codes.find(subscribers[i].getCode()) == std::string::npos) {
            codes += subscribers[i].getCode() + " ";
            answer++;
        }
    }
    return answer;
}
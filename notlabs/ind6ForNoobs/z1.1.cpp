#include <iostream>
#include <fstream>
#include "Subscriber.h"
#include "ArrayManager.h"

const char* ERROR_INCORRECT_INPUT_FILE_NAME = "Error: input file not found.";

const char* ERROR_INCORRECT_OUTPUT_FILE_NAME = "Error: output file not found.";

const char* ERROR_INCORRECT_LENGTH = "Error: length must be integer greater than 0.";

std::string mostPopularTrafficCodes(Subscriber * & subscribers, int length);

int countOfDifferentTrafficCodes(Subscriber * & subscribers, int length);

int main(){
    try {

        char inputAddress[40];
        char outputAddress[40];
        int length;

        std::cout << "Input name of file with information:"; std::cin >> inputAddress;
        std::cout << "Input name of file for output:"; std::cin >> outputAddress;

        std::fstream input(inputAddress);
        if(!input.is_open()) throw ERROR_INCORRECT_INPUT_FILE_NAME;

        input >> length;
        if(input.fail() || input.peek() != 10 || length < 1)
        {
            throw ERROR_INCORRECT_LENGTH;
        }
        input.seekg(3);

        Subscriber * subscribers = new Subscriber[length];

        ArrayManager::readArray(subscribers, length, input);
        input.close();

        ArrayManager::sortArray(subscribers, length);

        std::fstream output(outputAddress);
        if(!output.is_open()) throw ERROR_INCORRECT_OUTPUT_FILE_NAME;
        ArrayManager::writeArray(subscribers, length, output);
        input.close();

        std::cout << mostPopularTrafficCodes(subscribers, length) << std::endl;
        std::cout << countOfDifferentTrafficCodes(subscribers, length);

        return 0;
    }
    catch(const char* error)
    {
        system("cls");
        std::cerr << std::endl << error << std::endl;
        exit(1);
    }
}

std::string mostPopularTrafficCodes(Subscriber * & subscribers, int length){
    std::string answer = "";
    int cur = 0; int max = std::numeric_limits<int>::min();
    for (int i = 0; i < length; ++i) {
        cur = 0;
        for (int j = 0; j < length; ++j) {
            if(j != i && subscribers[i].getCode() == subscribers[j].getCode()){
                cur++;
            }
        }
        if(cur > max){
            max = cur;
            answer = subscribers[i].getCode();
        }
    }
    return answer;
}

int countOfDifferentTrafficCodes(Subscriber * & subscribers, int length){
    int answer = 0;
    std::string codes = "";
    for (int i = 0; i < length; ++i) {
        if(codes.find(subscribers[i].getCode()) == std::string::npos){
            codes += subscribers[i].getCode() + " ";
            answer++;
        }
    }
    return answer;
}
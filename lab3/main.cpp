#include <iostream>
#include "Stack.h"

int main () {
    StackArray<std::string> list(1024);
    std::string temp;
    while (temp != "exit")
        try {
            std::cout << ">>> ";
            std::getline(std::cin, temp);
            if (temp.empty()) {
                continue;
            }
            std::string postfix;
            list.getPostfixFromInfix(temp, postfix, 100);
            int32_t i =  list.evaluatePostfix(postfix, 100);
            std::cout << postfix << "\n";
            std::cout << list.checkBraces(temp) << "\n";
            std::cout << i << "\n";
        } catch (const char* error) {
            std::cout << "INCOMPLETE SENTENCE" << "\n";
        }
}
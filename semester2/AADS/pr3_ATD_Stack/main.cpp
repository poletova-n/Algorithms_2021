#include <iostream>
#include "Stack.h"
#include "StackList.h"
#include "StackArray.h"

void arrayStack();

void listStack();

bool checkBalanceBrackets (const std::string& text, int maxDeep);

int evaluatePostfix (const std::string& infix, const size_t stackSize);

bool getPostfixFromInfix (const std::string& infix, std::string& postfix, const size_t stackSize);

int main() {

    std::string ans = "";

    std::cout << getPostfixFromInfix("15/(7-(1+1))*3-(2+(1+1))*15/(7-(200+1))*3-(2+(1+1))*(15/(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1)))", ans, 100) << std::endl;

    std::cout << ans;

    std::cout << evaluatePostfix(ans, 100);

    return 0;
}

bool isPair(char first, char second){
    return first == '(' && second == ')' ||
            first == '[' && second == ']' ||
            first == '{' && second == '}';
}

bool isOpening(char first){
    return first == '(' ||  first == '[' ||  first == '{';
}

bool isClosing(char first){
    return first == ')' ||  first == ']' ||  first == '}';
}

bool checkBalanceBrackets (const std::string& text, int maxDeep){

    StackArray<char> stackArray;

    for (int i = 0; i < text.size(); ++i) {
        if(isOpening(text[i])){
            stackArray.push(text[i]);
            if(stackArray.getCurSize() > maxDeep) return false;
        }
        else{
            if(isOpening(stackArray.top())){
                if(isPair(stackArray.top(), text[i])) {
                    stackArray.pop();
                }
                else{
                    return false;
                }
            }else{
                return false;
            }
        }
    }
    return stackArray.isEmpty();
};

bool isSame(char first, char second){
    return (first == '+' || first == '-') && (second == '+' || second == '-') ||
         (first == '*' || first == '/') && (second == '*' || second == '/') ||
            (first == '(' && second == '(');
}

bool isBigger(char first, char second){
    return ((first == '*' || first == '/') && (second == '+' || second == '-' || second == '(')) || ((first == '+' || first == '-') && second == '(') ||
           isSame(first, second);
};

bool getPostfixFromInfix (const std::string& infix, std::string& postfix,
                          const size_t stackSize){
    StackArray<char> stackArray(stackSize);
    for (int i = 0; i < infix.size(); ++i) {
        if(infix[i] >= '0' && infix[i] <= '9'){
            if(i != 0 && i != infix.size()) if(infix[i-1] < '0' || infix[i-1] > '9')  postfix+= ' ';
            postfix+=infix[i];
        }

        else if(infix[i] == '(' ){
                    stackArray.push(infix[i]);
        }

        else if(infix[i] == ')'){
            while(stackArray.top() != '(' && !stackArray.isEmpty()){
                postfix += stackArray.pop();
            }
            if(stackArray.isEmpty()) return false;
            stackArray.pop();
        }

        else if(infix[i] == '/' || infix[i] == '*' || infix[i] == '+' || infix[i] == '-'){

            while( isBigger(stackArray.top(), infix[i]) && !stackArray.isEmpty()){
                postfix += stackArray.pop();
            }
            stackArray.push(infix[i]);
        }

    }
    while(!stackArray.isEmpty()){
        if(stackArray.top() == '('){
            postfix = "";
            return false;
        }
        postfix += stackArray.pop();
    }
    return true;
}

void stackMath(StackArray<int>& stackArray, char operation){
    int first = stackArray.pop();
    int second = stackArray.pop();
    std::cout << second << operation << first << std::endl;
    switch (operation) {
        case '+':
            stackArray.push(first+second);
            break;
        case '-':
            stackArray.push(second-first);
            break;
        case '/':
            stackArray.push(second/first);
            break;
        case '*':
            stackArray.push(second*first);
            break;
        default:
            break;
    }
};

int stringToInt(const std::string& string){
    int res = 0;
    int div = 1;
    for(int i = string.size() - 1; i >= 0; --i){
        res += (string[i] - 48) * div;
        div *= 10;
    }
    return res;
}

int evaluatePostfix (const std::string& infix, const size_t stackSize){
    StackArray<int> stackArray(stackSize);
    std::string curInt = "";
    for (char i : infix) {
        if (i >= '0' && i <= '9') {
            curInt += i;
        }
        else{
            if(!curInt.empty()) {
                stackArray.push(stringToInt(curInt));
                curInt = "";
            }
            if(i != ' ') stackMath(stackArray, i);
        }
    }

    return stackArray.top();
}

void listStack(){
    StackList<int> stack;

    stack.push(1);

    stack.push(2);

    stack.push(3);

    stack.print();

    std::cout << stack.pop() << std::endl;

    stack.print();
};

void arrayStack(){

    StackArray<int> stack(4);

    stack.push(1);

    stack.pop();

    stack.pop();

    stack.print();

    std::cout << stack.pop() << std::endl;

    stack.print();

}
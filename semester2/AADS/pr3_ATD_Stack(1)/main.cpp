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

    StackArray<int> stackArray(1);

    //stackArray.pop();

    //stackArray.push(1); stackArray.push(1);

    //StackArray<int> stackArray2(135252523525235);

    //std::cout << checkBalanceBrackets("()(){([])}[]", 5) << std::endl;

    std::string ans;

    std::cout << getPostfixFromInfix("5*(1+6)-(34+1)", ans, 100) << std::endl;

    std::cout << ans << std::endl;

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

bool isNumber(const char& first){
    return first >= '0' && first <= '9';
}

char getPair(const char& first){
    switch (first) {
        case '(': return ')';
        case ')':return '(';
        case '{':return '{';
        case '}':return '}';
        case '[':return ']';
        case ']':return '[';
        default: return '0';
    }
}

bool isOperation(const char& first){
    return first == '/' || first == '*' || first == '+' || first == '-';
}

bool getPostfixFromInfix (const std::string& infix, std::string& postfix,
                          const size_t stackSize){
    StackArray<char> stackArray(stackSize);
    for (int i = 0; i < infix.size(); ++i) {

        char cur = infix[i];

        if(isNumber(cur)){
            if(i != 0 && i != infix.size()) if(!isNumber(infix[i-1]))  postfix+= ' ';
            postfix+=cur;
        }

        else if(cur == '('){ stackArray.push(cur); }

        else if(cur == ')'){
            while(stackArray.top() != '(' && !stackArray.isEmpty()){
                postfix += stackArray.pop();
            }
            if(stackArray.isEmpty()) {
                postfix = "";
                return false;
            }
            stackArray.pop();
        }

        else if(isOperation(cur)){

            while( isBigger(stackArray.top(), cur) && !stackArray.isEmpty()){
                postfix += stackArray.pop();
            }
            stackArray.push(cur);
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

int stackMath(int first, int second, char operation){
    switch (operation) {
        case '+': return first+second;
        case '-': return second-first;
        case '/':
            try {
                if(first == 0){throw "Division by zero"; }
                return second / first;
            }catch(const char * error) {
                std::cerr << error << std::endl;
                exit(1);
            }
        case '*': return second*first;
        default: return 0;
    }
}

int stringToInt(const std::string& string){
    int res = 0, div = 1;
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
        if (isNumber(i)) {
            curInt += i;
        }
        else{
            if(!curInt.empty()) {
                stackArray.push(stringToInt(curInt));
                curInt = "";
            }
            if(isOperation(i)) {
                int first = stackArray.pop(), second = stackArray.pop();
                stackArray.push(stackMath(first,second, i));
            }
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
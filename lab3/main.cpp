#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

char getPriority (std::string& op) {
    if (op == "(") {
        return 0;
    } else if (op == ")") {
        return 1;
    } else if (op == "+" || op == "-") {
        return 2;
    } else if (op == "*" || op == "/") {
        return 3;
    } else if (op == "^") {
        return 4;
    } else {
        return -1;
    }
}

bool getSpaces(const std::string& str, size_t& index) {
    if (str[index] == ' ') {
        ++index;
        getSpaces(str, index);
        return true;
    } else {
        return false;
    }
}

bool getOperator(const std::string& str, size_t& index) {
    static char* operators = "+-*/()^";
    for (char* c = operators; *c != '\0'; ++c) {
        if (*c == str[index]) {
            ++index;
            return true;
        }
    }
    return false;
}

bool getInt (const std::string& str, size_t& index) {
    if (str[index] >= '0' && str[index] <= '9') {
        getInt(str, ++index);
        return true;
    } else {
        return false;
    }
}

template <typename T> class Stack {
public:
    virtual ~Stack () = default;
    virtual void push (const T& element) = 0;
    virtual T pop () = 0;
    virtual bool isEmpty () = 0;
};

template <typename T> class StackArray: Stack<T> {
public:
    T* array;
    int32_t top;
    int32_t length;
public:
    StackArray (int32_t size) {
        array = new T[size];
        length = size;
        top = -1;
    }

    ~StackArray () {
        delete[] array;
    }

    void push (const T& element) {
        if (top < length) {
            array[++top] = element;
        } else {
            throw "STACKOVERFLOW";
        }
    }

    T pop () {
        if (top >= 0) {
            return array[top--];
        } else {
            top = -1;
            throw "STACKUNDERFLOW";
        }
    }

    bool isEmpty () {
        return top < 0;
    }

    bool getPostfixFromInfix (const std::string& infix, std::string& postfix, const size_t stackSize) {
        size_t index = 0;
        size_t old_index = index;
        while (index != infix.length()) {
            if (getInt(infix, index)) {
                postfix += infix.substr(old_index, index - old_index);
                postfix += " ";
            } else if (getOperator(infix, index)) {
                std::string op = infix.substr(old_index, index - old_index);
                if (getPriority(op) == 1) {
                    while (getPriority(array[top]) != 0) {
                        postfix += pop();
                        postfix += " ";
                    }
                    pop();
                } else if (getPriority(op) == 0) {
                    push(op);
                } else if (!isEmpty()) {
                    while (getPriority(array[top]) >= getPriority(op)) {
                        postfix += pop();
                        postfix += " ";
                    }
                    push(op);
                } else {
                    push(op);
                }
            } else if (getSpaces(infix, index)) {
                ;
            } else {
                while (top >= 0) {
                    pop();
                }
                return false;
            }
            old_index = index;
        }
        while (!isEmpty()) {
            postfix += pop();
            postfix += " ";
        }
        return true;
    }

    int evaluatePostfix (const std::string& postfix, size_t stackSize) {
        size_t index = 0;
        while (index != postfix.length()) {
            size_t old_index = index;
            if (getInt(postfix, index)) {
                push(postfix.substr(old_index, index-old_index));
            }
            if (getOperator(postfix, index)) {
                const char* op = postfix.substr(old_index, index - old_index).c_str();
                int temp = std::stod(pop());
                switch (*op) {
                    case '+': {
                        push(std::to_string(std::stoi(pop()) + temp));
                        break;
                    }
                    case '-': {
                        push(std::to_string(std::stoi(pop()) - temp));
                        break;
                    }
                    case '*': {
                        push(std::to_string(std::stoi(pop()) * temp));
                        break;
                    }
                    case '/': {
                        push(std::to_string(std::stoi(pop()) / temp));
                        break;
                    }
                }
            }
            if (getSpaces(postfix, index)) {
                continue;
            }
            throw "UNKNOWN SYMBOLS";
        }
        if (top == 0) {
            return std::stoi(pop());
        } else {
            while (!isEmpty()) {
                pop();
            }
            throw "INCOMPLETE SENTENCE";
        }
    }
};

int main () {
    StackArray<std::string> list(1024);
    std::string temp;
    std::cout << std::setprecision(15);
    while (temp != "exit")
        try {
            std::cout << ">>> ";
            std::getline(std::cin, temp);
            if (temp.empty()) {
                continue;
            }
            std::string postfix;
            list.getPostfixFromInfix(temp, postfix, 100);
            int32_t i = list.evaluatePostfix(postfix, 100);
            //std::cout << postfix << "\n";
            std::cout << i << "\n";
        } catch (const char* error) {
            std::cout << "INCOMPLETE SENTENCE" << "\n";
        }
}
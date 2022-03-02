#include <iostream>
#include <vector>

char getPriority (std::string& op) {
    if (op == "(") {
        return 0;
    }
    if (op == ")") {
        return 1;
    }
    if (op == "+" || op == "-") {
        return 2;
    }
    if (op == "*" || op == "/") {
        return 3;
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
    if (str[index] == '+' || str[index] == '-' || str[index] == '*' || str[index] == '/' || str[index] == '(' || str[index] == ')') {
        ++index;
        return true;
    } else {
        return false;
    }
}

bool getVar(const std::string& str, size_t& index) {
    if ((str[index] >= 'a' && str[index] <= 'z') || (str[index] >= 'A' && str[index] <= 'Z')) {
        getVar(str, ++index);
        return true;
    } else {
        return false;
    }
}

bool getOperand(const std::string& str, size_t& index) {
    if (str[index] >= '0' && str[index] <= '9') {
        getOperand(str, ++index);
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
        size_t buf_index = 1;
        while (index != infix.length() && index != buf_index) {
            buf_index = index;
            if (getOperand(infix, index) || getVar(infix, index)) {
                postfix += infix.substr(buf_index, index - buf_index);
                postfix += " ";
                continue;
            }
            if (getOperator(infix, index)) {
            std::string op = infix.substr(buf_index, index - buf_index);
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
                continue;
            }
            if (getSpaces(infix, index)) {
                continue;
            }
            return false;
        }
        if (index == buf_index) {
            return false;
        }
        while (top >= 0) {
            postfix += pop();
            postfix += " ";
        }
    }

    int evaluatePostfix (const std::string& postfix, size_t stackSize) {
        size_t index = 0;
        while (index != postfix.length()) {
            size_t buf_index = index;
            if (getOperand(postfix, index)) {
                push(postfix.substr(buf_index, index-buf_index));
            }
            if (getOperator(postfix, index)) {
                char* op = const_cast<char *>(postfix.substr(buf_index, index - buf_index).c_str());
                int temp = std::stoi(pop());
                switch (*op) {
                    case '+': {
                        push(std::to_string(std::stoi(pop()) + temp));
                        break;
                    }
                    case '-': {
                        push(std::to_string(std::stoi(pop()) - temp)); //
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
        return std::stoi(pop());
    }

    std::string checkout() {
        std::string temp;
        for (uint32_t i = 0; i < length; ++i) {
            temp += array[i];
        }
        return temp;
    }
};

int main () {
    StackArray<std::string> list(1024);
    std::string temp;
    while (temp != "exit")
        try {
            std::string postfix;
            std::getline(std::cin, temp);
            list.getPostfixFromInfix(temp, postfix, 100);
            int i = list.evaluatePostfix(postfix, 100);
            std::cout << i << "\n";
        } catch (const char* error) {
            std::cout << error << "\n";
        }
}

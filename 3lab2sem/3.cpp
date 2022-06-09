#include <iostream>
#include <string>
#include "StackArray.h"
#include "Stack.h"
#include <map>
#include <cctype>

bool getPostfixFromInfix(const std::string& infix, std::string& postfix,const size_t stackSize);
bool checkBalanceBrackets(const std::string& text, const int maxDeep);
bool getPostfixFromInfix(const std::string& infix, std::string& postfix,const size_t stackSize);
bool checkBalanceBrackets(const std::string& text, const int maxDeep);
int evaluatePostfix (const std::string& infix, const size_t stackSize);

int main()
{
        setlocale(LC_ALL, "Russian");
        //stack underflow
      /*  std::string infix1("");
        std::string postfix1;
        getPostfixFromInfix(infix1, postfix1, 10);
        evaluatePostfix(postfix1, 10);*/

        //stackoverflow
      /*  std::string infix1("9*6+(3-9*1)+3+3+3+3+3");
        std::string postfix1;
        getPostfixFromInfix(infix1, postfix1, 10);*/

        //stack wrong size
     /*   std::string infix1("");
        std::string postfix1;
        getPostfixFromInfix(infix1, postfix1, 33333333333);*/





      /*  std::string infix1("9*6+(3-9*1)");
        std::string postfix1;
        std::cout << ((checkBalanceBrackets(infix1, 10)) ? "true" : "false")<<std::endl;
        getPostfixFromInfix(infix1, postfix1, 10);
        std::cout << postfix1 << '\n';
        std::cout << evaluatePostfix(postfix1, 10) << '\n';*/

        std::string infix2("(3+9)/(5-1)");
        std::string postfix2;
        std::cout << ((checkBalanceBrackets(infix2, 15)) ? "true" : "false") << std::endl;
        getPostfixFromInfix(infix2, postfix2, 15);
        std::cout << postfix2 << '\n';
        std::cout << evaluatePostfix(postfix2, 15) << '\n';

        std::string infix3("(2+2)*2");
        std::string postfix3;
        std::cout << ((checkBalanceBrackets(infix3, 10)) ? "true" : "false") << std::endl;
        getPostfixFromInfix(infix3, postfix3, 10);
        std::cout << postfix3 << '\n';
        std::cout << evaluatePostfix(postfix3, 10) << '\n';

        std::string infix4("{}[]()");
        std::cout << ((checkBalanceBrackets(infix4, 10)) ? "true" : "false") << std::endl;
        std::string infix5("{}]()");
        std::cout << ((checkBalanceBrackets(infix5, 10)) ? "true" : "false") << std::endl;
}

bool checkBalanceBrackets(const std::string& text, const int maxDeep) {
    StackArray<char>stack;
    int count = 0;
    for (int i = 0; i < text.length(); ++i) {
        if (text[i] == ')' || text[i] == '}' || text[i] == ']' || text[i] == '(' || text[i] == '{' || text[i] == '[') {
            if (text[i] == ')' || text[i] == '}' || text[i] == ']') {
                if (stack.isEmpty())return false;
                char last_br = stack.pop();
                if ((text[i] == ')' && last_br != '(') || (text[i] == '}' && last_br != '{') || (text[i] == ']' && last_br != '[')) return false;
            }
            else {
                stack.push(text[i]);
                count++;

            }
        }
        if (count > maxDeep)return false;
    }

    return stack.isEmpty();
}

bool getPostfixFromInfix(const std::string& infix, std::string& postfix, const size_t stackSize) {
    try {
        if(!checkBalanceBrackets(infix,stackSize)) return false;
        StackArray<char> stack(stackSize);
        StackArray<char> queue(stackSize);
        char temp, topElem;
        size_t i = 0;
        bool operatorCur, operatorTop = false;
        while (infix[i] != '\0' && infix[i] != '\n') {
            temp = infix[i];
            if (isdigit(temp)) {
                queue.push(temp);
            }
            else if (temp == '+' || temp == '-' || temp == '*' || temp == '/') {
                if (stack.isEmpty() || stack.top() == '(')//если в вершине стека открываюзая скобка или стек пуст добавляем в стек
                    stack.push(temp);
                else {
                    //проверяем приоритет
                    if (temp == '+' || temp == '-')
                        operatorCur = 0;
                    else
                        operatorCur = 1;
                    if (stack.top() == '+' || stack.top() == '-')
                        operatorTop = 0;
                    else if (stack.top() == '*' || stack.top() == '/')
                        operatorTop = 1;
                    if (operatorCur > operatorTop)
                        stack.push(temp);
                    else {
                        while (!stack.isEmpty() && operatorTop >= operatorCur && stack.top() != '(') {
                            queue.push(stack.pop());
                            if (stack.top() == '+' || stack.top() == '-')
                                operatorTop = 0;
                            else if (stack.top() == '*' || stack.top() == '/')
                                operatorTop = 1;
                        }
                        stack.push(temp);

                    }
                }
            }
            //если входящий элемент  ( делаем push
            else if (temp == '(')
                stack.push(temp);
            //если входящий элемент ) делаем pop
            else if (temp == ')') {
                //достаем элементы пока не встретим (
                while (true) {
                    topElem = stack.pop();
                    if (topElem == '(')
                        break;
                    else 
                        queue.push(topElem);
                }
            }
            i++;
        }
        //пока стек не пустой добавляем элементы в очередь из вершины стека
        while (!stack.isEmpty())
            queue.push(stack.pop());
        i = queue.getLenght();
        for (i; i > 0; i--)
            postfix = queue.pop() + postfix;
        return true;
    }
    catch (const std::exception& e) {
        std::cout  << e.what() << "\n";
    }
}


int evaluatePostfix(const std::string& infix, const size_t stackSize)
{
    try {
        StackArray<int> stack(stackSize);
        int i = 0;
        while (infix[i] != '\0' && infix[i] != '\n') {
            //если какой-то оператор, то извлекаем два верхних элемента, выполняем операцию и пушим результат в стек
            if (isdigit(infix[i])) {
                stack.push(infix[i] - '0');
            }
            else if (infix[i] == '+') {
                int first = stack.pop();
                int second = stack.pop();
                stack.push(first + second);
            }
            else if (infix[i] == '-') {
                int first = stack.pop();
                int second = stack.pop();
                stack.push(second - first);
            }
            else if (infix[i] == '*') {
                int first = stack.pop();
                int second = stack.pop();
                stack.push(second * first);
            }
            else if (infix[i] == '/') {
                int first = stack.pop();
                int second = stack.pop();
                stack.push(second / first);
            }
            i++;
        }
        return stack.pop();//результат
    }
    catch (const std::exception& e) {
        std::cout <<  e.what() << "\n";
        return NULL;
    }
}
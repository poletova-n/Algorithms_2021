#include <iostream>
#include <vector>

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
    size_t top;
    size_t length;
public:
    StackArray (size_t size) {
        array = new T(size);
        length = size;
        top = 0;
    }

    ~StackArray () {
        delete[] array;
    }

    void push (const T& element) {
        if (top < length) {
            array[top++] = element;
        } else {
            throw "а спонсор моего кода STACKOVERFLOW";
        }
    }

    T pop () {
        if (top != 0) {
            return array[top--];
        } else {
            throw "STACK UNDERFLOW";
        }
    }

    bool isEmpty () {
        return top == 0;
    }
};

int main () {
    StackArray<int> list(2);
    try {
        list.push(10);
        list.push(10);
        list.push(10);
        list.push(10);
        list.push(10);
        list.pop();
        list.pop();
    } catch (const char* error) {
        std::cout << error << "\n";
    }

    int* cursor = list.array;
    size_t i = 0;
    while (i < list.length) {
        std::cout << cursor[i++] << " ";
    }
}

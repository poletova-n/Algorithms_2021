#ifndef ALGORITHMS_2021_ARRAYMANAGER_H
#define ALGORITHMS_2021_ARRAYMANAGER_H

#include <fstream>
#include <iostream>

class MyArray {

public:

    MyArray() = delete;

    template <class T>
    static void sortMyArray(T*& array, int size);

    template<class T>
    static void readMyArray(T*& array, int size, std::fstream& input);

    template<class T>
    static void writeMyArray(T*& array, int size, std::fstream& output);

};

template<class T>
void MyArray::sortMyArray(T*& array, int size) {
    T temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

template<class T>
void MyArray::writeMyArray(T*& array, int size, std::fstream& output) {
    for (int i = 0; i < size; ++i) {
        output << array[i];
    }
}

template<class T>
void MyArray::readMyArray(T*& array, int size, std::fstream& input) {
    for (int i = 0; i < size; ++i) {
        input >> array[i];
    }
}
#endif 
#pragma once
#ifndef ALGORITHMS_2021_ARRAYMANAGER_H
#define ALGORITHMS_2021_ARRAYMANAGER_H

#include <fstream>
#include <iostream>

class ArrayManager {

public:

    ArrayManager() = delete;

    template <class T>
    static void sortArray(T*& array, int length);

    template<class T>
    static void readArray(T*& array, int length, std::fstream& input);

    template<class T>
    static void writeArray(T*& array, int length, std::fstream& output);

};

template<class T>
void ArrayManager::sortArray(T*& array, int length) {
    T current;
    int prevIndex;
    for (int counter = 1; counter < length; counter++)
    {
        current = array[counter];
        prevIndex = counter - 1;
        while (prevIndex >= 0 && array[prevIndex] > current)
        {
            array[prevIndex + 1] = array[prevIndex];
            array[prevIndex] = current;
            prevIndex--;
        }
    }
}

template<class T>
void ArrayManager::readArray(T*& array, int length, std::fstream& input) {
    for (int i = 0; i < length; ++i) {
        input >> array[i];
    }
}

template<class T>
void ArrayManager::writeArray(T*& array, int length, std::fstream& output) {
    for (int i = 0; i < length; ++i) {
        output << array[i];
    }
}


#endif //ALGORITHMS_2021_ARRAYMANAGER_H
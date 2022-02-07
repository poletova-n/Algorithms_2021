#ifndef ALGORITHMS_2021_ARRAYMANAGER_H
#define ALGORITHMS_2021_ARRAYMANAGER_H

#include <fstream>
#include <iostream>

class ArrayManager {

public:

    ArrayManager() = delete;

    template <class T>
    static void sortArray (T * & array , int length );

    template<class T>
    static void readArray(T *&array, int length, std::fstream &input);

    template<class T>
    static void writeArray(T *&array, int length, std::fstream &output);

};

template<class T>
void ArrayManager::sortArray(T *&array, int length) {
    T temp;
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {

            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}



template<class T>
void ArrayManager::readArray(T *&array, int length, std::fstream &input) {
    for (int i = 0; i < length; ++i) {
        input >> array[i];
    }
}

template<class T>
void ArrayManager::writeArray(T *&array, int length, std::fstream &output) {
    for (int i = 0; i < length; ++i) {
        output << array[i];
    }
}


#endif //ALGORITHMS_2021_ARRAYMANAGER_H

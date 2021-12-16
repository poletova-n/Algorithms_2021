#pragma once
#include <assert.h>

template <class T>
class Vector {
private:
    int m_lenght;
    T** m_data;
public:
    Vector() {
        m_lenght = 0;
        m_data = nullptr;
    }

    Vector(int lenght) {
        m_data = new T*[lenght];
        for (int i = 0; i < lenght; i++) {
            m_data[i] = new T();
        }
        m_lenght = lenght;
    }

    ~Vector() {
        if (m_data != nullptr) {
            delete[] m_data;
            m_data = nullptr;
        }
    }

    void erase() {
        if (m_data != nullptr) {
            for (int i = 0; i < m_lenght; i++) {
                if (m_data[i] != nullptr)delete m_data[i];
            }
            delete[] m_data;
            m_data = nullptr;
        }
    }

    T& operator[](int index) {
        assert(index >= 0 && index < m_lenght);
        return *(m_data[index]);
    }

    int getLenght() {
        return m_lenght;
    }

    void deleteElem(int index) {
        if (m_data[index] != nullptr) {
            delete m_data[index];
            m_data[index] = nullptr;
        }
    }

    void deleteInvalid() {
        bool exit = false;
        while (!exit) {
            exit = true;
            for (int i = 0; i < m_lenght - 1; i++) {
                if (m_data[i] == nullptr && m_data[i + 1] != nullptr) {
                    m_data[i] = m_data[i + 1];
                    m_data[i + 1] = nullptr;
                    exit = false;
                }
            }
        }
        for (int i = 0; i < m_lenght; i++) {
            if (m_data[i] == nullptr)
                m_lenght = i;
        }
    }

    T**getData() {
        return m_data;
    }
};






#ifndef ALGORITHMS_2021_VECTOR_H
#define ALGORITHMS_2021_VECTOR_H

#endif //ALGORITHMS_2021_VECTOR_H

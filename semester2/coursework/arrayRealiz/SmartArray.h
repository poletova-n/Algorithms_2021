
#ifndef ALGORITHMS_2021_SMARTARRAY_H
#define ALGORITHMS_2021_SMARTARRAY_H

#include <iostream>

template <class T>
class SmartArray {
private:

    T* array_;

    int size_;

public:


    explicit SmartArray(){
        size_ = 1;
        array_ = new T[size_];
    }

    explicit SmartArray(int size){
        size_ = size;
        array_ = new T[size];
    }

    SmartArray(SmartArray<int> *array, int size){
        size_ = size;
        array_ = new T[size_];
        for (int i = 0; i < size_; ++i) {
            array_[i] = array[i];
        }
    }


    void fillWithZeros(){
        for (int i = 0; i < size_; ++i) {
            array_[i] = 0;
        };
    }
    
    void add(){

        T* cur = new T[size_+1];
        for (int i = 0; i < size_; ++i) {
            cur[i] = array_[i];
        }

        delete [] array_;
        array_ = cur;

        ++size_;
    };

    void cut(int index){

        T* cur = new T[size_-1];
        int curI = 0;
        for (int i = 0; i < size_; ++i) {
            if(i != index) {
                cur[curI] = array_[i];
                curI++;
            }
        }
        delete [] array_;
        array_ = cur;
        size_--;
    }

    void print(){
        for (int i = 0; i < size_; ++i) {
            std::cout << array_[i] << " ";
        }
        std::cout << std::endl;
    };

    T &operator[](int pos){return array_[pos];};

    T& get(int pos){return array_[pos];};

    int size(){
        return size_;
    }

    ~SmartArray(){
        delete [] array_;
    }
};


#endif //ALGORITHMS_2021_SMARTARRAY_H

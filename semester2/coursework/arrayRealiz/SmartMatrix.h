
#ifndef ALGORITHMS_2021_SMARTMATRIX_H
#define ALGORITHMS_2021_SMARTMATRIX_H

#include "SmartArray.h"

class SmartMatrix {
private:

    SmartArray<SmartArray<int>*>* matrix_;

    int size_;

public:

    SmartMatrix(){
        matrix_ = new SmartArray<SmartArray<int>*>();
        matrix_->get(0) = new SmartArray<int>();
        matrix_->get(0)->get(0) = 0;
        size_ = 1;
    }

    int& operator()(int pos1, int pos2){
        return matrix_->get(pos1)->get(pos2);
    };

    SmartArray<int>* operator()(int pos1){
        return matrix_->get(pos1);
    };

    void add(){
        for (int i = 0; i < matrix_->size(); ++i) {
            matrix_->get(i)->add();
            matrix_->get(i)->get(matrix_->size()) = 0;
        }
        matrix_->add();
        ++size_;
        matrix_->get(size_ - 1) = new SmartArray<int>(size_);
        matrix_->get(size_ - 1)->fillWithZeros();
        //std::cout << std::endl;
    };

    void cut(int index){
        for (int i = 0; i < matrix_->size(); ++i) {
            if(index != i) {
                //std::cout << i << std::endl;
                matrix_->get(i)->cut(index);
            }
        }
        //std::cout << "sus" << std::endl;
        matrix_->cut(index);
        --size_;
    }

    void print(){
        for (int i = 0; i < matrix_->size(); ++i) {
            for (int j = 0; j < matrix_->get(i)->size(); ++j) {
                std::cout << matrix_->get(i)->get(j) << " ";
            }
            std::cout << std::endl;
        }
    };

    int sub(int i){return matrix_->get(i)->size();}

    ~SmartMatrix(){
        for (int i = 0; i < size_; ++i) {
            delete [] matrix_->get(i);
        }
        delete [] matrix_;
    }
};


#endif //ALGORITHMS_2021_SMARTMATRIX_H

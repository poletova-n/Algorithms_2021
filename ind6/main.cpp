//
// Created by Foko on 15.05.2022.
//

#include <iostream>
#include <vector>
#include <iterator>

template<typename T>
void quicksort(std::vector<T> &array, int left, int right) {
    int index = (right + left + 1) / 2;
    int i = left, j = right;
    while (i <= j) {
        while (array[i] > array[index]) {++i;}
        while (array[j] < array[index]) {--j;}
        if (i <= j) {
            std::swap(array[i], array[j]);
            ++i;
            --j;
        }
    }
    if (left < j)
        quicksort<double>(array, left, j);
    if (right > i)
        quicksort<double>(array, i, right);
}

int main () {
    std::vector<double> v{1, 6, 4, 5, 6, 7, 8, 2, 3, 6};
    quicksort<double>(v, 0, v.size()-1);
    std::ostream_iterator<double> out(std::cout, " ");
    std::copy(v.begin(), v.end(), out);
    return 0;
}
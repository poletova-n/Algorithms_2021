#include <iostream>

template <class T>
void heapify(T* array, int n, int i);

template <class T>
void heapSort(T* array, int n);

template <class T>
void printArray(T* array, int n);

int main()
{
    int array[] = {12, 11, 13, 5, 6, 7, 4, 20, 30, 325, 1, 0, -1, 21};

    heapSort(array, 14);

    printArray(array, 14);
}

template <class T>
void heapify(T* array, int n, int i)
{
    int largest = i;

    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && array[left] > array[largest]) largest = left;
    if (right < n && array[right] > array[largest]) largest = right;

    if (largest != i){
        std::swap(array[i], array[largest]);
        heapify(array, n, largest);
    }
}

template <class T>
void heapSort(T* array, int n)
{
    for (int i = n / 2 - 1; i >= 0; --i) heapify(array, n, i);

    for (int i = n - 1; i >= 0; --i){
        std::swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

template <class T>
void printArray(T* array, int n)
{
    for (int i = 0; i < n; ++i) std::cout << array[i] << " ";
    std::cout << std::endl;
}
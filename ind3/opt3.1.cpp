#include <iostream>

void swap(int& a, int& b)
{
    int term = a;
    a = b;
    b = term;
}

int main()
{
    const int size = 11;
    int arr[size] = {23,21,43,-2,12,-54,213,4,-3,-5,9};
    for (int i = 0; i < size; ++i)
    {
        int smaller = i;
        for (int curr = 0; curr < size; ++curr)
        {
            if(arr[smaller] < arr[curr])
            {
                swap(arr[smaller], arr[curr]);
            }
        }
    }
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}


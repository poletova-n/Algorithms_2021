#include <iostream>

const int size = 6;

void getAnswer(int(&array)[size], int size);

int main()
{
    int array[size] = { 1, 2, 3, 5, -1, 0 };
    getAnswer(array, size);
    return 0;
}

void getAnswer(int(&array)[size], int size)
{
    int max = std::numeric_limits<int>::min();
    int count = 0;

    for (int i = 2; i < size; ++i) {
        if (array[i - 2] < array[i - 1] && array[i - 1] < array[i]) {
            ++count;
        }
    }

    std::cout << "Answer: " << count << std::endl;
}
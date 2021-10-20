#include <iostream>

int Count (int size, int array[]);

int main()
{
    int size = 10;
    int count = 0;
    int min = INT_MAX;
    int array[size] = {145, -22, 93, -14, -5, 30, 99, -708, 111, 3};
    int result = Count(size,array);
    std::cout << "Number of positive elements: " << result;
}
int Count (int size, int array[])
{
    size = 10;
    int count = 0;
    int min = INT_MAX;
    array[size] = {};
    int index = 0;
    for (int j = 0; j < size; j++)
    {
        if (array[j] < min)
        {
            min = array[j];
            index = j;
        }
    }
    for (int i = 0; i <=  index; i++)
    {
        if(array[i] > 0)
        {
            count ++;
        }
    }
    return count;
}



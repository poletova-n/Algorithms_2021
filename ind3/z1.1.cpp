#include <iostream>

int main()
{
    const int size = 6;
    int array[6] = {1, 2, 3, 5, -1, 0};
    int max = std::numeric_limits<int>::min();
    int count = 0;

    for (int i = 0; i < size; ++i)
    {
        if(max < array[i])
        {
            max = array[i];
            count = 0;
        }
        else
        {
            if(array[i] < 0)
            {
                count++;
            }
        }
    }

    std::cout << "Answer: " << count;
}

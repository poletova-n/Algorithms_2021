#include <iostream>

int main()
{
    const int N = 10;
    int max = std::numeric_limits<int>::min();
    int count = 0;
    int array[N] = {5, -100, 33, 35, -1, -25, 41, -56, 18, -89};
    for (int i = 0; i < N; ++i)
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
    std::cout << count;
}

#include <iostream>

const char* ERROR_INCORRECT_INPUT = "Error: array size must be integer greater than 0.";

void generateArray();

int main()
{
    generateArray();
}

void generateArray(){

    int n = 0;

    std::cout << "Enter array size:";
    std::cin >> n;

    if(std::cin.fail() || std::cin.peek() != 10 || n < 1)
    {
        std::cerr << ERROR_INCORRECT_INPUT << std::endl;
        exit(-1);
    }

    srand( (unsigned)time(NULL) );

    int* array = new int[n];
    int max = std::numeric_limits<int>::min();
    int count = 0;

    std::cout << "Array:";

    for (int i = 0; i < n; ++i)
    {
        array[i] = rand()%200 - 100;
        std::cout << " " << array[i];
    }

    std::cout << std::endl;

    for (int i = 0; i < n; ++i)
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

    std::cout << "Answer: " << count << std::endl;

    delete [] array;
}

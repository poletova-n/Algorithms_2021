//zadanie 1
#include <iostream>

#include <fstream>

const int row = 4, col = 5;

void counts(int arr[][col], std::ofstream *output);

int main()

{

    std::ofstream output("../output.txt");

    int arr[row][col] = {

            { 1,5,7,13,1 },

            { 2,3,5,10,15 },

            { 2,2,2,2,2 },

            { 5,10,16,17,20 }

    };

    counts(arr, &output);

}

void counts(int arr[][col], std::ofstream *output)

{

    int n = col;

    for (int i = 0; i < row;i++)

    {

        for (int j = 0; j < col; j++)

        {

            if ((arr[i][j] != arr[i][j + 1]) && (j == (col - 1)))

            {

                n--;

                break;

            }

        }

    }

        *output << "Number of columns that includes repeating elements : " << n;

    }

void ans( int**& array, int sizeX, int sizeY) {
    int i, j, col = 1, tmp, num=0;
    for ( i = 0; i < sizeX; i++)
    {
        for(j=0; j < sizeY; j++)
        {
            tmp = j+1;
            while(tmp<sizeX && array[tmp][i] == array[j][i])
                tmp++;
            if(col<tmp-j)
            {
                col = tmp-j;
                num = i;
            }
        }
    }
}

#include <iostream>
#include <fstream>
const int row = 4, col = 5;
void counts(int arr[row][col], std::ofstream *output);
int main()
{
    std::ofstream output("C:\\Users\\User\\c++\\Algorithms_2021\\ind5\\output.txt");
    int arr[row][col] = {
            { 1,5,7,13,1 },
            { 2,3,5,10,15 },
            { 2,2,2,2,2 },
            { 5,10,16,17,20 }
    };
    counts(arr, &output);
}
void counts(int arr[row][col], std::ofstream *output)
{
    int n = row;
    for (int i = 0; i < row;i++)
    {
        for (int j = 0; j < col; j++)
        {
            int flag=1;
            for (int k = 1; k < (col-j); k++)
            if (arr[i][j] == arr[i][j + k])
            {
                flag--;
                n--;
                break;
            }
            if (flag != 1)
                break;
        }
    }
    *output<<"Unique col-s: " << n;
}
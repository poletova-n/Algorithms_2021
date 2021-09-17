#include <iostream>

int main()
{
    int sum = 0;
    int input = 0;
   do{
       std::cin >> input;
       sum += input;
   }while(input != 0);
   std::cout << sum;
}

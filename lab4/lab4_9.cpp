#include <iostream>
int main ()
{
    int N;
    std::cout<<"Enter side length of a triangle "<<std::endl;
    std::cin>>N;
    if (std::cin.fail()||(N<=0))
    {
        std::cout << "wrong input, try again.\n";
    }
    else
        for (int n=0;n!=N;n++,N--)
            std::cout<<std::string(N,'*')<<std::endl;
}
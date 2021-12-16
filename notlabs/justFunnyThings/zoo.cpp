#include <iostream>
#include <ctime>

int main(){

    std::srand(0);
    int sus = 0;
    for (int i = 0; i < 100000; ++i) {
        for (int j = 0; j < 100000; ++j) {
            sus++;
        }
    }
    std::cout << "runtime = " << clock()/1000.0 << std::endl;
    return 0;
}
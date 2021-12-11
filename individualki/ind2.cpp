#include <iostream>
#include <windows.h>

int F(int q) {
    if (q > 1) {
        for (int i = q - 1; i > 0; i--) {
            q = q * i;
        }
    }
    else {
        q = 1;
    }
    return q;
}

double pow(double q, int n) {
    double q1 = q;
    if (n > 1) {
        for (n; n > 1; n--) {
            q = q * q1;
        }
    }
    else if (n == 1) {
        q = q;
    }
    else {
        q = 1;
    }
    return q;
}

const std::string Error_Int = "Ошибка, введите целое число";
const std::string Error_Double = "Ошибка, введите нецелое число";

int main()
{
    setlocale(LC_ALL, "russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int Max;
    double a, a1, d, x, absError, inter1, inter2, step;

    try {
        std::cout << "Введите абс погрешность: \n";
        std::cin >> absError;
        if (!std::cin) {
            throw Error_Double;
        }
        std::cout << "Введите левую границу интервала: \n";
        std::cin >> inter1;
        if (!std::cin) {
            throw Error_Double;
        }
        std::cout << "Введите правую границу интервала: \n";
        std::cin >> inter2;
        if (!std::cin) {
            throw Error_Double;
        }
        std::cout << "Введите шаг: \n";
        std::cin >> step;
        if (!std::cin) {
            throw Error_Double;
        }
        std::cout << "Введите макс чило слагаемых: \n";
        std::cin >> Max;
        if (!std::cin) {
            throw Error_Int;
        }
    }
    catch (const char* error) {
        std::cerr << std::endl << error << std::endl;
        return -1;
    }
 
    for (inter1; inter1 <= inter2; inter1 = inter1 + step) {
      x = inter1;
      
        a = 0;
        if ((inter1 > -1) and (inter1 < 1)) {
            for (int n = 0; n <= Max; n++) {
                a += F(2 * n) * pow(x, (2 * n + 1)) / (pow(4, n) * F(n) * F(n) * (2 * n + 1));
                if (n == Max - 2)   a1 = a;
          
            }
            d = a - a1;

            if (d < 0)   d *= -1;

            if (d < absError)  std::cout << "arcsin(" << x << ")=" << a << "\n";
               
            }
        else  std::cout << "arcsin(" << x << ") исключение по интервалу \n";
        
    }
    return 0;
}

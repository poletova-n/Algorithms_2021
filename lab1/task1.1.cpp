#include <iostream>
#include <cmath>

double get_sqrt_discriminant(int a, int b, int c) {
    int temp = b*b - 4*a*c;
    if (temp < 0) {
        std::cout << "Дискриминант меньше нуля\n";
        std::exit(1);
    } else {
        return std::sqrt(temp);
    }
}

int get_double() {
    int temp = 0;
    std::cin >> temp;
    if (std::cin.fail() or std::cin.peek() != '\n') {
        std::cout << "Коэфициент должен быть целочисленным\n";
        std::exit(1);
    }
    return temp;
}

void print_roots(int a, int b, double sqrt_discriminant) {
    if (sqrt_discriminant == 0) {
        std::cout << "Единственный корень: " << -b/(2*a) << "\n";
    } else {
        std::cout << "Первый корень: " << (-b+sqrt_discriminant)/(2*a) << "\n";
        std::cout << "Первый корень: " << (-b-sqrt_discriminant)/(2*a) << "\n";
    }
}

int main() {
    std::cout << "Введите первый коэфициент: ";
    int a = get_double();
    if (a == 0) {
        std::cout << "Коэфициент не может быть нулевым";
        std::exit(1);
    }
    std::cout << "Введите второй коэфициент: ";
    int b = get_double();
    std::cout << "Введите третий коэфициент: ";
    int c = get_double();
    double sqrt_discriminant = get_sqrt_discriminant(a, b, c);
    print_roots(a, b, sqrt_discriminant);
    return 0;
}
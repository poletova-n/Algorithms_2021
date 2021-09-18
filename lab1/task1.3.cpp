#include <iostream>

template <typename T> T get_value() {
    T temp = 0;
    std::cin >> temp;
    if (std::cin.fail() or std::cin.peek() != '\n') {
        std::cout << "Ошибка чтения!\n";
        std::exit(1);
    }
    return temp;
}

template <typename T>  T get_max(T a, T b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

template <typename T> T get_min(T a, T b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int main () {
    uint32_t a, b, c;
    std::cout << "Введите первую сторону: ";
    a = get_value<int>();
    std::cout << "Введите вторую сторону: ";
    b = get_value<int>();
    std::cout << "Введите третью сторону: ";
    c = get_value<int>();
    uint32_t sum = a + b + c;
    uint32_t max = get_max(get_max(a,b), c);
    if (sum - max <= max) {
        std::cout << "Не треугольник!" << std::endl;
        return 1;
    }
    if ((a == b) && (a == c) && (b == c)) {
        std::cout << "Треугольник равносторонний." << std::endl;
    } else if ((a == b) || (a == c) || (b == c)) {
        std::cout << "Треугольник равносторонний." << std::endl;
    } else {
        std::cout << "Треугольник общего вида." << std::endl;
    }
}

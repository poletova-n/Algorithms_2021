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

int main () {
    std::cout << "Введите X ладьи: ";
    uint32_t tower_x = get_value<uint32_t>();
    std::cout << "Введите Y ладьи: ";
    uint32_t tower_y = get_value<uint32_t>();
    std::cout << "Введите X цели: ";
    uint32_t target_x = get_value<uint32_t>();
    std::cout << "Введите Y цели: ";
    uint32_t target_y = get_value<uint32_t>();
    if ((tower_x == target_x) xor (tower_y == target_y)) {
        std::cout << "Ладья бьет цель." << std::endl;
    } else if ((tower_x == target_x) and (tower_y == target_y)) {
        std::cout << "Ладья и цель имеют одинаковые координаты" << std::endl;
    } else {
        std::cout << "Ладья не бьет цель." << std::endl;
    }
}
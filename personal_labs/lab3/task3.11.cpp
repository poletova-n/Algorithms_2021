#include <iostream>
#include <fstream>
#include <vector>

size_t get_max_index(std::vector<int> &values) {
    size_t index = 0;
    for (size_t i = 1; i < values.size(); i++) {
        if (values[index] < values[i]) {
            index = i;
        }
    }
    return index;
}

size_t get_min_index(std::vector<int> &values) {
    size_t index = 0;
    for (size_t i = 0; i < values.size(); i++) {
        if (values[index] > values[i]) {
            index = i;
        }
    }
    return index;
}

int main () {
    std::vector<int> static_array = {1, 3, 10, -9, 6, -1, 3, 5, 1};

    std::vector<int> dynamic_array;
    int temp;
    int length;
    std::cin >> length;
    for (size_t i = 0; i < length; i++) {
        std::cin >> temp;
        dynamic_array.push_back(temp);
    }

    std::vector<std::vector<int>> arrays_from_file;
    std::ifstream input_file("arrays.txt");
    while (!input_file.eof()) {
        arrays_from_file.resize(arrays_from_file.size()+1);
        input_file >> length;
        for (size_t i = 0; i < length; i++) {
            input_file >> temp;
            arrays_from_file[arrays_from_file.size()-1].push_back(temp);
        }
    }

    std::cout << "Static array of: ";
    for (int& item: static_array) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    std::cout << "Sum is " << get_min_index(static_array) + get_max_index(static_array) << std::endl;
    std::cout << std::endl;

    std::cout << "Dynamic array of: ";
    for (int& item: dynamic_array) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    std::cout << "Sum is " << get_min_index(dynamic_array) + get_max_index(dynamic_array) << std::endl;
    std::cout << std::endl;

    for (size_t i = 0; i < arrays_from_file.size(); i++) {
        std::cout << "Array from file №" << i << " of: ";
        for (int& item: arrays_from_file[i]) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
        std::cout << "Sum is " << get_min_index(arrays_from_file[i]) + get_max_index(arrays_from_file[i]) << std::endl;
    }

    return 0;
}
#include <fstream>
#include "Person.h"

void personSort(Person*& array, int size, bool (*comp)(Person o1, Person o2));

int main() {
    string filename;
    std::cout << "Input filename: ";
    std::cin >> filename;
    std::ifstream file(filename);
    string temp;
    getline(file, temp);
    int size = std::stoi(temp);
    int iter = size;
    Person* persons = new Person[size];
    int counter = 0;
    for (int i = 0; i < iter; i++) {
        getline(file, temp);
        if (Person::isValidInfo(temp)) {
            persons[counter] = Person(temp);
            counter++;
        }
        else {
            size--;
        }
    }

    std::ofstream fileFirstName("dataFirstName.txt");
    std::ofstream fileSecondName("dataSecondName.txt");
    std::ofstream fileDateOfBirth("dataDateOfBirth.txt");

    std::cout << "\nSort by date,surname,name: \n";
    personSort(persons, size, Person::compDateOfBirth);
    for (int i = 0; i < size; i++) {
        std::cout << persons[i].getFirstName() << " " << persons[i].getSecondName() << " " << persons[i].getDateOfBirth() << "\n";
        fileDateOfBirth << persons[i].getFirstName() << " " << persons[i].getSecondName() << " " << persons[i].getDateOfBirth() << "\n";
    }

    std::pair<string, int>* years = new std::pair<string, int>[size];
    for (int i = 0; i < size; i++) {
        bool isFound = false;
        for (int j = 0; j < size; j++) {
            if (persons[i].getDateOfBirth() == years[j].first) {
                years[j].second++;
                isFound = true;
                break;
            }
        }
        if (!isFound) {
            years[i].first = persons[i].getDateOfBirth();
            years[i].second = 1;
        }
    }
    int max = 0;
    for (int i = 0; i < size; i++) {
        if (years[i].first.length() != 0) {
            if (years[i].second > max) {
                max = years[i].second;
            }
        }
    }
    std::cout << "\nMax year(s): ";
    for (int i = 0; i < size; i++) {
        if (years[i].second == max) {
            std::cout << years[i].first << " \n";
        }
    }

    int c = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != j) {
                if (persons[i].getDateOfBirth() == persons[j].getDateOfBirth() && persons[i].getSecondName() == persons[j].getSecondName()) {
                    c++;

                }
            }
        }
    }
    std::cout << "\nThere are " << c << " people born in the same year." << std::endl;

    fileFirstName.close();
    fileSecondName.close();
    fileDateOfBirth.close();
    file.close();
}

void personSort(Person*& array, int size, bool (*comp)(Person o1, Person o2)) {
    for (int i = 1; i < size; i++) {
        for (int j = i; j > 0 && comp(array[j - 1], array[j]); j--) {
            Person tmp = array[j - 1];
            array[j - 1] = array[j];
            array[j] = tmp;
        }
    }
}

#include <iostream>
#include <fstream>
#include "Person.h"
#include "Vector.h"
#include <windows.h>

#define ERROR_OPEN_FILE "\nОшибка! Не удалось открыть файл.\n"
#define ERROR_REALLOC "\nОшибка! Перевыделение памяти.\n"
#define ERROR_STRING "Ошибка! Строка некорректна."
#define ERROR_BAD_COUNT "\nОшибка! Неверное количество строк.\n"

enum sortType {
    lastName = 1, firstName = 2, yearOfBirth = 3, all = 4, uniqueNames = 5, getYear = 6
};

int deleteInvalidPers(Person**, int);
void printPersons(Person**, int);

template <typename T>
void sortDinamicArray(T**, int, int);


int main() {
    SetConsoleOutputCP(CP_UTF8);
    try {
        String inputFileName;
        std::cout << "Введите путь до файла с входными данными: "; std::cin >> inputFileName;
        std::cout << '\n';
        std::ifstream inputFile(inputFileName.getCString());
        if (!inputFile.is_open())throw ERROR_OPEN_FILE;

        int strCount;
        inputFile >> strCount;

        int strSize = 0, wordCount = 0, letCount = 0, persCount = 0;
        char ch;
        char* strNew, *str = NULL;
        char* word;

        Vector<Person> array(strCount);

        inputFile.get(ch);
        for (int i = 0; i < strCount; i++) {
            strSize = 0;
            str = NULL;
            do {
                inputFile.get(ch);
                if (ch != '\n' && ch != '\0' && !inputFile.eof()) {
                    strSize++;
                    strNew = (char*)realloc(str, strSize * sizeof(char));
                    if (strNew != NULL) {
                        str = strNew;
                        str[strSize-1] = ch;
                    }
                    else {
                        free(str);
                        throw ERROR_REALLOC;
                    }
                }
                else {
                    str[strSize] = '\0';
                }
            } while (ch != '\n' && ch != '\0' && !inputFile.eof());

            std::cout << i + 1 << ": ";
            for (int j = 0; j < strSize; j++)std::cout << str[j];
            std::cout << '\n';

            if (strSize < 11) {
                std::cout << ERROR_STRING <<'\n';
                continue;
            }

            word = new char[21];
            wordCount = 0;
            letCount = 0;
            for (int j = 0; j < strSize; j++) {
                ch = str[j];
                if(ch != ' ') {
                    if (wordCount == 3) {
                        wordCount++;
                        std::cout << ERROR_STRING <<'\n';
                        break;
                    }
                    if (letCount != 20) {
                        word[letCount] = ch;
                        letCount++;
                    }
                    else {
                        std::cout << ERROR_STRING << '\n';
                        break;
                    }
                    if (j != strSize) {
                        if (str[j + 1] == ' ' || j+1 == strSize)
                        {
                            word[letCount] = '\0';
                            switch (wordCount) {
                                case 0:
                                    array[persCount].setLastName(word);
                                case 1:
                                    array[persCount].setFirstName(word);
                                case 2:
                                    array[persCount].setYearOfBirth(word);
                            }
                            wordCount++;
                            letCount = 0;
                        }
                    }
                }
            }
            delete[] word;
            if(wordCount == 3)persCount++;
            if (inputFile.eof()) {
                if (i != strCount-1) {
                    inputFile.close();
                    throw ERROR_BAD_COUNT;
                }
            }
        }
        if (!inputFile.eof()) {
            inputFile.close();
            throw ERROR_BAD_COUNT;
        }
        inputFile.close();


        bool atLeastOneValidPerson = false;

        std::cout << '\n';
        for (int i = 0; i < array.getLenght(); i++) {
            if(!checkData(array[i])) {
                std::cout << i + 1 << " - некорректные данные.\n";
                array.deleteElem(i);
            }
            else
                atLeastOneValidPerson = true;
        }

        if (atLeastOneValidPerson) {
            array.deleteInvalid();
            persCount = array.getLenght();

            sortDinamicArray(array.getData(), persCount, uniqueNames);
            sortDinamicArray(array.getData(), persCount, yearOfBirth);

            std::cout << "\nСортировка по году рождения:\n";
            printPersons(array.getData(), persCount);
            sortDinamicArray(array.getData(), persCount, getYear);

            sortDinamicArray(array.getData(), persCount, all);
            std::cout << "\n\nСортировка по Имени, году рождения, фамилии:\n";
            printPersons(array.getData(), persCount);

            String outputFileName;
            std::cout << "\nВведите путь до файла с выходными данными: "; std::cin >> outputFileName;
            std::fstream outputFile(outputFileName.getCString());
            if (!outputFile.is_open())throw ERROR_OPEN_FILE;
            outputFile << persCount <<'\n';
            for (int i = 0; i < persCount; i++) {
                outputFile << array[i].getLastName() << ' ' << array[i].getFirstName() <<' '<< array[i].getYearOfBirth();
                if (i != persCount - 1)outputFile << '\n';
            }
            outputFile.close();
        }
        else {
            std::cout << "\nНет валидных персон для вывода!\n";
        }
        array.erase();
    }
    catch (const char* error) {
        std::cout << error<<"Ошибка.\n";
        return -1;
    }

    std::cout << "Завершение работы программы.\n";
    return 0;
}

void printPersons(Person** arr, int count) {
    for (int i = 0; i < count; i++) {
        std::cout << "Персона " << i + 1 << ": " << arr[i]->getLastName() << ' ';
        std::cout << arr[i]->getFirstName() << ' ';
        std::cout << arr[i]->getYearOfBirth() << '\n';
    }
}

template<typename T>
void sortDinamicArray(T** array, int count, int type) {
    if (type > 6 || type < 1) {
        std::cout<<"Неверное задание сортировки!\n";
        return;
    }
    T* temp;
    int item;
    if (type == 4) {
        for (int i = 1; i < count; i++) {
            temp = array[i];
            item = i - 1;
            while (item >= 0 && (array[item]->compareFNames(*temp) == 1 || (array[item]->compareFNames(*temp) >= 0 && array[item]->compareYBirth(*temp) == 1) || (array[item]->compareFNames(*temp) >= 0 && array[item]->compareYBirth(*temp) >= 0 && array[item]->compareLNames(*temp) == 1))) {
                array[item + 1] = array[item];
                array[item] = temp;
                item--;
            }
        }
    }
    else if(type == 1) {
        for (int i = 1; i < count; i++) {
            temp = array[i];
            item = i - 1;
            while (item >= 0 && array[item]->compareLNames(*temp) == 1) {
                array[item + 1] = array[item];
                array[item] = temp;
                item--;
            }
        }
    }
    else if(type == 2) {
        for (int i = 1; i < count; i++) {
            temp = array[i];
            item = i - 1;
            while (item >= 0 && array[item]->compareFNames(*temp) == 1) {
                array[item + 1] = array[item];
                array[item] = temp;
                item--;
            }
        }
    }
    else if (type == 3) {
        for (int i = 1; i < count; i++) {
            temp = array[i];
            item = i - 1;
            while (item >= 0 && array[item]->compareYBirth(*temp) == 1) {
                array[item + 1] = array[item];
                array[item] = temp;
                item--;
            }
        }
    }
    else if (type == 5) {
        int namesCount = 1;
        temp = array[0];
        for (int i = 1; i < count; i++) {
            if (array[i]->compareFNames(*temp) != 0) {
                namesCount++;
                temp = array[i];
            }
        }
        std::cout << "\nУникальных имён: " << namesCount << '\n';
    }
    else if (type == 6) {
        int year, yearMax = 0;
        int countMax = 0, countCur;
        for (int i = 0; i < count - 1; i++) {
            countCur = 0;
            year = 0;
            for (int j = i + 1; j < count; j++) {
                if (array[i]->compareYBirth(*(array[j])) == 0) {
                    if (array[i]->compareFNames(*(array[j])) == 0 && array[i]->compareLNames(*(array[j])) == 0) {
                        year = atoi(array[i]->getYearOfBirth().getCString());
                        countCur++;
                    }
                }
                else {
                    if (countCur > countMax) {
                        yearMax = year;
                        countMax = countCur;
                    }
                    break;
                }
                if (yearMax == -1)break;
            }
        }
        if (yearMax == 0)
            std::cout << "\nИмена и фамилии не повторяются в пределах года.\n";
        else
            std::cout << "\nГод, в который родилось больше всего персон с одинаковыми именами и фамилиями: " << yearMax;
    }
}


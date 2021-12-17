#include <iostream>
#include <fstream>
#include <string>
#include "String.h"
#include "Array.h"
#include "Person.h"

//typedef std::string String;

template <class T>
void floatSort(Array<T>& forSort);

template <class TString>
size_t differentNames(const Array<Person<TString>>& persons);

template <class TString>
bool isEqualSurnameInOneYear(const Array<Person<TString>>& persons);

int main()
{
    setlocale(LC_ALL, "ru");
    
    String finName;
    String foutName;

    std::cout << "Enter source file name: ";
    getline(std::cin, finName);
    std::cout << "Enter source file name: ";
    getline(std::cin, foutName);
    std::cout << '\n';

    std::ifstream fin(finName);
    std::ofstream fout(foutName);
    if (!fin.good())
    {
        std::cerr << "Error while opening a source file\n";
        return -1;
    }

    String dataCountString;
    getline(fin, dataCountString);
    unsigned int dataCount = 0;

    for (int i = 0; i < dataCountString.size(); ++i)
    {
        dataCount += (dataCountString[i] - '0') * static_cast<unsigned int>(pow(10, dataCountString.size() - i - 1));
    }

    Array<Person<String>> persons(dataCount);
    
    try
    {
        for (size_t i = 0; i < dataCount; ++i) {
            String personData;
            getline(fin, personData);

            size_t index = 0;

            String surname;
            while (personData[index] != ' ')
            {
                surname += personData[index];
                ++index;
            }
            while (personData[index] == ' ')
            {
                ++index;
            }

            String name;
            while (personData[index] != ' ')
            {
                name += personData[index];
                ++index;
            }
            while (personData[index] == ' ')
            {
                ++index;
            }

    
            String birthYear;
            while (personData[index] != ' ')
            {
                birthYear += personData[index];
                ++index;
                if (index == personData.size())
                {
                    break;
                }
            }

            persons[i].setSurname(surname);
            persons[i].setName(name);
            persons[i].setBirthYear(birthYear);
        }

        floatSort(persons);
        fout << dataCount << std::endl;
        for (int i = 0; i < dataCount; ++i) {
            fout << persons[i] << std::endl;
        }

        std::cout << '\n';
        std::cout << "Unical names count: " << differentNames(persons) << std::endl;
        std::cout << (isEqualSurnameInOneYear(persons) ? "There IS persons with equal birth years and surnames" : "There is NO persons with equal birth years and surnames") << std::endl;
    }
    catch (std::invalid_argument error) {
        std::cerr << error.what() << std::endl;
        return -1;
    }
    catch (std::out_of_range error) {
        std::cerr << error.what() << std::endl;
        return -1;
    }

    fin.close();
    fout.close();

    return 0;
}

template<class T>
void floatSort(Array<T>& forSort)
{
    for (size_t i = 0; i < forSort.getSize(); ++i)
    {
        for (size_t j = 0; j < forSort.getSize() - i - 1; ++j) {
            if (forSort[j] > forSort[j + 1]) {
                forSort.swapElements(j, j + 1);
            }
        }
    }
}

template<class TString>
size_t differentNames(const Array<Person<TString>>& persons)
{
    Array<TString> unicNames;
    for (size_t i = 0; i < persons.getSize(); ++i)
    {
        bool unic = true;
        for (size_t j = 0; j < unicNames.getSize() && unic; ++j)
        {
            if (persons[i].getName().compare(unicNames[j]) == 0)
            {
                unic = false;
            }
        }
        if (unic)
        {
            unicNames.addElement(persons[i].getName());
        }
    }

    return unicNames.getSize();
}

template<class TString>
bool isEqualSurnameInOneYear(const Array<Person<TString>>& persons)
{
    for (size_t i = 0; i < persons.getSize(); ++i)
    {
        int equalNameInOneYearNumber = 0;
        for (size_t j = 0; j < persons.getSize(); ++j)
        {
            if (persons[i].getBirthYear().compare(persons[j].getBirthYear()) == 0)
            {
                ++equalNameInOneYearNumber;
            }
            if (equalNameInOneYearNumber > 1)
            {
                return true;
            }
        }
    }
    
    return false;
}
//Variant 1.1
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>


//class
//class String
//{
//public:
//    String()
//    {
//        stroka.clear();
//    }
//    String & operator=(const String& right);
//private:
//    std::vector <char> stroka;
//};
//
//String& operator=(const String& right)
//{
//    this->clear();
//}



class Person
{
public:

    Person()
    {
        surname = "";
        name = "";
        year = "";
    }

    Person(std::string Surname, std::string Name, std::string Year)
    {
        this->surname = Surname;
        this->name = Name;
        this->year = Year;
    }
    template < typename T >
    Person* sort_person(T* arr, int size);

    void setSurname(std::string Surname) { surname = Surname; }
    void setName(std::string Name) { name = Name; }
    void setYear(std::string Year) { year = Year; }
    std::string getInfo() { return surname + " " + name + " " + year + "\n"; }
    std::string getSurname() { return surname; }
    std::string getName() { return name; }
    std::string getYear() { return year; }
    Person& operator=(const Person& right);
private:
    std::string surname;
    std::string name;
    std::string year;
};

Person& Person::operator=(const Person& right)
{
    surname = right.surname;
    name = right.name;
    year = right.year;
    return *this;
}

//
//Task 1
//
template < typename T > //шаблонная сортировка
Person* sort_person(T* arr, int size)
{
    Person temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j].getSurname() > arr[j + 1].getSurname())
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            else
            {
                if (arr[j].getSurname() == arr[j + 1].getSurname())
                {
                    if (arr[j].getName() > arr[j + 1].getName())
                    {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                    else
                    {
                        if (arr[j].getName() == arr[j + 1].getName())
                        {
                            if (arr[j].getYear() > arr[j + 1].getYear())
                            {
                                temp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                            }
                        }
                    }
                }
            }
        }
    }
    return arr;
}

//functions
bool isFileNameOK(std::string line);
std::string findSurname(std::string line);
std::string findName(std::string line, std::string line2);
std::string findYear(std::string line);
int Find_person_quant(Person arr[], int number);
int Find_person_SurName_quant(Person arr[], int number);

//errors
const char* ERROR_FILE_INPUT_NOT_OPEN = "The input file was not open!\n";
const char* ERROR_FILE_OUTPUT_NOT_OPEN = "The output file was not open!\n";
const char* ERROR_FILE_NAME_ENTER = "Incorrect file name entered!\n";
const char* ERROR_INVALID_INPUT = "Invalid number was entered, end of the program!\n";
const char* ERROR_WRONG_SURNAME_ENTERED = "Wrong surname entered, end of the program!\n";
const char* ERROR_WRONG_NAME_ENTERED = "Wrong name entered, end of the program!\n";
const char* ERROR_WRONG_YEAR = "Wrong year entered, end of the program!\n";


//main
int main()
{
    std::string inpname = "input.txt", outname = "output.txt";
    std::cout << "Entering the name of the input file (with .txt): ";
    std::getline(std::cin, inpname);
    try
    {
        if (isFileNameOK(inpname) != true)
        {
            throw ERROR_FILE_NAME_ENTER;
        }
        std::cout << "Entering the name of the output file (with .txt): ";
        std::getline(std::cin, outname);
        if (isFileNameOK(outname) != true)
        {
            throw ERROR_FILE_NAME_ENTER;
        }
    }
    catch (const char* error)
    {
        std::cerr << error;
        return -1;
    }
    std::ifstream input(inpname, std::ios_base::in | std::ios::binary);
    std::ofstream output(outname, std::ios_base::out | std::ios::binary);
    try
    {
        if (!input.is_open())
        {
            throw ERROR_FILE_INPUT_NOT_OPEN;
        }
        if (!output.is_open())
        {
            throw ERROR_FILE_OUTPUT_NOT_OPEN;
        }
    }
    catch (const char* error)
    {
        std::cerr << error;
        return -1;
    }

    int number = 0;
    input >> number;
    try
    {
        if ((!input) or input.fail())
        {
            throw ERROR_INVALID_INPUT;
        }
    }
    catch (const char* error)
    {
        std::cerr << error;
        return -1;
    }
    Person* array = new Person[number];
    std::string line = "";
    std::getline(input, line);

    for (int i = 0; i < number; i++)
    {
        std::string line = "";
        std::getline(input, line);
        try
        {
            if (findSurname(line) != "-1")
                array[i].setSurname(findSurname(line));
            else
                throw ERROR_WRONG_SURNAME_ENTERED;

            if (findName(line, findSurname(line)) != "-1")
                array[i].setName(findName(line, findSurname(line)));
            else
                throw ERROR_WRONG_NAME_ENTERED;

            if (findYear(line) != "-1")
                array[i].setYear(findYear(line));
            else
                throw ERROR_WRONG_YEAR;
        }
        catch (const char* error)
        {
            std::cerr << error;
            return -1;
        }
    }
    array = sort_person(array, number);
    output << "Correctly ordered information by last name, first name, year of birth: \n";
    for (int i = 0; i < number; i++)
    {
        output << array[i].getInfo();
    }
    output << "\nNumber of different last names contained in the file: \n";
    output << Find_person_quant(array, number) << "\n";

    output << "\nNumber of persons with matching first and last names: \n";
    output << Find_person_SurName_quant(array, number) << "\n";
    output.close();
    input.close();
    delete[] array;
    return 0;
}

//
//functions realize
//
std::string findSurname(std::string line)
{

    int i = 0, num = 0;
    std::string line1 = "";
    while (line[i] != ' ')
    {
        if (line[i] == '-')
            num++;
        line1 += line[i];
        i++;
    }
    if (!((line1.size() > 2) and (line1.size() < 21)))
        return "-1";
    if ((line1[0] >= 'A') and (line1[0] <= 'Z') and (num < 2))
    {
        for (i = 1; i < line1.size(); i++)
        {
            if (!(((line1[i] >= 'a') and (line1[i] <= 'z')) or ((line1[i] == '-') and ((line1[i - 1] >= 'a') and (line1[i - 1] <= 'z')) and ((line1[i + 1] >= 'a') and (line1[i + 1] <= 'z')))))
                return "-1";
        }
        return line1;
    }
    else
    {
        return "-1";
    }
}

std::string findName(std::string line, std::string line2)
{

    int i = line2.size(), num = 0;
    std::string line1 = "";
    while (line[i] == ' ')
        i++;
    while (line[i] != ' ')
    {
        if (line[i] == '-')
            num++;
        line1 += line[i];
        i++;
    }

    if ((!((line1.size() > 1) and (line1.size() < 11))) or (num != 0))
        return "-1";
    if ((line1[0] >= 'A') and (line1[0] <= 'Z'))
    {
        for (i = 1; i < line1.size(); i++)
        {
            if (!(((line1[i] >= 'a') and (line1[i] <= 'z'))))
                return "-1";
        }
        return line1;
    }
    else
    {
        return "-1";
    }
}

std::string findYear(std::string line)
{
    int i = 0;
    std::string line1 = "";
    while (!((line[i] >= '0') and (line[i] <= '9')))
    {
        i++;
    }
    while ((line[i] >= '0') and (line[i] <= '9') and (i < line.size()))
    {
        line1 = line1 + line[i];
        i++;
    }
    if (line1.size() != 4)
        return "-1";
    return line1;
}

bool isFileNameOK(std::string line)
{
    if ((line[line.size() - 1] == 't') and (line[line.size() - 2] == 'x') and (line[line.size() - 3] == 't') and (line[line.size() - 4] == '.'))
    {
        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] == ' ')
            {
                return 0;
            }
        }
    }
    else
    {
        return 0;
    }
    return 1;
}




//
//Task 2 
//
int Find_person_quant(Person arr[], int number)
{
    std::list <std::string> pers_list;
    for (int i = 0; i < number; i++)
    {
        pers_list.push_back(arr[i].getSurname());
    }
    pers_list.unique();                            //отчистил от повторений
    return pers_list.size();

}


//
//Task 3
//
int Find_person_SurName_quant(Person arr[], int number)
{
    int k = 1;
    for (int i = 0; i < number - 1; i++)
    {
        if (arr[i].getSurname() == arr[i + 1].getSurname())
        {
            k++;
        }
    }
    return k;
}
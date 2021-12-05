//Variant 1.1
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <list>
#include <vector>



class String
{
    char* data;    
    unsigned length;  

public:

    String();


    String(char c);


    String(const char* c);

    String(const String& s);

    ~String();

    int len() const;
    void togglecase(unsigned first, unsigned last);
    friend std::ostream& operator<< (std::ostream& so, const String& s);
    friend std::istream& operator>> (std::istream& so, String& s);
    char  operator[] (unsigned j) const;
    char& operator[] (unsigned j);
    String& operator= (const String& s);
    String& operator+= (const String& s);
    friend String operator+ (const String& lhs, const String& rhs);
    friend String operator+ (const String& lhs, char          rhs);
    friend String operator+ (const String& lhs, const char* rhs);
    friend String operator+ (char          lhs, const String& rhs);
    friend String operator+ (const char* lhs, const String& rhs);
    friend bool operator== (const String& lhs, const String& rhs);
    friend bool operator== (const String& lhs, char          rhs);
    friend bool operator== (const String& lhs, const char* rhs);
    friend bool operator== (char          lhs, const String& rhs);
    friend bool operator== (const char* lhs, const String& rhs);
    friend bool operator> (const String& lhs, const String& rhs);
    friend bool operator> (const String& lhs, char          rhs);
    friend bool operator> (const String& lhs, const char* rhs);
    friend bool operator> (char          lhs, const String& rhs);
    friend bool operator> (const char* lhs, const String& rhs);
    friend bool operator!= (const String& lhs, const String& rhs);
    friend bool operator!= (const String& lhs, char          rhs);
    friend bool operator!= (const String& lhs, const char* rhs);
    friend bool operator!= (char          lhs, const String& rhs);
    friend bool operator!= (const char* lhs, const String& rhs);
    friend bool operator< (const String& lhs, const String& rhs);
    friend bool operator< (const String& lhs, char          rhs);
    friend bool operator< (const String& lhs, const char* rhs);
    friend bool operator< (char          lhs, const String& rhs);
    friend bool operator< (const char* lhs, const String& rhs);
    friend bool operator<= (const String& lhs, const String& rhs);
    friend bool operator<= (const String& lhs, char          rhs);
    friend bool operator<= (const String& lhs, const char* rhs);
    friend bool operator<= (char          lhs, const String& rhs);
    friend bool operator<= (const char* lhs, const String& rhs);
    friend bool operator>= (const String& lhs, const String& rhs);
    friend bool operator>= (const String& lhs, char          rhs);
    friend bool operator>= (const String& lhs, const char* rhs);
    friend bool operator>= (char          lhs, const String& rhs);
    friend bool operator>= (const char* lhs, const String& rhs);
    //@}
};

String::String()
{
    length = 0;
    data = new char[0];
}

String::String(char c)
{
    length = 1;
    data = new char(c);
}

String::String(const char* c)
{
    if (c)
    {
        unsigned n = 0;
        while (c[n] != '\0') n++;
        length = n;
        data = new char[n];
        for (unsigned j = 0; j < n; j++)
            data[j] = c[j];
    }
    else
    {
        length = 0;
        data = new char[0];
    }
}

String::String(const String& s)
{
    length = s.len();
    data = new char[length];
    for (unsigned j = 0; j < length; j++)
        data[j] = s[j];
}



String::~String()
{
    delete[] data;
}



int String::len() const
{
    return length;
}


void String::togglecase(unsigned first, unsigned last)
{
    if ((first >= last) || (last > length)) throw 1;

    for (unsigned j = first; j < last; j++)
        if ('A' <= data[j] && data[j] <= 'Z')
            data[j] += ('a' - 'A');
        else if ('a' <= data[j] && data[j] <= 'z')
            data[j] -= ('a' - 'A');
}



std::ostream& operator<< (std::ostream& os, const String& s)
{
    if (s.len() > 0)
    {
        for (unsigned j = 0; j < s.len(); j++)
            os << s[j];
    }
    else os << "";

    return os;
}

std::istream& operator>> (std::istream& is, String& s)
{
    char* c = new char[1000];
    is >> c;
    s = String(c);
    delete[] c;

    return is;
}



char String::operator[] (unsigned j) const
{
    if (j >= length) throw 1;
    return data[j];
}

char& String::operator[] (unsigned j)
{
    return data[j];
}



String& String::operator= (const String& s)
{
    if (this == &s) return *this;

    delete data;
    length = s.len();
    data = new char[length];
    for (unsigned j = 0; j < length; j++)
        data[j] = s[j];
    return *this;
}



String& String::operator+= (const String& s)
{
    unsigned len = length + s.len();
    char* str = new char[len];

    for (unsigned j = 0; j < length; j++)
        str[j] = data[j];

    for (unsigned i = 0; i < s.len(); i++)
        str[length + i] = s[i];

    delete data;
    length = len;
    data = str;
    return *this;
}



String operator+ (const String& lhs, const String& rhs)
{
    return String(lhs) += rhs;
}

String operator+ (const String& lhs, char rhs)
{
    return String(lhs) += String(rhs);
}

String operator+ (const String& lhs, const char* rhs)
{
    return String(lhs) += String(rhs);
}

String operator+ (char lhs, const String& rhs)
{
    return String(lhs) += rhs;
}
String operator+ (const char* lhs, const String& rhs)
{
    return String(lhs) += rhs;
}



bool operator== (const String& lhs, const String& rhs)
{
    if (lhs.len() != rhs.len()) return false;

    unsigned cap = lhs.len();
    unsigned   n = 0;
    while ((n < cap) && (lhs[n] == rhs[n])) n++;
    return (n == cap);
}

bool operator== (const String& lhs, char rhs)
{
    return (lhs == String(rhs));
}

bool operator== (const String& lhs, const char* rhs)
{
    return (lhs == String(rhs));
}

bool operator== (char lhs, const String& rhs)
{
    return (String(lhs) == rhs);
}

bool operator== (const char* lhs, const String& rhs)
{
    return (String(lhs) == rhs);
}



bool operator> (const String& lhs, const String& rhs)
{
    unsigned cap = (lhs.len() < rhs.len()) ? lhs.len() : rhs.len();
    unsigned n = 0;
    while ((n < cap) && (lhs[n] == rhs[n])) n++;
    if (n == cap) return (lhs.len() > rhs.len());

    if ((('A' <= lhs[n] && lhs[n] <= 'Z') || ('a' <= lhs[n] && lhs[n] <= 'z')) &&
        (('A' <= rhs[n] && rhs[n] <= 'Z') || ('a' <= rhs[n] && rhs[n] <= 'z')))
    {
        char A = (lhs[n] & ~32);
        char B = (rhs[n] & ~32);
        if (A != B) return (A > B);
    }
    return lhs[n] > rhs[n];
}

bool operator> (const String& lhs, char rhs)
{
    return (lhs > String(rhs));
}

bool operator> (const String& lhs, const char* rhs)
{
    return (lhs > String(rhs));
}

bool operator> (char lhs, const String& rhs)
{
    return (String(lhs) > rhs);
}

bool operator> (const char* lhs, const String& rhs)
{
    return (String(lhs) > rhs);
}



bool operator!= (const String& lhs, const String& rhs)
{
    return !(lhs == rhs);
}

bool operator!= (const String& lhs, char rhs)
{
    return !(lhs == rhs);
}

bool operator!= (const String& lhs, const char* rhs)
{
    return !(lhs == rhs);
}

bool operator!= (char lhs, const String& rhs)
{
    return !(lhs == rhs);
}

bool operator!= (const char* lhs, const String& rhs)
{
    return !(lhs == rhs);
}



bool operator< (const String& lhs, const String& rhs)
{
    return !(lhs == rhs) && !(lhs > rhs);
}

bool operator< (const String& lhs, char rhs)
{
    return !(lhs == rhs) && !(lhs > rhs);
}

bool operator< (const String& lhs, const char* rhs)
{
    return !(lhs == rhs) && !(lhs > rhs);
}

bool operator< (char lhs, const String& rhs)
{
    return !(lhs == rhs) && !(lhs > rhs);
}

bool operator< (const char* lhs, const String& rhs)
{
    return !(lhs == rhs) && !(lhs > rhs);
}



bool operator<= (const String& lhs, const String& rhs)
{
    return !(lhs > rhs);
}

bool operator<= (const String& lhs, char rhs)
{
    return !(lhs > rhs);
}

bool operator<= (const String& lhs, const char* rhs)
{
    return !(lhs > rhs);
}

bool operator<= (char lhs, const String& rhs)
{
    return !(lhs > rhs);
}

bool operator<= (const char* lhs, const String& rhs)
{
    return !(lhs > rhs);
}



bool operator>= (const String& lhs, const String& rhs)
{
    return (lhs == rhs) || (lhs > rhs);
}

bool operator>= (const String& lhs, char rhs)
{
    return (lhs == rhs) || (lhs > rhs);
}

bool operator>= (const String& lhs, const char* rhs)
{
    return (lhs == rhs) || (lhs > rhs);
}

bool operator>= (char lhs, const String& rhs)
{
    return (lhs == rhs) || (lhs > rhs);
}

bool operator>= (const char* lhs, const String& rhs)
{
    return (lhs == rhs) || (lhs > rhs);
}


//    
//
//
//  Class Person
//
//

class Person
{
public:

    template < typename T >
    Person* sort_person(T* arr, int size);

    Person()
    {
        surname = "";
        name = "";
        year = "";
    }

    Person(String Surname, String Name, String Year)
    {
        this->surname = Surname;
        this->name = Name;
        this->year = Year;
    }

    void setSurname(String Surname) { surname = Surname; }
    void setName(String Name) { name = Name; }
    void setYear(String Year) { year = Year; }
    String getInfo() { return surname + " " + name + " " + year + "\n"; }
    String getSurname() { return surname; }
    String getName() { return name; }
    String getYear() { return year; }
    Person& operator=(const Person& right);
private:
    String surname;
    String name;
    String year;
};

Person& Person::operator=(const Person& right)
{
    surname = right.surname;
    name = right.name;
    year = right.year;
    return *this;
}

template < typename T >
Person* sort_person(T* arr, int size)
{
    T temp;
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
bool isFileNameOK(String line);
String findSurname(String line);
String findName(String line, String line2);
String findYear(String line);
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
    String inpname = "input.txt", outname = "output.txt";
    std::cout << "Entering the name of the input file (with .txt): ";
    std::cin >> inpname;
    try
    {
        if (isFileNameOK(inpname) != true)
        {
            throw ERROR_FILE_NAME_ENTER;
        }
        std::cout << "Entering the name of the output file (with .txt): ";
        std::cin >> outname;
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
    char* inpname1 = new char[inpname.len() + 1];
    char* outname1 = new char[inpname.len() + 1];


    for (int i = 0; i < inpname.len(); i++)
    {
        inpname1[i] = inpname[i];
    }
    inpname1[inpname.len()] = '\0';

    for (int i = 0; i < outname.len(); i++)
    {
        outname1[i] = outname[i];
    }
    outname1[outname.len()] = '\0';
    std::ifstream input(inpname1, std::ios_base::in | std::ios::binary);
    std::ofstream output(outname1, std::ios_base::out | std::ios::binary);
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
    String line = "", line1 = "", line2 = "", line3 = "";


    for (int i = 0; i < number; i++)
    {
        String line = "";
        input >> line >> line1 >> line2;
        line3 = line + " " + line1 + " " + line2;
        try
        {
            if (findSurname(line3) != "-1")
                array[i].setSurname(findSurname(line3));
            else
                throw ERROR_WRONG_SURNAME_ENTERED;

            if (findName(line3, findSurname(line3)) != "-1")
                array[i].setName(findName(line3, findSurname(line3)));
            else
                throw ERROR_WRONG_NAME_ENTERED;

            if (findYear(line3) != "-1")
                array[i].setYear(findYear(line3));
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
String findSurname(String line)
{

    int i = 0, num = 0;
    String line1 = "";
    while (line[i] != ' ')
    {
        if (line[i] == '-')
            num++;
        line1 += line[i];
        i++;
    }
    if (!((line1.len() > 2) and (line1.len() < 21)))
        return "-1";
    if ((line1[0] >= 'A') and (line1[0] <= 'Z') and (num < 2))
    {
        for (i = 1; i < line1.len(); i++)
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

String findName(String line, String line2)
{

    int i = line2.len(), num = 0;
    String line1 = "";
    while (line[i] == ' ')
        i++;
    while (line[i] != ' ')
    {
        if (line[i] == '-')
            num++;
        line1 += line[i];
        i++;
    }

    if ((!((line1.len() > 1) and (line1.len() < 11))) or (num != 0))
        return "-1";
    if ((line1[0] >= 'A') and (line1[0] <= 'Z'))
    {
        for (i = 1; i < line1.len(); i++)
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

String findYear(String line)
{
    int i = 0;
    String line1 = "";
    while (!((line[i] >= '0') and (line[i] <= '9')))
    {
        i++;
    }
    while ((line[i] >= '0') and (line[i] <= '9') and (i < line.len()))
    {
        line1 = line1 + line[i];
        i++;
    }
    if (line1.len() != 4)
        return "-1";
    return line1;
}

bool isFileNameOK(String line)
{
    if ((line[line.len() - 1] == 't') and (line[line.len() - 2] == 'x') and (line[line.len() - 3] == 't') and (line[line.len() - 4] == '.'))
    {
        for (int i = 0; i < line.len(); i++)
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
    std::list <String> pers_list;
    for (int i = 0; i < number; i++)
    {
        pers_list.push_back(arr[i].getSurname());
    }
    pers_list.unique();                            
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
        if ((arr[i].getSurname() == arr[i + 1].getSurname()) and (arr[i].getName() == arr[i + 1].getName()))
        {
            k++;
        }
    }
    return k;
}
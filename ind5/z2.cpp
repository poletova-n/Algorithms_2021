#include <iostream>
#include <fstream>

using namespace std;

const char* ERROR_INPUT_FILE_NOT_FOUND = "Error: input file not found.";

const char* ERROR_OUTPUT_FILE_NOT_FOUND = "Error: output file not found.";

void setArray(int** &array, int sizeX, int sizeY, ifstream &input);

void ans( int**& array, int sizeX, int sizeY);

void outArray(int** &array, int sizeX, int sizeY, ofstream &output);

int main() {
    try {
        ifstream input("C:\\Users\\miha1\\CLionProjects\\Algorithms_2021\\ind5\\input2");

        if (!input.is_open()) {
            throw ERROR_INPUT_FILE_NOT_FOUND;
        }

        int sizeX(0);
        int sizeY(0);

        int** array;

        input >> sizeX;
        input >> sizeY;

        setArray(array, sizeX, sizeY,input);

        input.close();

        ofstream output("C:\\Users\\miha1\\CLionProjects\\Algorithms_2021\\ind5\\output2");
        ans( array, sizeX, sizeY);
        outArray(array, sizeX, sizeY, output);
        if (!output.is_open()) {
            throw ERROR_OUTPUT_FILE_NOT_FOUND;
        }
        output.close();
    }
    catch(const char* error) {
        cerr << endl << error << endl;
        return -1;
    }
}

void setArray(int** &array, int sizeX, int sizeY, ifstream &input) {

    array = new int* [sizeX];

    for (int i = 0; i < sizeX; ++i) {
        int* line = new int[sizeY];
        for (int j = 0; j < sizeY; ++j) {
            input >> line[j];
        }
        array[i] = line;
    }
}

void ans( int**& array, int sizeX, int sizeY) {
    int value(1);
    int minX(0);
    int maxX = sizeX - 1;
    int minY(0);
    int maxY = sizeY - 1;
    while (value <= sizeX * sizeY) {
        for (int i = minY; i <= maxY; ++i) array[i][minX] = value++; //вниз
        for (int i = minX + 1; i <= maxX; ++i) array[maxY][i] = value++; //вправо
        for (int i = maxY - 1; i >= minY; --i) array[i][maxX] = value++; //вверх
        for (int i = maxX - 1; i >= minX + 1; --i) array[minY][i] = value++; //влево
        minX++;
        minY++;
        maxX--;
        maxY--;
    }
}

void outArray(int** &array, int sizeX, int sizeY, ofstream &output) {
    for (int i = 0; i < sizeX; i++) {
        for (int j = 0; j < sizeY; j++) output << array[i][j] << " ";
        output << endl;
    }
}
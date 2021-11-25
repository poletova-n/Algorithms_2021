#include <iostream>
#include <fstream>

using namespace std;

const char* ERROR_INPUT_FILE_NOT_FOUND = "Error: input1 file not found.";

const char* ERROR_OUTPUT_FILE_NOT_FOUND = "Error: output1 file not found.";

const int sizeX(5);

const int sizeY(5);

void setArray(int (&array)[sizeX][sizeY], ifstream &input);

int ans(int (&array)[sizeX][sizeY]);

int main() {
    try {
        int array[sizeX][sizeY];
        ifstream input("C:\\Users\\miha1\\CLionProjects\\Algorithms_2021\\ind5\\input1");
        if (!input.is_open()) {
            throw ERROR_INPUT_FILE_NOT_FOUND;
        }

        setArray(array, input);

        input.close();

        int answer = ans(array);

        std::ofstream output("C:\\Users\\miha1\\CLionProjects\\Algorithms_2021\\ind5\\output1");
        if (!output.is_open()) {
            throw ERROR_OUTPUT_FILE_NOT_FOUND;
        }
        output << answer;

        output.close();
    }
    catch(const char* error) {
        cerr << endl << error << endl;
        return -1;
    }
}

void setArray(int (&array)[sizeX][sizeY], ifstream &input) {
    for (int i = 0; i < sizeX; ++i) {
        for (int j = 0; j < sizeY; ++j) {
            input >> array[i][j];
        }
    }
}

int ans(int (&array)[sizeX][sizeY]) {
    int ans = 0;
    for (int i = 0; i < sizeX; ++i) {
        bool flag = true;
        for (int j = 0; j < sizeY; ++j) {
            if(array[i][j] == 0) {
                flag = false;
            }
        }
        if (flag) ans++;
    }
    return ans;
}

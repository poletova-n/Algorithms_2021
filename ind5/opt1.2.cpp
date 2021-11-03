#include <iostream>
#include <fstream>

char * ERROR_FILE_DIDNT_OPEN = "File didn't open!";

void readFile(int ** &a, int size1, int size2, std::ifstream &fin);

void printFile(int ** &a, int size1, int size2, std::ofstream &fout);

int saddle (int n,int m,int **a,int is,int js);

int *saddle_points (int n, int m, int **a, int &k);


int main () {
    try
    {
        int n=4,m=4;
        int **a;
        std::ifstream fin("C:\\Users\\anush\\Algorithms_2021\\ind5\\inputFile.txt");
        if(!fin.is_open())
        {
            throw ERROR_FILE_DIDNT_OPEN;
        }
        else
        {
            readFile(a, n, m, fin);
        }
        std::ofstream fout("C:\\Users\\anush\\Algorithms_2021\\ind5\\outputFile.txt");
        if(!fout.is_open())
        {
            throw ERROR_FILE_DIDNT_OPEN;
        }
        else
        {
            printFile(a, n, m, fout);
        }
        return 0;
    }
    catch(const char * error)
    {
        std::cerr << std::endl << error << std::endl;
        return -1;
    }
}

void readFile(int ** &a, int size1, int size2, std::ifstream &fin)
{
    a = new int * [size1];
    for (int i = 0; i < size1; i++)
    {
        a[i] = new int [size2];
    }

    for (int i = 0; i < size1 * size2; i++)
    {
        fin >> a[i/size2][i%size2];
    }
}

void printFile(int ** &a, int size1, int size2, std::ofstream &fout)
{
    int k = 0;
    int *s = saddle_points(size1, size2,a,k);
    if (k > 0) {
        for (int i = 0; i < 2*k; i += 2) {
            fout << "A" << "[" << s[i] << "][" << s[i+1] << "] = " << a[s[i]][s[i+1]];
        }
    }
    else
    {
        fout << "Don't have point!";
    }
}

int saddle (int n,int m,int **a,int is,int js) {
    int i, j, min, max;
    min = a[is][0];
    for (j = 0; j < m; j++)
    {
        if (a[is][j]<min)
        {
            min = a[is][j];
        }
    }
    max = a[0][js];
    for (i=0; i < n; i++)
    {
        if (a[i][js] > max)
        {
            max = a[i][js];
        }
    }
    if(a[is][js] == min && a[is][js] == max)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int *saddle_points (int n, int m, int **a, int &k) {
    int i, j;
    k = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) {
            if (saddle(n, m, a, i, j))
            {
                k++;
            }
        }
    if (k==0)
    {
        return NULL;
    }
    int *s = new int [k*2];
    if (s==NULL)
    {
        return NULL;
    }
    int l = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) {
            if (saddle(n, m, a, i, j))
            {
                s[l++] = i; s[l++] = j;
            }
        }
    return s;
}
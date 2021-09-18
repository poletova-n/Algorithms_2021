#include <iostream>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");  //#include <windows.h> SetConsoleOutputCP(CP_UTF8);

    double a;
    double b;
    double c;
    double dsk;
    double x1;
    double x2;
    int x1check;
    int x2check;

    cout << "������� 3 ����� ����� ������ � ������� a b c - (����� ������������ ������ ����� �����)" << endl;
    if (cin >> a >> b >> c) {

        if (cin.peek() == EOF || cin.peek() == '\n')
        {

        }
        else
        {

            cout << endl << "����� ������� ������ ����� �����" << endl;
            cin.ignore(100, '\n');
            cin.clear();
            return 1;

        }
    }
    else
    {
        cin.ignore(100, '\n');
        cin.clear();
        cout << "����� ������� ������ ����� �����";
        return 1;

    }

    if (a == 0) {
        cout << ("���� a = 0, ������ ��� �� ���������� ���������")
            return 1;
    }
    dsk = sqrt((b * b) - (4 * a * c));

    x1 = (-b + dsk) / (2*a);
    x2 = (-b - dsk) / (2*a);

    x1check = (-b + dsk) / (2 * a);
    x2check = (-b - dsk) / (2 * a);

    cout << "�����:" << endl;

    if (x1check == x1) {
        cout << x1 << endl;
    }

    if (x2check == x2) {
        cout << x2;
    }

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian"); //#include <windows.h> SetConsoleOutputCP(CP_UTF8);

    // ���� 3 ��������

    int a;
    int b;
    int c;
    cout << "������� 3 ������� ������������ ����� ������ - (����� ������������ ������ ����� ��������������� �����)" << endl;

    // �������� �����

    if (cin >> a >> b >> c) {

        if (cin.peek() == EOF or cin.peek() == '\n')
        {

        }
        else
        {

            cout << endl << "����� ������������ ������ ����� ��������������� ����� - �� ����� ������� ����� " << endl;
            cin.ignore(100, '\n');
            cin.clear();
            return 1;

        }
    }
    else
    {
        cin.ignore(100, '\n');
        cin.clear();
        cout << "����� ������������ ������ ����� ��������������� ����� - �� ����� �������";
        return 1;

    }

    // �������� �� �����������������

    if ((a < 0) or (b < 0) or (c < 0)) {
        cout << "����� ������������ ������ ����� ��������������� ����� - �� ����� ������������� �����";
        return 1;
    }

    // ��������� �����
        //�������� �� �������������

    if ((a > b + c) or (b > a + c) or (c > b + a)) {
        cout << "����� ����������� �� ����������";
        return 1;
    }

    // ����������� + ������� + ���

    cout << "����������� - ";

    // ���

    if ((a * a == b * b + c * c) or (b * b == a * a + c * c) or (c * c == b * b + a * a)) {

        cout << "�������������";

    }
    else {
        if ((a * a > b * b + c * c) or (b * b > a * a + c * c) or (c * c > b * b + a * a)) {

            cout << "������������";

        }
        else {

            cout << "�������������";

        }

    }

    // �������

    if ((a == b) and (a == c) and (b == c)) {

        cout << ", ��������������.";

    }
    else if ((a == b) or (a == c) or (b == c)) {

        cout << ", ��������������.";

    }

    return 0;
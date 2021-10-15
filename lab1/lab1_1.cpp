#include <iostream>
using namespace std;

int main()
{
    cout << "vvedite koefficienty uravneniya: ";
    double a, b, c, x1, x2; // объявляем коэффициенты и корни
    cin >> a >> b >> c; //вводим значения
    if (cin.fail() || cin.peek() != 10) //проверка введенных чисел
    {
        cout << "vvedite only chisla"; //при неверном вводе
    }
    else
    {
        if (a == 0)
        {
            cout << "v kvadratnom uravnenii x^2 ne mozhet ravnyatsya zero"; //условие квадратного уравнения
        }
        else
        {
            double disc = (b * b) - (4 * a * c); //ищем дискриминант
                double sqrtdis = sqrt(disc); //значение дискриминанта
                if (disc < 0) //если значение дискриминанта меньше нуля, то нет корней
                {
                    cout << "korney net" << endl;
                    return 0;
                }
                if ((sqrtdis * sqrtdis) == disc && (sqrtdis == int(sqrtdis))) // если дискриминант возможно вынести из-под корня
                {
                    if (disc == 0) //если дискриминант равен нулю
                    {
                        x1 = (-b) / (2 * a);
                        cout << "one koren: " << x1 << endl;
                    }
                    else //если дискриминант больше нуля и не равен ему
                    {
                        x1 = (-b + sqrt(disc)) / (2 * a);
                        x2 = (-b - sqrt(disc)) / (2 * a);
                        cout << "first coren: " << x1 << endl;
                        cout << "second coren: " << x2 << endl;
                    }
                }
                else
                {
                    cout << "discriminant ne vynositsya";
                }
        }
    }
}
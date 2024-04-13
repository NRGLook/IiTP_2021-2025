// LR-2-16 Выполнил:Тиханёнок Илья
//Задача 16. Введены два числа.Выведите их НОД и НОК.

#include <iostream>

using namespace std;

int main()
{
     int a, b, NOK, NOD;
    setlocale(LC_ALL, "Rus");

    cout << "Программа повозяет вычислить NOK и NOD введенных пользователем чисел.\nВведем первое число:";
    cin >> a;
    cout << "\nВведем второе число:";
    cin >> b;

    while ((a<=0)||(b<=0)) {
        cout << "NOK и NOD нельзя посчитать для отрицательных чисел.\nПопробуйте снова!A:";
        cin >> a;
        cout << "\nB:";
        cin >> b;
    }

    if (a == b) {
        NOD = a; NOK = a;
    }
    else if (a > b) {
        NOK = a;
        while ((NOK % a) || (NOK % b)) {
            NOK++;
        }
    }
    else {
        NOK = b;
        while ((NOK % a) || (NOK % b))
        {
            NOK++;
        }
    }
    NOD = a * b / NOK;

    cout << "\nNOD(a;b)=" << NOD;
    cout << "\nNOK(a;b)=" << NOK << "\n\n\n";

    return 0;
}


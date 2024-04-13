// LR-2-5 Выполнил:Тиханёнок Илья
//Задача 5.Составить программу используя условный оператор if.

#include <iostream>

using namespace std;

int main()
{
    double Z, a=3.8, b=-25.0, c=5.0, d;
    setlocale(LC_ALL, "Rus");

    cout << "Введите d:";
    cin >> d;

    if (c >= d && a < d) {
        Z = a + b / c;
        cout << "Полученное выражение равно:" << Z;
    }
    else if (c < d && a >= d) {
        Z = a - b / c;
        cout << "Полученное выражение равно:" << Z;
    }
    else {
        Z = 0;
        cout << "Полученное выражение равно:" << Z;
    }

    return 0;

}


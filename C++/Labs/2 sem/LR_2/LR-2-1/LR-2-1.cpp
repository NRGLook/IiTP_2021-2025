// Lab 2.1 Выполнил:Тиханёнок Илья 
/*Задача 1. Заданы два целых числа x и y. Определите, верно ли, что одно из них 
делится на другое без остатка, или нет.*/

#include <iostream>

using namespace std;

int main()
{
    int x, y;
    setlocale(LC_ALL, "Rus");

    cout << "Введите число x:";
    cin >> x;

    cout << "Введите число y:";
    cin >> y;

    if (x % y == 0 || y % x == 0) {
        cout << "Делится без остатка";
    }
    else {
        cout << "Делится с отсатком";
    }

    return 0;

}




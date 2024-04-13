// Lab 2.2 Выполнил:Тиханёнок Илья
/*Задача 2.Меньшее из двух значений переменных целого типа Х и Y заменить 
нулём, а в случае их равенства - заменить нулями оба.*/

#include <iostream>

using namespace std;

int main()
{
    int x, y, k, a, b, c, z;
    setlocale(LC_ALL, "Rus");

    cout << "Введите x,y:";
    cin >> x >> y;

    if (x < y) {
        x = 0;
        cout<< "x равен:" << x << "\n";
    }
    else if(y<x)
    {
        y = 0;
        cout << "\ny равен:" << y;
    }
    else if (x = y) {
        x = 0, y = 0;
        cout <<"x равен:"<< x << ";\ny равен:" << y;
    }

    return 0;

}

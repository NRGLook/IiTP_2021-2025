// LR-3-3 Выполнил:Тиханёнок Илья
//Задание 3:использовать for...Составить программу вычисления значений функции y=sin(x)-cos(x).

#include <iostream>//библиотека ввода-вывода
#include <cmath>

using namespace std;

int main()
{
    int M = 20, A = 0;
    double PI = 3.1415, B = PI / 2, H, Xi=0, y, i=0;
    setlocale(LC_ALL, "Rus");

    cout << "Программа вычисляет значение функции y=sin(x)-cos(x).";

    H = (B - A) / M;

    for (i >= 1;Xi >= A && Xi <= B;++i) {
        Xi = A + i * H;
        y = sin(Xi) - cos(Xi);
        cout << "\nПолученное выражение равно:" << y<<"\n";
    }
 
    return 0;
}


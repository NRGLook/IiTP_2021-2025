// LR-2-6 Выполнил:Тиханёнок Илья
/*Задача 6. Составить программу используя переключатель switch
1)Y=b*c-a*a при N=2
2)Y=b*c при N=56
3)Y=a^7+c при N=7
4)Y=a-b*c при N=3
5)Y=(a+b)^3 при других N*/

#include <iostream>

using namespace std;

int main()
{
    int choice;
    double a = -13.8, b = 8.9, c = 25.0,Y;
    setlocale(LC_ALL, "Rus");

    cout << "Программа определяет значение выражения Y.\n1)Y=b*c-a*a при N=2(ввести 1)\n2)Y = b * c при N = 56(ввести 2)\n3)Y = a ^ 7 + c при N = 7(ввести 3)\n4)Y = a - b * c при N = 3(ввести 4)\n5)Y = (a + b) ^ 3 при других N(ввести 5)\n";
    cin >> choice;

    switch (choice) {
    case 1:
        Y = b * c - a * a;
        break;
    case 2:
        Y = b * c;
        break;
    default:
        Y = pow((a + b), 3);
    case 3:
        Y = pow(a,2) + c;
        break;
    case 4:
        Y = a - b * c;
        break;
    }
    cout << "Полученное выражение равно :" << Y;
    
    return 0;

}


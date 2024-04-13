// LR-3-4 Выполнил:Тиханёнок Илья
/*Задание 4. Вычислить сумму четных чисел на промежутке от 1 до числа, 
введенного пользователем: 4.1 С использованием цикла;4.2 Без использования цикла.*/

#include <iostream>
#include <cmath>
#include <iomanip>//манипуляторы и флаги
#include <cstdlib>//printf-scanf

using namespace std;

long double inputInt()
{
	setlocale(LC_ALL, "Rus");
	long double x;

	cout << "Программа считает сумму четных чисел от 1 до числа введенного пользователем.\nВведём число, до которого хотим посчитать сумму четных чисел :";
	cin >> x;

	while (cin.peek() == ' ')
		cin.ignore(1, ' ');
	while (cin.fail() || cin.peek() != '\n' || x <= 0 || x != (long double)x || x!=round(x)) {
		//cin.peek - не пропускает пробелы
		cin.clear();//очищает
		cin.ignore(10000, '\n');
		cout << "Некорректный ввод.Попробуйте снова.";
		cout << "\nВведите натуральное число:";
		cin >> x;
		while (cin.peek() == ' ')
			cin.ignore(1, ' ');
	}
	return x;
}

int main()
{

    int S1 = 0, i=0;
	int x = inputInt();
    setlocale(LC_ALL, "Rus");

    for (i>=0; i <= x; i++) {
        if (i % 2 == 0) {
            S1 += i;
        }
    }

    cout << "4.1:\nОтвет полученного выражения равен:" << S1;

	//считаю с помощью арифметической прогрессии
    int S2, a1 = 2, an = x, d=2, n;
    n = x / 2;
    S2 = (a1 + an) / 2 * n;

    cout << "\n4.2:\nОтвет полученного выражения равен:" << S2;

    return 0;
}


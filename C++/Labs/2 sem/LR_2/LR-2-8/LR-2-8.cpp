﻿// LR-2-8 Выполнил:Тиханёнок Илья
/*Задача 8. Вычислить значение y в зависимости от выбранной функции f(x),аргумент определяется из поставленного условия.
Возможные значения функции f(x) : 2x, x ^ 3, x / 3(выбор осуществляется используя оператор switch).Предусмотреть вывод сообщений,
показывающих, при каком условии и с какой функцией производились вычисления y.*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double a,b,x,y,f1,f2,f,Z;
	int choice;
	setlocale(LC_ALL, "Rus");

	cout << "Программа позволяет вычислить значение функции.Возможные значения функции f(x) : 2x, x ^ 3, x / 3.\n1)2x;\n2)x^3;\n3)x/3.\n";
	cin >> choice;

	switch (choice) {
	case 1:
		cout << "Для начала область Z ,чтобы работать с x.Введем Z(либо больше , либо меньше 0):";
		cin >> Z;

		if (Z > 0) {
			x = 1 / (Z * Z + 2 * Z);
		}
		else {
			x = 1 - Z * Z * Z;
		}

		cout << "Введите a:";
		cin >> a;
		cout << "Введите b:";
		cin >> b;

	    f1 = 2 * x;
		y = (-3) * x;
		f2 = (2.5 * a * exp(y) - 4 * b * x * x) / (log(x) + f1);
		cout <<"Ответ:" << f2;

		break;

	case 2:
		cout << "Для начала определим область числа Z ,чтобы работать с x.Введем Z(либо больше , либо меньше 0):";
		cin >> Z;

		if (Z  > 0) {
			x = 1 / (Z * Z + 2 * Z);
		}
		else {
			x = 1 - Z * Z * Z;
		}

		cout << "Введите a:";
		cin >> a;
		cout << "Введите b:";
		cin >> b;

		f1 = x * x * x;
		y = (-3) * x;
		f2 = (2.5 * a * exp(y) - 4 * b * x * x) / (log(x) + f1);
		cout << "Ответ:" << f2;

		break;

	case 3:
		cout << "Для начала область Z ,чтобы работать с x.Введем Z(либо больше , либо меньше 0):";
		cin >> Z;

		if (Z  > 0) {
			x = 1 / (Z * Z + 2 * Z);
		}
		else {
			x = 1 - Z * Z * Z;
		}

		cout << "Введите a:";
		cin >> a;
		cout << "Введите b:";
		cin >> b;

		f1 = x / 3;
		y = (-3) * x;
		f2 = (2.5 * a * exp(y) - 4 * b * x * x) / (log(x) + f1);
		cout << "Ответ:" << f2;

		break;

	}

	return 0;

}
	

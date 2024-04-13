//Лабораторная 1,задание 2.Выполнена:Тиханёнок Илья Александрович
/*Составить программу на языке С++ для расчета соотношения. Исходные 
данные ввести с клавиатуры. Вариант – номер по журналу.
Вариант 8
A=lg(x);B=x+e^d;
Y=(A+B)-(C*C)/K*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long double A, B, C, K, x, Y, d;
	setlocale(LC_ALL, "Rus");

	cout << "Вариант 8\nНеобходимо ввести x,C,K,d-чтобы получить ответ данного выражения(Y):\nВведите x:\n";
	cin >> x;

	cout << "\nВведите d:\n";
	cin >> d;

	cout << "\nВведите C:\n";
	cin >> C;

	cout << "\nВведите K:\n";
	cin>> K;

        A = log10(x);
	    B = x + exp(d);
        Y = (A + B) - (C * C) / K;

		cout << "Ответ:Y=" << Y;
		
		return 0;
   
}


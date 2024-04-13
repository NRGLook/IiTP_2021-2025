// LR-3 Выполнил:Тиханёнок Илья
//Задание 1:Использовав цикл while.Найти значение выражения N.

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	int i = 1;
	double  ai, bi, N=0,n;
	setlocale(LC_ALL, "Rus");

	cout << "Программа позволяет вычислить значение выражения N=pow((ai-bi),2).Где первый член i=1.";

	while (i >= 1 && i <= 30) {
		if (i % 2 == 0) { 
			ai = i / 2; bi = powl(i, 3); i = i++; 
		}
		else {
			ai = i; bi = powl(i, 2); i = i++;
		}
		n = powl((ai - bi), 2);
		N = N + n;
	}

	cout << fixed << setprecision(1)<<"\nПолученное выражение равно:" << N;

	return 0;
}

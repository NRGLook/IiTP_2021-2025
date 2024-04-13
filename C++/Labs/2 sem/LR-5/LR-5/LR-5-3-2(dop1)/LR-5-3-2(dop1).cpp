// LR-5-3-2(dop1) Выполнил : Тиханёнок Илья
/*Задание 2:Создать двумерный динамический массив вещественных чисел. Определить, встречаются ли среди них элементы с нулевым значением.
Если встречаются такие элементы, то определить их индексы и общее количество. Переставить элементы этого массива в обратном порядке и вывести на экран.
Использовать функции.*/

#include <iomanip>
#include <iostream>

bool NullCheck(double** arr, const int a, const int b);
void PrintArray(double** arr, const int a, const int b);

int main() {
	std::cout<< "Please, enter integer n and k, numbers of the row and the collumns of the matrix: ";
	int n, m;
	std::cin >> n >> m;

	double** A = new double* [n];
	for (int i = 0; i < n; i++)
		A[i] = new double[m];
	double** A2 = new double* [n];
	for (int i = 0; i < n; i++)
		A2[i] = new double[m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			A[i][j] = (rand() % 5) * 3.1415926;
			if (NullCheck(A, i, j)) std::cout << std::endl << "Array [" << i << "]["<< j << "] = 0";
		}
	}
	std::cout << "\n\nArray A:";
	PrintArray(A, n, m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			A2[i][j] = A[n - 1 - i][m - 1 - j];
	}
	std::cout << "\nThe second array after transportation:";
	PrintArray(A2, n, m);
	std::cout << "\n\n";

	return 0;
}

bool NullCheck(double** arr, const int a, const int b) {
	return (!arr[a][b]);
}
void PrintArray(double** arr, const int a, const int b) {
	std::cout << "\n\n";
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			std::cout << std::setw(8) << std::setfill(' ') << arr[i][j];
		}
		std::cout << std::endl << std::endl;
	}
}
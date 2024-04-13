// LR-5-3-2(dop) Выполнил:Тиханёнок Илья
/* Задание 3: Дан двумерный динамический массив целых чисел.Значения элементов данного массива ввести с клавиатуры. Создать динамический массив 
из элементов, расположенных в четных столбцах данного массива и имеющих нечетное значение. Вычислить среднее арифметическое элементов динамического массива.
Вывести результат на экран.Использовать функции*/

#include<iostream>
#include<iomanip>

bool Checkout(int** arr, const int a, const int b);
double ArithmeticMean(int* arr, const int size);
void PrintArray2(int** arr, const int a, const int b);
void PrintArray1(int* arr, const int size);

int main() {

	std::cout<< "Please, enter integer n and k, numbers of the row and the collumns of the matrix: ";
	int n, m;
	std::cin >>n>> m;

	int** ARR1 = new int* [n];
	for (int i = 0; i < n; i++)
		ARR1[i] = new int[m];

	std::cout <<std::endl<< "Enter elements of matrix: ";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num;
			std::cin>> num;
			ARR1[i][j] = num;
		}
	}

	int pos = -1, number = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (Checkout(ARR1, i, j)) number++;
		}
	}
	int* ARR2 = new int[number];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (Checkout(ARR1, i, j)) {
				pos++;
				ARR2[pos] = ARR1[i][j];
			}
		}

	std::cout<< std::endl << "Your matrix:\n";
	PrintArray2(ARR1, n, m);
	std::cout << std::endl << "Array of the uneven elements of the even columns of the matrix:\n";
	PrintArray1(ARR2, number);

	std::cout << std::endl << "Arithmetic mean of the elements of the dynamic array(2) = " << ArithmeticMean(ARR2, number) << "\n\n\n";
	return 0;
}

bool Checkout(int** arr, const int a, const int b) {
	return ((!(b % 2)) && (arr[a][b] % 2));
}

double ArithmeticMean(int* arr, const int size) {
	int SUM = 0;
	for (int i = 0; i < size; i++) {
		SUM += arr[i];
	}

	return (SUM * 1. / size);
}

void PrintArray2(int** arr, const int a, const int b) {
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			std::cout << std::setw(8) << std::setfill(' ') << arr[i][j];
		}
		std::cout << std::endl;
	}
}

void PrintArray1(int* arr, const int size) {
	for (int pos = 0; pos < size; pos++) {
		std::cout << std::setw(6) << std::setfill(' ') << arr[pos];
	}
}

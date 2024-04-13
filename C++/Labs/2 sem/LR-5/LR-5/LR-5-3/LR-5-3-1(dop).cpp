// LR-5-3 Выполнил:Тиханенок Илья
/*Задание 1:Дан двумерный динамический массив целых чисел А размерностью n  k.Размерность массива(n = 5, k = 6)
ввести с клавиатуры. Значения элементов массива ввести с клавиатуры. Создать динамический массив из элементов,
расположенных на главной диагонали матрицы и имеющих четное значение. Вычислить произведение элементов 
динамического массива.Созданный массив и результат произведения вывести на экран.Использовать функции.*/

#include <iostream>

int input()
{
	int N;

	while (true)
	{
		std::cin >> N;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "The value is not correct.Try again: " << std::endl;
		}
		else
		{
			if (N < 0)
			{
				std::cin.ignore(32767, '\n');
				std::cout << "Try again:" << std::endl;
			}
			else
			{
				std::cin.ignore(32767, '\n');
				break;
			}
		}
	}
	return N;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int n = 0;
	int k = 0;

	std::cout << "Enter the number of rows of a two-dimensional dynamic array: \n";
	n = input();
	std::cout << "Enter the number of columns of a two-dimensional dynamic array: \n";
	k = input();

	int** arr = new int* [n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[k];
	}

	std:: cout << "Enter array: \n";

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			std::cout << "Enter [" << i << "][" << j << "]: ";
			std::cin >> arr[i][j];
		}
	}

	std::cout <<"\n\n";
	std::cout << "\nArray:\n";

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			std::cout << arr[i][j] << "\t";
		}
		std::cout << "\n";
	}

	int count = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i][i] % 2 == 0)
		{
			count++;
		}
	}

	int* arr1 = new int[count];

	int l = 1;

	for (int i = 0, g = 0; i < n; i++)
	{
		if (arr[i][i] % 2 == 0)
		{
			arr1[g] = arr[i][i];
			l *= arr1[g];
			g++;
		}
	}

	std::cout<< "The product of even elements of the main diagonal of the matrix: " << l;

	delete[] arr1;

	for (int i = 0; i < n; i++)
	{
		delete[] arr[i];
	}

	delete[] arr;
}




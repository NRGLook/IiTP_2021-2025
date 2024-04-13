// LR-7-2.cpp Выполнил:Тиханёнок Илья
/*Задание 2: Перевести числа. Предусмотреть ввод положительных и
отрицательных чисел. Из дополнительного кода в прямой код.*/

#include <iostream>

int main()
{
	int n, num;
	int arr[100], arr1[100], arr2[100];
	std::cout << "Enter your number: ";
	std::cin >> num;

	int l = 0;

	n = abs(num);

	while (n != 0)
	{
		arr[l] = n % 2;
		n /= 2;
		l++;
	}

	int size = l + 1;

	for (int i = 0; i < size; i++)
	{
		arr1[i] = arr[size - i - 1];
	}

	if (num < 0) arr1[0] = 1;
	if (num >= 0) arr1[0] = 0;

	std::cout << std::endl;

	arr2[0] = arr1[0];

	if (num < 0) {
		for (int i = 1; i < size; i++)
		{
			if (arr1[i] == 1) arr2[i] = 0;
			if (arr1[i] == 0) arr2[i] = 1;
		}

		for (int i = 0; i < size; i++)
		{
			std::cout << arr2[i] << " ";
		}
	}
	else {
		for (int i = 0; i < size; i++)
		{
			std::cout << arr1[i] << " ";
		}
	}

	std::cout << '\n';

	return 0;
}
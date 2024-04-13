// LR-4-14 Выполнил:Тиханёнок Илья
//Задание 14:Создание "игры" Сапёр.

#include <stdlib.h>
#include <iostream>
#include <time.h>

//проверка на пользовательский ввод
long double inputInt()
{
	setlocale(0,"");
	long double a,b;

	std::cout << "Введите число:";
	std::cin >> a;

	while (std::cin.peek() == ' ')
		std::cin.ignore(1, ' ');
	while (std::cin.fail() || std::cin.peek() != '\n' || a <= 0 || a != (long double)a || a != round(a)) {
		//cin.peek - не пропускает пробелы
		std::cin.clear();//очищает
		std::cin.ignore(10000, '\n');
		std::cout << "Некорректный ввод.Попробуйте снова:";
		std::cin >> a;
		while (std::cin.peek() == ' ')
			std::cin.ignore(1, ' ');
	}
	return a;
}

int main()
{
	setlocale(0, "");
	int rows, colums, bomb, bombs = 0, a, b, c, d;
	rows = inputInt();
	colums = inputInt();
	char** arr = (char**)calloc(rows, sizeof(char*));
	for (int i = 0; i < rows; i++)
	{
		arr[i] = (char*)calloc(colums, sizeof(char));
	}
	std::cout << "Введите количество бомб:\n";
	bomb = inputInt();

	srand(time(0));
	while (bomb != 0)
	{
		int i = rand() % (rows - 1);
		int j = rand() % (colums - 1);
		if (arr[i][j] != '*')
		{
			arr[i][j] = '*';
			--bomb;
		}
	}
	std::cout << "Незаполненное поле:\n";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++)
		{
			if (arr[i][j] != '*')
			{
				arr[i][j] = '.';
			}
			std::cout << arr[i][j] << "\t";
		}
		std::cout << "\n";
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++)
		{
			if (arr[i][j] != '*')
			{
				c = i - 1;
				d = j - 1;
				if (c >= 0 && d >= 0 && c < rows && d < colums)
					if (arr[c][d] == '*')
						bombs += 1;
				c = i - 1;
				d = j;
				if (c >= 0 && d >= 0 && c < rows && d < colums)
					if (arr[c][d] == '*')
						bombs += 1;
				c = i - 1;
				d = j + 1;
				if (c >= 0 && d >= 0 && c < rows && d < colums)
					if (arr[c][d] == '*')
						bombs += 1;
				c = i;
				d = j + 1;
				if (c >= 0 && d >= 0 && c < rows && d < colums)
					if (arr[c][d] == '*')
						bombs += 1;
				c = i + 1;
				d = j + 1;
				if (c >= 0 && d >= 0 && c < rows && d < colums)
					if (arr[c][d] == '*')
						bombs += 1;
				c = i + 1;
				d = j;
				if (c >= 0 && d >= 0 && c < rows && d < colums)
					if (arr[c][d] == '*')
						bombs += 1;
				c = i + 1;
				d = j - 1;
				if (c >= 0 && d >= 0 && c < rows && d < colums)
					if (arr[c][d] == '*')
						bombs += 1;
				c = i;
				d = j - 1;
				if (c >= 0 && d >= 0 && c < rows && d < colums)
					if (arr[c][d] == '*')
						bombs += 1;
				arr[i][j] = bombs + 48;
				bombs = 0;
			}
		}
	}
	std::cout << "Поле,дополненное цифрами.\n";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++)
		{
			std::cout << arr[i][j] << "\t";
		}
		std::cout  << "\n";
	}

	for (int i = 0; i < rows; i++)
	{
		free(arr[i]);
	}
	free(arr);
	return 0;
}

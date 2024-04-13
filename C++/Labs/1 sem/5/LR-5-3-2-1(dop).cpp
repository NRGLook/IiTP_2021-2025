// LR-5-3-2-1(dop) Выполнил:Тиханёнок Илья
/* Задание 1 (доп): Входные данныеСостоит из нескольких тестов. Каждая строка содержит два неотрицательных целых числа p и q (p ≤ q), 
разделенных пробелом. p и q являются 32 битовыми знаковыми целыми. Последняя строка содержит два отрицательных целых числа и не обрабатывается.*/

#include<iostream>
#include<iomanip>

long double toget();
int rec(int val_1, int val_2);


int main()
{
	int p, q;
	std::cout << "Input value p\n";
	p = toget();
	std::cout << "Input value bigger than p\n";
	while (true)
	{
		q = toget();
		if (p <= q)
		{
			break;
		}
		else
		{
			std::cout << "Wrong value, try again \n";
		}
	}
	std::cout << "The result of the : " << rec(p, q) << std::endl;
}

long double toget()
{
	setlocale(0, " ");
	long double N;

	std::cout << "Enter:";
	std::cin >> N;

	while (std::cin.peek() == ' ')
		std::cin.ignore(1, ' ');
	while (std::cin.fail() || std::cin.peek() != '\n' || N <= -1 || N != (long double)N || N != round(N)) {
		//cin.peek - не пропускает пробелы
		std::cin.clear();//очищает
		std::cin.ignore(10000, '\n');
		std::cout << "Enter the correct value:";
		std::cin >> N;
		while (std::cin.peek() == ' ')
			std::cin.ignore(1, ' ');
	}
	return N;
}

int rec(int val_1, int val_2) {
	int F;

	if (val_1 > val_2)
	{
		return 0;
	}

	if (val_2 % 10 > 0)
	{
		F = val_2 % 10;
	}
	else if (val_2 == 0)
	{
		F = 0;
	}
	else
	{
		F = val_2 / 10;
	}
	return rec(val_1, val_2 - 1) + F;
}
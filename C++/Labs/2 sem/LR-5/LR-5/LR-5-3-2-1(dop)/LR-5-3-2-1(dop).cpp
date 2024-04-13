// LR-5-3-2-1(dop) Выполнил:Тиханёнок Илья
/* Задание 1 (доп): Входные данные. Состоит из нескольких тестов. Каждая строка содержит два неотрицательных целых числа p и q (p ≤ q), 
разделенных пробелом. p и q являются 32 битовыми знаковыми целыми. Последняя строка содержит два отрицательных целых числа и не обрабатывается.*/

#include<iostream>
#include<iomanip>

long double receive();
int recursion(int value1, int value2);


int main()
{
	int a, b;
	std::cout << "Input value p\n";
	a = receive();
	std::cout << "Input value bigger than p\n";
	while (true)
	{
		b = receive();
		if (a <= b)
		{
			break;
		}
		else
		{
			std::cout << "Wrong value, try again \n";
		}
	}
	std::cout << "The result of the : " << recursion(a, b) << std::endl;
}

long double receive()
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

int recursion(int value1, int value2) {
	int NRG;

	if (value1 > value2)
	{
		return 0;
	}

	if (value2 % 10 > 0)
	{
		NRG = value2 % 10;
	}
	else if (value2 == 0)
	{
		NRG = 0;
	}
	else
	{
		NRG = value2 / 10;
	}
	return recursion(value1, value2 - 1) + NRG;
}
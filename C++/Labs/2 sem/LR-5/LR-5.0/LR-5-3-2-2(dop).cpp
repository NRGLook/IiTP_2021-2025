// LR-5-3-2-2(dop) Выполнил:Тиханенок Илья
/*Задание 2(доп):Входные данные Каждая строка содержит три целых числа: k (0 < k < 1019), n (0 < n < 1019) и t (0 < t < 10). 
Последняя строка содержит три нуля и не обрабатывается.*/

#include <iostream>

unsigned long long output(unsigned long long k, unsigned long long n, unsigned long long m)
{
	if (!n)
	{
		return 1;
	}
	if (n % 2)
	{
		return (k * output((k * k) % m, n / 2, m)) % m;
	}
	else
	{
		return output((k * k) % m, n / 2, m);
	}
}

long double getinput(bool check, int max_)
{
	setlocale(0, " ");
	long double input;

	std::cout << "Enter:";
	std::cin >> input;

	while (std::cin.peek() == ' ')
		std::cin.ignore(1, ' ');
	while (std::cin.fail() || std::cin.peek() != '\n' || input <= -1 || input != (long double)input || input != round(input)) {
		//cin.peek - не пропускает пробелы
		std::cin.clear();//очищает
		std::cin.ignore(10000, '\n');
		std::cout << "Enter the correct value:";
		std::cin >> input;
		while (std::cin.peek() == ' ')
			std::cin.ignore(1, ' ');
	}
	return input;
}
int main() {
		setlocale(LC_ALL, "rus");

		std::cout << "Рекурсивная функция задана следующим образом:\nf(0, 0) = 1\nf(n, r) = сумма значений функции f(n-1, r-i), где i от 0 до n*(k-1),после которой затем находится сумма mod m\nгде m = 10^t.С клавиатуры вводятся числа k, n, t. Их возможные значения:\n 0 < k < 10^19, 0 < n < 10^19 0 < t < 10\n\n";

		unsigned long long k, n, t, m;
		int occasion = 0;

		while (true)
		{
			std::cout << "Введите k\n";
			k = getinput(true, pow(10, 19));

			std::cout << "Введите n\n";
			n = getinput(true, pow(10, 19));

			std::cout << "Введите t\n";
			t = getinput(true, 10);

			if (k == 0 && n == 0 && t == 0)
			{
				break; 
			}


			m = pow(10, t);

			++occasion;

			std::cout << "Case #" << occasion << ": " << output(k % m, n, m) << "\n";
		}

		return 0;
	
}

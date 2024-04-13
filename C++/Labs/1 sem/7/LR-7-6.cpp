// LR-7-6.cpp Выполнил:Тиханёнок Илья
//Задание 6:Задача с интересным числом)

#include <iostream>

int main() {
	int a;
	std::cout << "Programm can help you to find interesting numbers.Please, enter your number:";
	std::cin >> a;
	while (a) {
		long long x;
		std::cin >> x;
		int b = x / 10;
		if (x % 10 == 9) ++b;
		std::cout << b << '\n';
		--a;
	}
}
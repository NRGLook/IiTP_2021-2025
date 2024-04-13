// LR-5-3-2-3 Выполнил:Тиханенок Илья
/*Задание 3(доп)Пусть f(n) - наибольший нечетный делитель натурального числа n. По заданному 
натуральному n необходимо вычислить значение суммы f(1) + f(2) + ... + f(n).*/

#include <iostream>

int receive();
int NODget(int val);


int main() {
	std::cout << "Please, input n, the biggest number of the row: ";
	int n = receive();
	int an = 0;
	for (int i = 1; i <= n; i++) {
		an += NODget(i);
	}

	std::cout << "The sum of the row f(1) + f(2) + ... + f(n) = " << an << "\n\n\n";
	return 0;
}

int receive() {
	int N;

	while (true) {
		std::cin >> N;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Please, try again " << std::endl;
		}
		else
		{
			if (N <= 0) {
				std::cin.ignore(32767, '\n');
				std::cout << "Please, try again " << std::endl;
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

int NODget(int val) {
	int NOD = val;
	if (val == 1) return 1;
	else {
		while ((val % NOD) || !(NOD % 2)) {
			NOD--;
		}
		return NOD;
	}
}


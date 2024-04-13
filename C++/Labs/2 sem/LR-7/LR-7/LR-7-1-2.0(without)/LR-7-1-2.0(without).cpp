// LR-7-1-2.0(without array).cpp Выполнил:Тиханёнок Илья
/*Задание 1-2: Необходимо разработать программу для перевода чисел изодной системы счисления в другую.
Выполнить два варианта решениязадачи: без использования массивов и с помощью массивов.
** из четырнадцатеричной в троичную. ** */

#include <iostream>
#include <stdio.h>

int convert(char a) {
	if (a == '0') return 0;
	if (a == '1') return 1;
	if (a == '2') return 2;
	if (a == '3') return 3;
	if (a == '4') return 4;
	if (a == '5') return 5;
	if (a == '6') return 6;
	if (a == '7') return 7;
	if (a == '8') return 8;
	if (a == '9') return 9;
	if (a == 'A') return 10;
	if (a == 'B') return 11;
	if (a == 'C') return 12;
	if (a == 'D') return 13;
}

int convert_to_10() {
	char num;
	std::cin >> num;
	int size = std::cin.rdbuf()->in_avail();
	int number = convert(num);

	if (size != 1) {
		return number * pow(14, size - 1) + convert_to_10();
	}
	else {
		return number * pow(14, size - 1);
	}
}
void convert_to_3(int ten) {
	int number, integer, mod;
	integer = ten / 3;
	number = integer * 3;
	mod = ten - number;

	if (integer == 0) {
		std::cout << mod;
		return;
	}

	convert_to_3(ten /= 3);

	std::cout << mod;
}

int main() {
	int ten = convert_to_10();
	convert_to_3(ten);
}


// LR-7-2 Выполнил:Тиханёнок Илья
/*Задание 2: Перевести числа. Предусмотреть ввод положительных и 
отрицательных чисел.
** Из дополнительного кода в прямой код ** */
#include <iostream>
#include <cmath>;
#include "lr72.h"

using namespace std;

int main() {

	cout << "Enter integer value [-127; 127]:\t";
	int value;
	cin >> value;
	int tvalue = abs(value);
	int d_count = 0;
	while (tvalue) {
		tvalue /= 2;
		d_count++;
	}

	tvalue = abs(value);
	int po = 0;
	while (tvalue) {
		tvalue /= 2;
		po++;
	}

	int* bin = new int[po + 1];
	for (int i = 0; i < po + 1; i++) {
		bin[i] = 0;
	}

	tvalue = abs(value);
	for (int i = d_count; tvalue; i--) {
		int a = tvalue / 2;
		int remain = tvalue % 2;
		tvalue = a;
		bin[i] = remain;
	}

	if (value < 0) bin[0] = 1;
	cout << "\n\nDirect code for this value is the following:\t";
	for (int i = 0; i < po + 1; i++) {
		cout << bin[i];
	}

	direct_to_reverse(bin, po + 1, value);
	cout << "\n\n\n";

	return 0;
}
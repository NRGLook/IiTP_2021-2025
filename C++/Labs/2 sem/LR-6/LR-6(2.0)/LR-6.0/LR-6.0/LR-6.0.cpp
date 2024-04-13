// LR-6 Выполнил:Тиханёнок Илья
/*Задание 1:Рассматривать строки как одномерный массив символов.Дана строка, состоящая из слов, разделенных пробелами.
Вывести на экран порядковый номер слова максимальной длины и номер позиции строки с которой оно начинается.*/

#include <iostream>

int main() {

	int n = 0, m = 0, j = 0, max = 0, i;
	char a[80];//limiting user input
	std::cout << "The program allows you to find a word of maximum length and output the number and position from which it begins in\nthe entered line:";

	int* arr = new int[2];//initialization

	gets_s(a);//taking a string

	while (a[n])//as long as the string does not exceed the size of the array
		++n;
	for (int i = 0; i < n; i++) {
		if (a[i] != ' ' && a[i] != '\0') {
			m++;
		}
		else {
			if (m > max) {
				max = m;
				arr[j] = m;
				arr[j + 1] = i - m + 1;
				j += 2;
			}
			m = 0;
		}
		if (j % 2 == 0 && j != 0)
			sizeof(int);//determining the size of an array
	}

	for (int i = 0; i < j; i++) {
		if (i != 0 && i % 2 == 0) {
			std::cout << std::endl << arr[i] << " ";
		}
		else {
			std::cout << arr[i] << " ";
		}
	}

	return 0;
}
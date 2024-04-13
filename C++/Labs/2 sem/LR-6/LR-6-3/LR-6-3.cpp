// LR-6-3 Выполнил:Тиханёнок Илья
/*Задание 3:Ввести строку и определить все входящие в неё символы. Например: строка «abccbbbabba» состоит из символов
«a», «b» и «с». Результат вывести на экран. Стандартных функцийработы со строками не использовать. */

#include <iostream>

int main() {
	int N = 2, length;
	char* str = (char*)malloc(N * sizeof(char));//allocating memory
	std::cout << "Enter the line: ";
	for (length = 0; '\n' - (str[length] = getchar()); ++length) {
		if (length == N - 1) {
			str = (char*)realloc(str, (N *= 2) * sizeof(char));//getting a new size
		}
	}

	str = (char*)realloc(str, (length + 1) * sizeof(char));
	str[length] = '\0';//adding zero to the end of the line

	for (int i = 0, j = 0; i < length; ++i) {
		if (str[i] == '\0') ++j;
		j = i + 1;
		for (; j < length; ++j) {
			if (str[i] == str[j])str[j] = '\0';
		}
	}
	std::cout << "The string consists of: ";
	for (int i = 0; i < length; ++i) {
		if (str[i] == '\0') continue;
		else std::cout << str[i] << "  ";
	}

	return 0;
}
// LR-6-7 Выполнил:Тиханёнок Илья
/*Задание 7:В заданной строке S найти максимальную по длине подстроку, которая не является палиндромом.
**Формат входных данных:**
На вход задается строка S, состоящая из строчных букв латинского 
алфавита (1 ⩽ |S| ⩽ 105 ).
**Формат выходных данных:**
Выведите одно целое число — длина максимального непалиндрома. 
Если такой подстроки не существует, то выведите -1.*/

#include <iostream>

bool lastfunction(char* arr, int size);

int main()
{

	std::cout << "Input the string, where we will find nonpolindrom (do not forget about \".\" at the end of the string): \n";

	char str[105];
	std::cin.getline(str, 105, '.');
	int m_one = -1, m_length = 1;

	int size = 0;

	for (int i = 0; str[i] != 0; i++) {
		size++;
	}

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			for (int n = 0; n <= (j - i) / 2; n++) {
				if ((str[i + n] != str[j - n]) && (j - i + 1) > m_length)
					m_length++;
			}
		}
	}


	if (lastfunction(str, size) || size == 1) std::cout << "\n\n" << m_one << "\n\n\n";
	else std::cout << "\n\nThe longest non-palindrom substring contains " << m_length << " characters.\n\n\n";

	return 0;
}

bool lastfunction(char* arr, int size) {

	for (int i = 0; i < size - 1; i++) {
		if (arr[i] != arr[i + 1]) return false;
	}
	return true;
}




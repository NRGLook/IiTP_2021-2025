//LR-7-3.cpp Выполнил:Тиханёнок Илья
/*Задание 3: Осуществить сложение чисел. Разработать функции для 
выполнения операции сложения. Предусмотреть ввод положительных и 
отрицательных чисел.Найдите сумму двоичных чисел, заданных в естественной 
форме. Сложение выполните в дополнительном коде. Ответ выразите в естественной форме.*/

#include <iostream>
#include <string>

using namespace std;

int firstfunction(char a)
{
	int b = 0;
	if (a == '0') b = 0;
	if (a == '1') b = 1;

	return b;
}

char secondfunction(int a)
{
	char b = '0';
	if (a == 0) b = '0';
	if (a == 1) b = '1';

	return b;
}

string code(string a, string b, string sum, short i) {
	string temp_a = ""; temp_a[0] = a[i]; string temp_b = ""; temp_b[0] = b[i];
	short temp_sum = atoi(temp_a.c_str()) + atoi(temp_b.c_str());
	if (temp_sum > 1) {
		temp_sum -= 2;
		sum[i] = temp_sum + '0';
		if (i > 0) {
			temp_a[0] = a[i - 1];
			temp_b[0] = b[i - 1];
			short value_a = atoi(temp_a.c_str());
			short value_b = atoi(temp_b.c_str());
			value_a > value_b ? b[i - 1] = ++value_b + '0' : a[i - 1] = ++value_a + '0';
		}
	}
	else {
		string temp = "";
		temp = to_string(temp_sum);
		sum[i] = temp[0];
	}
	if (i == 0) return sum;
	return code(a, b, sum, --i);
}

void convertation(string code, short i, bool check, bool newcode, bool printcode) {
	if (check) {
		if (code[0] == '0') {
			cout << code; return;
		}
		if (code[i + 1] == '1') return convertation(code, i, 0, 1, 0);
		if (i == 0) return convertation(code, i, 0, 0, 1);
		else return convertation(code, --i, 1, 0, 0);
	}
	if (newcode) {
		if (i == 0) return convertation(code, ++i, 0, 0, 1);
		else {
			code[i] == '1' ? code[i] = '0' : code[i] = '1';
			return convertation(code, --i, 0, 1, 0);
		}
	}
	if (printcode) {
		if (i == code.length()) {
			cout << code;
			return;
		}
		else {
			code[i] == '1' ? code[i] = '0' : code[i] = '1';
			return convertation(code, ++i, 0, 0, 1);
		}
	}
}

int main() {
	string a, b, one, sum;
	cin >> a >> b;
	short size_a = a.length(), size_b = b.length(), i = 0,
		size = size_a > size_b ? size_a : size_b; //using ternary operations

	if (size_a < size) {
		string temp = a; short j = 0;
		a.resize(size); for (i = 0; i < size; ++i) a[i] = '0';//adiing zero
		for (i = temp.length() - 1; i >= 0; --i, ++j) a[size - j - 1] = temp[i];
	}

	if (size_b < size) {
		string temp = b; short j = 0;
		b.resize(size); for (i = 0; i < size; ++i) b[i] = '0';//adding zero
		for (i = temp.length() - 1; i >= 0; --i, ++j) b[size - j - 1] = temp[i];
	}

	if (a[0] == '1') {
		one.resize(size_a, '0');
		one[size_a - 1] = '1';
		sum.resize(size_a, '0');
		a = code(a, one, sum, size_a);
	}
	if (b[0] == '1') {
		one.resize(size_b, '0');
		one[size_b - 1] = '1';
		sum.resize(size_b, '0');
		b = code(b, one, sum, --size_b);
	}
	sum.resize(size, '0');
	string s = code(a, b, sum, size);
	convertation(s, s.length() - 2, 1, 0, 0);
	return (0);
}
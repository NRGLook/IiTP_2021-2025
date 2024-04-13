// LR-7-9.cpp Выполнил:Тиханёнок Илья
/*Задание 9:Вчера на уроке математики Саша (возможно Богом данный) узнал 
о том, что иногда полезно использовать вместо десятичной системы счисления какую-нибудь другую. Однако, учительница
(как иронично) не объяснила, почему в системе счисления по основанию b в качестве цифр 
выбирают числа от 0 до b - 1. Немного подумав, Саша понял, что можно выбирать и другие наборы цифр. Например, 
вместо троичной системы счисления можно рассмотреть систему счисления, где вместо обычных цифр 
0, 1, 2 есть цифры 1, 2 и 3. Саша заинтересовался вопросом, а как перевести число n в эту систему счисления? Например,
число 7 в этой системе записывается как 21, так как 7 = 2∙3+1, а число 22 записывается как 211,
так как 22 = 2 ∙ 9 + 1 ∙ 3 + 1. 
Входные данные натуральное число n, 1 ≤ n ≤ 2•109
.
Выходные данные число n записанное в указанной системе счисления.*/

#include <iostream>
#include <string>

using namespace std;

bool MINUS;

void convert_to_3(int a, string& Digit) {
	if (a / 3) convert_to_3(a / 3, Digit);
	string temp = to_string(a % 3);
	Digit.push_back(temp[0]);
}

void convert_to_new_3(string digit3, string& Digit, int i) {
	string temp3; temp3[0] = digit3[i];
	short a;
	if (atoi(temp3.c_str()) < 1) {
		string temp = to_string(atoi(temp3.c_str()) + 3);
		Digit[i] = temp[0];
		if (i == 0) {
			string newDigit; newDigit.resize(Digit.length() + 1);
			newDigit[0] = '2';
			for (short j = 0, k = 1; j < Digit.length(); ++j, ++k) newDigit[k] = Digit[j];
			cout << newDigit; return;
		}
		temp[0] = digit3[i - 1];
		a = atoi(temp.c_str()) - 1;
		if (a >= 0) {
			temp.erase(0, 1);
			string y = to_string(a);
			temp.push_back(y[0]);
			digit3[i - 1] = temp[0];
		}
		else {
			bool zero = 0;
			a += 3;
			temp.erase(0, 1);
			string y = to_string(a);
			temp.push_back(y[0]);
			if (digit3[i - 1] == '0') zero = 1;
			digit3[i - 1] = temp[0];
			if (zero) {
				temp[0] = digit3[i - 2];
				a = atoi(temp.c_str()) - 1;
				temp = to_string(a);
				digit3[i - 2] = temp[0];
			}
		}
	}
	else Digit[i] = digit3[i];
	if (i - 1 == 0 && digit3[i - 1] == '0') {
		if (MINUS) putchar('-');
		Digit.erase(0, 1); cout << Digit; return;
	}
	if (i == 0) {
		if (MINUS) putchar('-'); cout << Digit;
		return;
	}
	return convert_to_new_3(digit3, Digit, --i);
}

int main() {
	short digit; string Digit; cin >> digit;
	if (digit < 0) { digit *= -1; MINUS = 1; }
	if (digit == 0) { cout << 0; return (0); }
	convert_to_3(digit, Digit);
	string digit3 = Digit;
	convert_to_new_3(digit3, Digit, Digit.length() - 1);
}
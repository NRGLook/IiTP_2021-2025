// LR-7-8.cpp Выполнил:Тиханёнок Илья
/*Задание 8:Брюс недавно получил работу в NEERC (Numeric Expression Engineering & Research Center),
где изучают и строят много различных любопытных чисел. Его первым заданием стало исследование двудесятичных чисел.
Натуральное число называется двудесятичным, если его десятичное представление является суффиксом его двоичного 
представления; и двоичное и десятичное представление рассматривается без ведущих нулей. Например,
1010 = 10102, так что 10 двудесятичное число. Числа 101010 = 11111100102 и 4210 = 1010102 не являются
двудесятичными.Сначала Брюс хочет создать список двудесятичных чисел. Помогите ему найти n-ое наименьшее
двудесятичное число.*/


#include <iostream>
#include <string>
using namespace std;

void swap_cod(string& two) {
	for (int j = 0, j1 = two.length() - 1; j < two.length() / 2; j++, j1--)
		swap(two[j], two[j1]);
}

string to_two(string s, string two, int t, int k, int c) {
	for (;;) {
		for (int u = 0; u < s.length() - 1; u++) {
			if (s[u] == '0') {
				k = 0;
			}
			else {
				k = 1;
				break;
			}
		}
		if (s[s.length() - 1] == '1' && !k) {
			two += '1';
			break;
		}
		if (s[s.length() - 1] == '0' && !k) {
			two += '0';
			break;
		}

		for (int e = 0; e < s.length(); e++) {
			c = s[e] - '0';
			if (c % 2) {
				c = (c + t * 10) / 2;
				s[e] = c + '0';
				t = 1;
			}
			else {
				c = (c + t * 10) / 2;
				s[e] = c + '0';
				t = 0;
			}
			if (e == s.length() - 1) {
				if (t) two += '1';
				else  two += '0';
				t = 0;
			}
		}
	}

	for (int j = 0, j1 = two.length() - 1; j < two.length() / 2; j++, j1--)
		swap(two[j], two[j1]);

	return two;
}

int main() {
	string s, two, two2, buf, buf2;

	int a;
	cin >> a;
	while (cin.fail() || a < 1 || a > 10000) {
		cin.clear();
		cin.ignore(9999, '\n');
		cout << "incorrect value, t = ";
		cin >> a;
	}
	s = to_string(a);

	if (a == 1) {
		cout << 1;
		return 0;
	}
	int h, h2;
	two = to_two(s, two, 0, 0, 0);
	buf = two;
	buf2 = s;
	swap_cod(buf);
	swap_cod(buf2);
	h = two.length();
	h2 = s.length();
	buf.erase(h2, h);
	if (buf2 != buf) {
		cout << two;
		return 0;
	}

	two = to_two(two, two2, 0, 0, 0);
	swap_cod(two);
	two.erase(0, h2);
	two.erase(h, two.length());
	swap_cod(two);
	while (two[0] == '0') two.erase(0, 1);
	cout << two;
}



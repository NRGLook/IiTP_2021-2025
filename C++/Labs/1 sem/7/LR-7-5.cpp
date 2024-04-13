// LR-7-5.cpp Выполнил:Тиханёнок Илья
//Задание 5: Перевести число из арабской системы записи чисел в римскую.

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int Arabicnumber;
	int digit, d_number;
	string I = "I", IV = "IV", V = "V", IX = "IX", X = "X", XL = "XL", L = "L", XC = "XC", C = "C", CD = "CD", D = "D", CM = "CM", M = "M";
	cout << "Input you number in arabic system from the interval [1; 3999]:\t";
	cin >> Arabicnumber;
	d_number = 1;
	int time_value = Arabicnumber;

	while (time_value > 10) {
		time_value /= 10;
		d_number++;
	}

	cout << endl << endl;

	int* digits = new int[d_number];
	for (int i = 0; i < d_number; i++) {
		int b = pow(10, d_number - i - 1);
		int a = pow(10, d_number - i);
		digits[i] = (Arabicnumber % a - Arabicnumber % b) / b;
	}

	for (int i = 0; i < d_number; i++) {
		int a = d_number - 1 - i;
		int b = digits[i];
		switch (a) {
		case 0: {
			switch (b) {
			case 0:
				break;
			case 1: {
				cout << I;
				break;
			}
			case 2: {
				cout << I << I;
				break;
			}
			case 3: {
				for (int j = 0; j < 3; j++) {
					cout << I;
				}
				break;
			}
			case 4: {
				cout << IV;
				break;
			}
			case 5: {
				cout << V;
				break;
			}
			case 6: {
				cout << V << I;
				break;
			}
			case 7: {
				cout << V << I << I;
				break;
			}
			case 8: {
				cout << V << I << I << I;
				break;
			}
			case 9: {
				cout << IX;
				break;
			}
			}
			break;
		}


		case 1: {
			switch (b) {
			case 0:
				break;
			case 1: {
				cout << X;
				break;
			}
			case 2: {
				cout << X << X;
				break;
			}
			case 3: {
				for (int j = 0; j < 3; j++) {
					cout << X;
				}
				break;
			}
			case 4: {
				cout << XL;
				break;
			}
			case 5: {
				cout << L;
				break;
			}
			case 6: {
				cout << L << X;
				break;
			}
			case 7: {
				cout << L << X << X;
				break;
			}
			case 8: {
				cout << L + X + X + X;
				break;
			}
			case 9: {
				cout << XC;
				break;
			}
			}
			break;
		}

		case 2: {
			switch (b) {
			case 0:
				break;
			case 1: {
				cout << C;
				break;
			}
			case 2: {
				cout << C + C;
				break;
			}
			case 3: {
				for (int j = 0; j < 3; j++) {
					cout << C;
				}
				break;
			}
			case 4: {
				cout << CD;
				break;
			}
			case 5: {
				cout << D;
				break;
			}
			case 6: {
				cout << D + C;
				break;
			}
			case 7: {
				cout << D + C + C;
				break;
			}
			case 8: {
				cout << D + C + C + C;
				break;
			}
			case 9: {
				cout << CM;
				break;
			}
			}
			break;
		}

		case 3: {
			switch (b) {
			case 0:
				break;
			case 1: {
				cout << M;
				break;
			}
			case 2: {
				cout << M + M;
				break;
			}
			case 3: {
				cout << M + M + M;
				break;
			}
			default: {
				cout << "\n\nYour number is so big.Try again...\n\n";
			}
			}
			break;
		}
		}

	}
	return 0;
}

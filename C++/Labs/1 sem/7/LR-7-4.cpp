// LR-7-4.cpp Выполнил:Тиханёнок Илья
/*Задание 4:Осуществить сложение и вычитание чисел в заданной системе счисления. В другую систему счисления
не переводить. В системах счисления больших десятичной использовать буквы по аналогии с шестнадцатеричной
системой. Разработать функции для выполнения операции сложения и функции для выполнения операции вычитания.
Предусмотреть ввод положительных и отрицательных чисел.*/

#include <iostream>
#include <string>

bool number_A, number_B;

std::string letter_to_number(char number) {
	std::string A = "..";
	if (number == 'A' || number == 'a') A = "10";
	if (number == 'B' || number == 'b') A = "11";
	if (number == 'C' || number == 'c') A = "12";
	if (number == 'D' || number == 'd') A = "13";
	if (number == 'E' || number == 'e') A = "14";
	if (number == 'F' || number == 'f') A = "15";
	if (number == 'G' || number == 'g') A = "16";
	if (number == 'H' || number == 'h') A = "17";
	if (number == 'I' || number == 'i') A = "18";
	if (number == '0') A = "0";
	if (number == '1') A = "1";
	if (number == '2') A = "2";
	if (number == '3') A = "3";
	if (number == '4') A = "4";
	if (number == '5') A = "5";
	if (number == '6') A = "6";
	if (number == '7') A = "7";
	if (number == '8') A = "8";
	if (number == '9') A = "9";
	return A;
}

std::string number_to_letter(long long letter) {
	std::string B = "";
	if (letter == 0) B = "0";
	if (letter == 1) B = "1";
	if (letter == 2) B = "2";
	if (letter == 3) B = "3";
	if (letter == 4) B = "4";
	if (letter == 5) B = "5";
	if (letter == 6) B = "6";
	if (letter == 7) B = "7";
	if (letter == 8) B = "8";
	if (letter == 9) B = "9";
	if (letter == 10) B = "A";
	if (letter == 11) B = "B";
	if (letter == 12) B = "C";
	if (letter == 13) B = "D";
	if (letter == 14) B = "E";
	if (letter == 15) B = "F";
	if (letter == 16) B = "G";
	if (letter == 17) B = "H";
	if (letter == 18) B = "I";
	return B;
}
   
void sum_a_and_b(std::string a, std::string b, std::string sum, int i) {
	std::string A = letter_to_number(a[i]), B = letter_to_number(b[i]);
	long long delete_sum = atoi(A.c_str()) + atoi(B.c_str());
	if (delete_sum > 18) {
		delete_sum = delete_sum - 19;
		std::string temp = number_to_letter(delete_sum);
		sum[i] = temp[0];
		if (i == 0) {
			std::string new_sum;
			new_sum.resize(sum.length() + 1);
			new_sum[0] = '1';
			for (int j = 0, k = 1; j < sum.length(); ++j, ++k) {
				new_sum[k] = sum[j];
			}
			std::cout << new_sum;
			return;
		}
		std::string new_a = letter_to_number(a[i - 1]);
		long long NEW_A = atoi(new_a.c_str()) + 1;
		std::string END_NEW_A = number_to_letter(NEW_A);
		a[i - 1] = END_NEW_A[0];
	}
	else {
		std::string temp_A = number_to_letter(delete_sum); sum[i] = temp_A[0];
	}
	if (i == 0) {
		std::cout << sum;
		return;
	}
	sum_a_and_b(a, b, sum, --i);
}

void dif_a_and_b(std::string a, std::string b, std::string dif, int i) {
	std::string A = letter_to_number(a[i]); std::string B = letter_to_number(b[i]);
	short delete_dif = atoi(A.c_str()) - atoi(B.c_str());

	if (delete_dif < 0) {

		std::string new_a = letter_to_number(a[i]);
		long long add_new_a = atoi(new_a.c_str()) + 17;
		std::string new_b = letter_to_number(b[i]);
		long long add_new_b = atoi(new_b.c_str());
		long long difference = add_new_a - add_new_b;
		std::string temp = std::to_string(difference);
		dif[i] = temp[0];
		if (i == 0) {
			std::string new_dif;
			new_dif.resize(dif.length() + 1);
			new_dif[0] = 'H';
			for (short j = 0, k = 1; j < dif.length(); ++j, ++k) {
				new_dif[k] = dif[j];
			}
			std::cout << new_dif;
			return;
		}
		std::string NEW_A = letter_to_number(a[i - 1]);
		short NEW = atoi(NEW_A.c_str()) - 1;
		if (NEW < 0) NEW += 18;
		std::string END_NEW_A = number_to_letter(NEW);
		a[i - 1] = END_NEW_A[0];
	}
	else { std::string END = number_to_letter(delete_dif); dif[i] = END[0]; }
	if (i == 0) {
		std::cout << dif;
		return;
	}
	dif_a_and_b(a, b, dif, --i);
}

int main() {

	std::string a, b, sum;
	std::cin >> a >> b;
	long long size_a = a.length(), size_b = b.length();
	if (a[0] == '-') {
		number_A = 1;
		std::string temp;
		temp.resize(a.length() - 1);
		for (int i = 1, k = 0; i < a.length(); ++i, ++k) {
			temp[k] = a[i];
		}
		a.resize(temp.length());
		a = temp;
		size_a = a.length();
	}
	if (b[0] == '-') {
		number_B = 1;
		std::string temp;
		temp.resize(b.length() - 1);
		for (int i = 1, k = 0; i < b.length(); ++i, ++k) {
			temp[k] = b[i];
		}
		b.resize(temp.length());
		b = temp;
		size_b = b.length();
	}

	long long size;

	if (size_a > size_b) {
		size = size_a;
	}
	else {
		size = size_b;
	}

	if (size_a < size) {
		std::string temp = a;
		int j = 0;
		a.resize(size);
		for (int i = 0; i < size; ++i) {
			a[i] = '0';
		}
		for (int i = temp.length() - 1; i >= 0; --i, ++j) {
			a[size - j - 1] = temp[i];
		}
	}
	if (size_b < size) {
		std::string temp = b;
		int j = 0;
		b.resize(size);
		for (int i = 0; i < size; ++i) {
			b[i] = '0';
		}
		for (int i = temp.length() - 1; i >= 0; --i, ++j) {
			b[size - j - 1] = temp[i];
		}
	}
	sum.resize(size, '0');
	if (number_A && number_B) {
		std::cout << a << " + " << b << " = ";
		std::cout << std::endl;
		sum_a_and_b(a, b, sum, size);
		std::cout << std::endl;
		std::cout << a << " - " << b << " = "; (a, b, sum, size);
	}
	if ((number_A && !number_B) || (number_B && !number_A)) {
		std::cout << a << " + " << b << " = ";
		dif_a_and_b(a, b, sum, size);
		std::cout << a << " - " << b << " = ";
		std::cout << '-';
		sum_a_and_b(a, b, sum, size);
		std::cout << std::endl;
	}
	if (!number_A && !number_B) {
		std::cout << a << " + " << b << " = ";
		sum_a_and_b(a, b, sum, size);
		std::cout << std::endl;
		std::cout << a << " - " << b << " = ";
		dif_a_and_b(a, b, sum, size);
	}
	return 0;
}
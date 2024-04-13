#include <iostream>
#include <cmath>
#include "Header.h"

using namespace std;

long long int ternary_to_decimal(long long int ternary, int digit_count) {

	long long int  dec_value = 0, i = digit_count - 1, n = 0;


	while (i > -1) {

		long long a = pow(3, i);
		long long int b = pow(10, digit_count - n);
		long long int c = pow(10, digit_count - 1 - n);
		long long int sum1 = ternary % b / c * a;
		dec_value += sum1;
		i--;
		n++;
	}
	return dec_value;
}

void digit(int value) {
	int a = value - 10;
	switch (a) {
	case 0: {
		cout << "a";
		break;
	}
	case 1: {
		cout << "b";
		break;
	}
	case 2: {
		cout << "c";
		break;
	}
	case 3: {
		cout << "d";
		break;
	}
	}
}


void space(int number) {
	for (int i = 1; i <= number; i++) {
		cout << " ";
	}
}

int digit_counting_2(long long int ter_value, int digit_count) {
	int digit_count_2 = 1;
	long long int time_dec = ternary_to_decimal(ter_value, digit_count);
	while (time_dec > 17) {
		int a = time_dec / 17;
		int b = 17 * a;
		int c = time_dec - b;
		time_dec = a;
		digit_count_2++;
	}

	return digit_count_2;
}
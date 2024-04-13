#include <iostream>
#include "Header.h";


void direct_to_reverse(int* bin_arr, int size, int value) {
	std::cout << "\n\nReverse code for this value is the following\t";
	if (value < 0) {
		std::cout << bin_arr[0];
		for (int i = 1; i < size; i++) {
			if (bin_arr[i]) bin_arr[i] = 0;
			else bin_arr[i] = 1;
			std::cout << bin_arr[i];
		}
	}
	else {
		for (int i = 0; i < size; i++) {
			std::cout << bin_arr[i];
		}
	}

}
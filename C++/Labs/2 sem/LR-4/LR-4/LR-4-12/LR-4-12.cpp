// LR-4-12 Выполнил:Тиханёнок Илья
/*Задача 12. Написать функцию которая будет удалять дубликаты элементов из массива. Входные параметры: массив,
длинна массива. Выходные параметры: новый массив, новый размер.*/

#include <iostream>

// Ввод целочисленного значения (число больше 0)
long long int inputInt() {
    long double value;

    std::cin >> value;

    // Удаление всех пробелов (если они есть) после первого числа, если оно было в потоке
    while (std::cin.peek() == ' ')
        std::cin.ignore(1, ' ');

    // Проверка состояния потока ввода, конца строки, области допустимых значений и экспоненты
    while (std::cin.fail() || std::cin.peek() != '\n' || value <= 0 || value != (long long int)value) {
        std::cout << "Enter correct value. Enter a positive integer value (before 2⁶³): ";

        std::cin.clear(); // Включение потока ввода
        std::cin.ignore(3256, '\n'); // Очищение буфера потока ввода

        std::cin >> value;

        while (std::cin.peek() == ' ')
            std::cin.ignore(1, ' ');
    }

    return value;
}

double inputDouble(long long int i2) {
    double value;

    std::cin >> value;

    while (std::cin.fail()) {
        std::cout << "Enter correct value. Enter element [" << i2 + 1 << "] again:\n";

        std::cin.clear();
        std::cin.ignore(3256, '\n');

        std::cin >> value;
    }

    return value;
}

void deleteDoub(int n, double* arr) {
    for (long long int i = 1; i < n; ++i) {
        for (long long j = i - 1; j > -1; --j) {
            if (arr[i] == arr[j]) {
                for (long long z = i; z < (n-1); ++z) {
                    arr[z] = arr[z + 1];
                }
                --n;
                --i;
                break;
            }
        }
    }

    std::cout << "\n\nNew array: \n";
    for (long long int i = 0; i < n; ++i) {
        std::cout << arr[i] << "  ";
    }
    std::cout << "\n\nNew size of array: " << n << '.';
}

int main() {
    int n;

    std::cout << "The program removes duplicate elements from the array.\n\n";
    std::cout << "Enter the size of array: ";
    n = inputInt();

    double* arr = new double[n];

    std::cout << "Enter elements of array: ";
    for (long long int i = 0; i < n; ++i) {
        arr[i] = inputDouble(i);
    }

    deleteDoub(n, arr); // Функция удаления дубликатов в массиве

    delete[] arr;

    return 0;
}
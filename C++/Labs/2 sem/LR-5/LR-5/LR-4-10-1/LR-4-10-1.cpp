// LR-4-10-1 Выполнил:Тиханенок Илья
//Задание 10:Построить магический квадрат любого порядка.

#include <iostream>
#include <iomanip>
#include <ctime>

//проверка на ввод
long long int inputInt() {
    long double value;

    std::cin >> value;

    // не пропускает пробелы
    while (std::cin.peek() == ' ')
        std::cin.ignore(1, ' ');

    // Проверка состояния потока ввода, конца строки, области допустимых значений и экспоненты
    while (std::cin.fail() || std::cin.peek() != '\n' || value <= 0 || value != (long long int)value) {
        std::cout << "Invalid value.Try again(or restart programm)(before 2⁶³): ";

        std::cin.clear(); // включение потока ввода
        std::cin.ignore(3256, '\n'); // очищение буфера потока ввода

        std::cin >> value;


        while (std::cin.peek() == ' ')
            std::cin.ignore(1, ' ');
    }

    return value;
}

int main() {

    int n, j, i, t, y, x, buff, m=1;
    setlocale (LC_ALL, "Rus");
    std::cout << "Enter the size of square:";
    n = inputInt();
    clock_t time1 = clock();
    std::ios_base::sync_with_stdio();
    int** magicSquare;

    magicSquare = (int**)calloc(n, sizeof(*magicSquare));

    for (int i = 0; i < n; ++i) {
        magicSquare[i] = (int*)calloc(n, sizeof(*magicSquare[i]));
    }

    if (n == 2) {
        std::cout << "\nMagic square isn't exists.";
    }
    else if (n == 1) {
        std::cout << "\nMagic square:\n" << std::setw(3) << 1 << '\n';
    }
    else if (n % 2 == 1) {
        i = 0;
        j = static_cast<int>(n / 2); //Вычисляем среднее значение элемента

        magicSquare[i][j] = 1; // В верхней строке средний элемент равен 1

        // Заполнение магического квадрата
        for (int k = 2; k < n * n + 1; ++k) {
            if (i - 1 >= 0 && j - 1 >= 0 && magicSquare[i - 1][j - 1] == 0) {
                magicSquare[i - 1][j - 1] = k;
                --i;
                --j;
            }
            else if (i - 1 >= 0 && j - 1 >= 0 && magicSquare[i - 1][j - 1] != 0) {
                magicSquare[i + 1][j] = k;
                ++i;
            }
            else if (i - 1 < 0 && j - 1 >= 0) {
                magicSquare[n - 1][j - 1] = k;
                i = n - 1;
                --j;
            }
            else if (i - 1 >= 0 && j - 1 < 0) {
                magicSquare[i - 1][n - 1] = k;
                --i;
                j = n - 1;
            }
            else if (i - 1 < 0 && j - 1 < 0 && magicSquare[n - 1][n - 1] != 0) {
                magicSquare[i + 1][j] = k;
                ++i;
            }
        }
    }
    else if (n % 4 == 0) {
        int** secondSquare;

        secondSquare = (int**)malloc(n * sizeof(int*));

        for (long long int i = 0; i < n; ++i) {
            secondSquare[i] = (int*)malloc(n * sizeof(int));
        }

        // Заполнение от 0 до n^2 магического квадрата
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                magicSquare[i][j] = m;
                ++m;
            }
        }

        m = n * n;

        // Заполнение дополнительного квадрата
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                secondSquare[i][j] = m;
                --m;
            }
        }

        // Вычисление длины одного маленького квадрата
        m = (n / 4) * (n / 4);

        t = 1;
        i = 0;
        j = 0;

        // Перестановка элементов из дополнительного в магический квадрат по диагоналям
        while (t < m + 1) {
            ++t;

            y = i;
            x = j;

            while (y < i + 4) {
                magicSquare[y][x] = secondSquare[y][x];
                ++y;
                ++x;
            }

            y = i + 3;
            x = j;

            while (x < i + 4) {
                magicSquare[y][x] = secondSquare[y][x];
                --y;
                ++x;
            }

            if (j + 4 < n) {
                j += 4;
            }
            else if (j + 4 >= n) {
                j = 0;
                i += 4;
            }
        }

        for (long long int i = 0; i < n; ++i) {
            free(secondSquare[i]);
        }
        free(secondSquare);

    }
    else {
        int n4 = n / 2;

        int** arr1;
        arr1 = (int**)calloc(n4, sizeof(*arr1));
        int** arr2;
        arr2 = (int**)calloc(n4, sizeof(*arr2));
        int** arr3;
        arr3 = (int**)calloc(n4, sizeof(*arr3));
        int** arr4;
        arr4 = (int**)calloc(n4, sizeof(*arr4));

        for (int i = 0; i < n4; ++i) {
            arr1[i] = (int*)calloc(n4, sizeof(*arr1[i]));
        }
        for (int i = 0; i < n4; ++i) {
            arr2[i] = (int*)calloc(n4, sizeof(*arr2[i]));
        }
        for (int i = 0; i < n4; ++i) {
            arr3[i] = (int*)calloc(n4, sizeof(*arr3[i]));
        }
        for (int i = 0; i < n4; ++i) {
            arr4[i] = (int*)calloc(n4, sizeof(*arr4[i]));
        }

        // Высчитываем максимальные значения в дополнительных квадратах
        int pred1 = n * n / 4;
        int pred2 = n * n / 2;
        int pred3 = n * n / 4 * 3;
        int pred4 = n * n;

        int k = 1;

        i = 0;
        j = static_cast<int>(n4 / 2);
        arr1[i][j] = 1;
        ++k;

        // Заполняем первый магический квадрат
        while (k < pred1 + 1) {
            if (i - 1 > -1 && j - 1 > -1 && arr1[i - 1][j - 1] == 0) {
                arr1[i - 1][j - 1] = k;
                --i;
                --j;
            }
            else if (i - 1 > -1 && j - 1 > -1 && arr1[i - 1][j - 1] != 0 && i + 1 < n4) {
                arr1[i + 1][j] = k;
                ++i;
            }
            else if (i - 1 < 0 && j - 1 >= 0) {
                arr1[n4 - 1][j - 1] = k;
                i = n4 - 1;
                --j;
            }
            else if (i - 1 >= 0 && j - 1 < 0) {
                arr1[i - 1][n4 - 1] = k;
                --i;
                j = n4 - 1;
            }
            else if (i - 1 < 0 && j - 1 < 0 && arr1[n4 - 1][n4 - 1] != 0 && i + 1 < n4) {
                arr1[i + 1][j] = k;
                ++i;
            }

            ++k;
        }

        i = 0;
        j = static_cast<int>(n4 / 2);
        arr4[i][j] = k;

        ++k;

        // Заполняем четвертый квадрат
        while (k < pred2 + 1) {
            if (i - 1 > -1 && j - 1 >= 0 && arr4[i - 1][j - 1] == 0) {
                arr4[i - 1][j - 1] = k;
                --i;
                --j;
            }
            else if (i - 1 >= 0 && j - 1 >= 0 && arr4[i - 1][j - 1] != 0 && i + 1 < n4) {
                arr4[i + 1][j] = k;
                ++i;
            }
            else if (i - 1 < 0 && j - 1 >= 0) {
                arr4[n4 - 1][j - 1] = k;
                i = n4 - 1;
                --j;
            }
            else if (i - 1 >= 0 && j - 1 < 0) {
                arr4[i - 1][n4 - 1] = k;
                --i;
                j = n4 - 1;
            }
            else if (i - 1 < 0 && j - 1 < 0 && arr4[n4 - 1][n4 - 1] != 0 && i + 1 < n4) {
                arr4[i + 1][j] = k;
                ++i;
            }

            ++k;
        }

        i = 0;
        j = static_cast<int>(n4 / 2);
        arr2[i][j] = k;

        ++k;

        // Заполняем второй магический квадрат
        while (k < pred3 + 1) {
            if (i - 1 >= 0 && j - 1 >= 0 && arr2[i - 1][j - 1] == 0) {
                arr2[i - 1][j - 1] = k;
                --i;
                --j;
            }
            else if (i - 1 >= 0 && j - 1 >= 0 && arr2[i - 1][j - 1] != 0 && i + 1 < n4) {
                arr2[i + 1][j] = k;
                ++i;
            }
            else if (i - 1 < 0 && j - 1 >= 0) {
                arr2[n4 - 1][j - 1] = k;
                i = n4 - 1;
                --j;
            }
            else if (i - 1 >= 0 && j - 1 < 0) {
                arr2[i - 1][n4 - 1] = k;
                --i;
                j = n4 - 1;
            }
            else if (i - 1 < 0 && j - 1 < 0 && arr2[n4 - 1][n4 - 1] != 0 && i + 1 < n4) {
                arr2[i + 1][j] = k;
                ++i;
            }

            ++k;
        }

        i = 0;
        j = static_cast<int>(n4 / 2);
        arr3[i][j] = k;

        ++k;

        // Заполняем третий магический квадрат
        while (k < pred4 + 1) {
            if (i - 1 >= 0 && j - 1 >= 0 && arr3[i - 1][j - 1] == 0) {
                arr3[i - 1][j - 1] = k;
                --i;
                --j;
            }
            else if (i - 1 >= 0 && j - 1 >= 0 && arr3[i - 1][j - 1] != 0 && i + 1 < n4) {
                arr3[i + 1][j] = k;
                ++i;
            }
            else if (i - 1 < 0 && j - 1 >= 0) {
                arr3[n4 - 1][j - 1] = k;
                i = n4 - 1;
                --j;
            }
            else if (i - 1 >= 0 && j - 1 < 0) {
                arr3[i - 1][n4 - 1] = k;
                --i;
                j = n4 - 1;
            }
            else if (i - 1 < 0 && j - 1 < 0 && arr3[n4 - 1][n4 - 1] != 0 && i + 1 < n4) {
                arr3[i + 1][j] = k;
                ++i;
            }

            ++k;
        }

        // Меняем местами два крайних числа слева
        buff = arr1[0][0];
        arr1[0][0] = arr3[0][0];
        arr3[0][0] = buff;

        buff = arr1[n4 - 1][0];
        arr1[n4 - 1][0] = arr3[n4 - 1][0];
        arr3[n4 - 1][0] = buff;

        y = 1; // Отсчёт со второй строки

        // Замена на втором столбике
        while (y < n4 - 1) {
            buff = arr1[y][1];
            arr1[y][1] = arr3[y][1];
            arr3[y][1] = buff;

            ++y;
        }

        k = (n - 2) / 4 - 1; // Высчитываем сколько столбиков сдвигается

        // Сдвигаем столбцы
        if (k > 0) {
            while (k > 0) {
                for (int i = 0; i < n4; ++i) {
                    buff = arr1[i][n4 - k];
                    arr1[i][n4 - k] = arr3[i][n4 - k];
                    arr3[i][n4 - k] = buff;

                    buff = arr2[i][k - 1];
                    arr2[i][k - 1] = arr4[i][k - 1];
                    arr4[i][k - 1] = buff;
                }

                --k;
            }
        }

        // Из маленьких четырёх квадратов собирается магический квадрат
        for (int i = 0; i < n4; ++i) {
            for (int j = 0; j < n4; ++j) {
                magicSquare[i][j] = arr1[i][j];
                magicSquare[i][j + n4] = arr2[i][j];
                magicSquare[i +n4][j] = arr3[i][j];
                magicSquare[i + n4][j + n4] = arr4[i][j];
            }
        }

        for (long long int i = 0; i <n4; ++i) {
            free(arr1[i]);
        }
        free(arr1);

        for (long long int i = 0; i < n4; ++i) {
            free(arr2[i]);
        }
        free(arr2);

        for (long long int i = 0; i < n4; ++i) {
            free(arr3[i]);
        }
        free(arr3);

        for (long long int i = 0; i < n4; ++i) {
            free(arr4[i]);
        }
        free(arr4);
    }

    // Вывод магического квадрата
    if (n > 2) {
        std::cout << "\nMagic square:\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (n < 100) {
                    std::cout << std::setw(4) << magicSquare[i][j] << "";
                }
                else {
                    std::cout << std::setw(10) << magicSquare[i][j] << "";
                }
            }
            std::cout << std::endl;
        }
    }

    clock_t time2 = clock();

    std::cout << time2 - time1 << std::endl;

    for (long long int i = 0; i < n; ++i) {
        free(magicSquare[i]);
    }
    free(magicSquare);


}
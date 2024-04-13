// LR-4-4 Выполнил:Тиханёнок Илья
//Задание 4:Найти локальный минимум матрицы.Подсчитать количество локальных минимумов заданной матрицы.

#include <iostream>
#include <iomanip>

//проверка на пользовательский ввод
long double inputInt()
{
    setlocale(0, "");
    long double a, b;

    std::cout << "Enter:";
    std::cin >> a;

    while (std::cin.peek() == ' ')
        std::cin.ignore(1, ' ');
    while (std::cin.fail() || std::cin.peek() != '\n' || a <= 0 || a != (long double)a || a != round(a)) {
        //cin.peek - не пропускает пробелы
        std::cin.clear();//очищает
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid value.Please,try again:";
        std::cin >> a;
        while (std::cin.peek() == ' ')
            std::cin.ignore(1, ' ');
    }
    return a;
}

int main() {

    // srand(time(NULL));

    int n, m, sum = 0;
    std::cout << "Enter the rows of matrix:";
    n = inputInt();
    std::cout << "Enter the columns of matrix:";
    m = inputInt();

    //инициализация двумерного массива
    int** a = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[m];
    }
    //заполнение массива рандомными числами

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            a[i][j] = rand() % 90 + 10;
            std::cout << a[i][j] << "   ";
        }

        std::cout << "\n";
    }

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            if (j < m - 1 && j >= 0) {

                if (a[i][j] > a[i][j + 1]) {

                    continue;
                }
            }
            if (j > 0 && j <= m - 1) {

                if (a[i][j] > a[i][j - 1]) {

                    continue;
                }
            }
            if (i >= 0 && i < n - 1) {

                if (a[i][j] > a[i + 1][j]) {

                    continue;
                }
            }
            if (i > 0 && i <= n - 1) {

                if (a[i][j] > a[i - 1][j]) {

                    continue;
                }
            }

            sum++;
        }
    }

    std::cout << "The number of local minimum:" << sum << "\n";

    for (int i = 0; i < n; i++) {

        delete a[i];
    }

    delete[] a;

    return 0;
}

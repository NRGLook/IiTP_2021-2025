// LR-4-5 Выполнил:Тиханёнок Илья
//Задание 5:Cгладить заданную матрицу (через среднее арифметическое).

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
        std::cout << "Invalid value.Please,try again( or remove programm):";
        std::cin >> a;
        while (std::cin.peek() == ' ')
            std::cin.ignore(1, ' ');
    }
    return a;
}

int main()
{
    //srand(time(NULL));

    double n, m;
    int min = 0;
    std::cout << "Enter the rows of matrix:";
    n = inputInt();
     std::cout << "Enter the columns of matrix:";
    m = inputInt();

    //инициализация двумерного массива
    double** arr = new double* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new double[m];
    }
    //заполнение массива рандомными числами

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            arr[i][j] = rand() % 90 + 10;
            std::cout << arr[i][j] << "   ";
        }

        std::cout << "\n";
    }
    //будем работать с веществ матрицей(так как это сказано в условии) для этого берем double
    double** arr1 = new double* [n];
    for (int i = 0; i < n; i++) {
        arr1[i] = new double[m];
    }

    if ((n > 1) && (m > 1)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0) && (j == 0)) {
                    arr1[i][j] = (arr[i][j + 1] + arr[i + 1][j]) / 2;
                }
                if ((i == n - 1) && (j == 0)) {
                    arr1[i][j] = (arr[i][j + 1] + arr[i - 1][j]) / 2;
                }
                if ((i == n - 1) && (j == m - 1)) {
                    arr1[i][j] = (arr[i][j - 1] + arr[i - 1][j]) / 2;
                }
                if ((i == 0) && (j == m - 1)) {
                    arr1[i][j] = (arr[i][j - 1] + arr[i + 1][j]) / 2;
                }
                if ((i == 0) && (j > 0) && (j < m - 1)) {
                    arr1[i][j] = (arr[i][j - 1] + arr[i + 1][j] + arr[i][j + 1]) / 3;
                }
                if ((i == n - 1) && (j > 0) && (j < m - 1)) {
                    arr1[i][j] = (arr[i][j + 1] + arr[i][j - 1] + arr[i - 1][j]) / 3;
                }
                if ((j == 0) && (i > 0) && (i < n - 1)) {
                    arr1[i][j] = (arr[i][j + 1] + arr[i + 1][j] + arr[i - 1][j]) / 3;
                }
                if ((j == m - 1) && (i > 0) && (i < n - 1)) {
                    arr1[i][j] = (arr[i][j - 1] + arr[i + 1][j] + arr[i - 1][j]) / 3;
                }
                if ((i > 0) && (i < n - 1) && (j > 0) && (j < m - 1)) {
                    arr1[i][j] = (arr[i][j - 1] + arr[i + 1][j] + arr[i - 1][j] + arr[i][j + 1]) / 4;
                }
            }
        }
    }
    else if ((n == 1) && (m > 1)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j == 0) {
                    arr1[i][j] = arr[i][j + 1];
                }
                if (j == m - 1) {
                    arr1[i][j] = arr[i][j - 1];
                }
                if ((j > 0) && (j < m - 1)) {
                    arr1[i][j] = (arr[i][j + 1] + arr[i][j - 1]) / 2;;
                }
            }
        }
    }
    else if ((n > 1) && (m == 1)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0) {
                    arr1[i][j] = arr[i + 1][j];
                }
                if (i == n - 1) {
                    arr1[i][j] = arr[i - 1][j];
                }
                if ((i > 0) && (i < n - 1)) {
                    arr1[i][j] = (arr[i + 1][j] + arr[i - 1][j]) / 2;;
                }
            }
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr1[i][j] = arr[i][j];
            }
        }
    }
  
    std::cout << "\n\n";

    //выводим вещественную матрицу
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        std::cout << std::fixed << std::setprecision(1) << arr1[i][j] << "   ";
        std::cout << "\n";
    }

    return 0;
}
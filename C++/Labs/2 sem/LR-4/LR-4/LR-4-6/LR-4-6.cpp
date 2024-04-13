// LR-4-6 Выполнил:Тиханёнок Илья
//Задание 6:Преобразование матрицы.

#include<iostream>

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
        std::cout << "Некорректный ввод.Попробуйте снова(или перезапустите программу):";
        std::cin >> a;
        while (std::cin.peek() == ' ')
            std::cin.ignore(1, ' ');
    }
    return a;
}

int main()
{
    //srand(time(NULL));

    int n, m, min = 0;
    std::cout << "Enter the rows of matrix:";
    n = inputInt();
    std::cout << "Enter the columns of matrix:";
    m = inputInt();

    //инициализация двумерного массива
    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
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
    int** arr1 = new int* [n];
    for (int i = 0; i < n; i++) {
        arr1[i] = new int[m];
    }

    if ((n > 1) && (m > 1)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr1[0][0] = arr[0][0];
                if ((i == 0) && (j > 0) && (j <= m - 1)) {
                    if (arr[i][j] < arr[i][j - 1]) {
                        arr1[i][j] = arr[i][j - 1];
                    }
                    else {
                        arr1[i][j] = arr[i][j];
                    }
                }
                if ((j == 0) && (i > 0) && (i <= n - 1)) {
                    if (arr[i][j] < arr[i - 1][j]) {
                        arr1[i][j] = arr[i - 1][j];
                    }
                    else {
                        arr1[i][j] = arr[i][j];
                    }
                }
                if (((i == n - 1) && (j > 0) && (j <= m - 1)) || ((j == m - 1) && (i > 0) && (i <= n - 1)) || ((i > 0) && (i <= n - 1) && (j > 0) && (j <= m - 1))) {
                    if ((arr[i][j] < arr[i - 1][j]) || (arr[i][j] < arr[i][j - 1]) || (arr[i][j] < arr[i - 1][j - 1])) {
                        if (arr[i - 1][j] > arr[i][j - 1]) {
                            arr1[i][j] = arr[i - 1][j];
                        }
                        else if (arr[i][j] < arr[i][j - 1]) {
                            arr1[i][j] = arr[i][j - 1];
                        }
                        else {
                            arr1[i][j] = arr[i - 1][j - 1];
                        }
                    }
                    else {
                        arr1[i][j] = arr[i][j];
                    }
                }
            }
        }

    }

    std::cout <<"\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cout << arr1[i][j] << "   ";
        std::cout << "\n";
    }
    return 0;
}

// LR-4-9 Выполнил:Тиханёнок Илья
//Задание 9:Перемножить две матрицы заданные пользователем.И вывести полученную матрицу.


#include <iostream>

//проверка на пользовательский ввод
long double inputInt()
{
    setlocale(0, "");
    long double a;

    std::cout << "Ввод:";
    std::cin >> a;

    while (std::cin.peek() == ' ')
        std::cin.ignore(1, ' ');
    while (std::cin.fail() || std::cin.peek() != '\n' || a <= 0 || a != (long double)a || a != round(a)) {
        //cin.peek - не пропускает пробелы
        std::cin.clear();//очищает
        std::cin.ignore(10000, '\n');
        std::cout << "Некорректный ввод.Попробуйте снова:(или перезапустите программу)";
        std::cin >> a;
        while (std::cin.peek() == ' ')
            std::cin.ignore(1, ' ');
    }
    return a;
}

int main()
{
    int row1, row2, col1, col2,k,l;
    setlocale(LC_ALL, "Rus");
    std::cout << "Программа может умножить две матрицы.(при вводе корректных значений)\nВведите количество строк первой матрицы: ";
    row1 = inputInt();
    std::cout << "Введите количество столбцов первой матрицы: ";
    col1 = inputInt();
    std::cout << "Введите количество строк второй матрицы: ";
    row2 = inputInt();
    std::cout << "Введите количество столбцов второй матрицы: ";
    col2 = inputInt();
    if (col1 != row2) {
        std::cout << "Умножение невозможно!Перезапустите программу.";
        exit(1);
    }

    //Объявляем первую матрицу
    int** a = (int**)malloc(row1 * sizeof(int*));
    for (int i = 0; i < row1; i++) {
        a[i] = (int*)malloc(col1 * sizeof(int));
    }
    //Вводим элементы первой матрицы
    std::cout << "Введите элементы первой матрицы\n";
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            std::cout << "Введите число для " << i + 1 << " ряда и " << j + 1 << " столба:";
            k = inputInt();
        }
    }

    //Объявляем вторую матрицу
    int** b = (int**)malloc(row2 * sizeof(int*));
    for (int i = 0; i < row2; i++) {
        b[i] = (int*)malloc(col2 * sizeof(int));
    }

    //Вводим элементы второй матрицы (поштучно)
    std::cout << "Введите элементы второй матрицы\n";
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            std::cout << "Введите число для " << i + 1 << " ряда и " << j + 1 << " столба:";
            l = inputInt();
        }
    }

    // Умножение матриц+Объявление 3 матрицы
    int** c = (int**)malloc(row1 * sizeof(int*));
    for (int i = 0; i < row1; i++) {
        c[i] = (int*)malloc(col2 * sizeof(int));
        for (int j = 0; j < col2; j++) {
            c[i][j] = 0;
            for (int k = 0; k < col1; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }

    // Вывод первой матрицы
    std::cout << "Первая матрица:\n";
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    // Вывод второй матрицы
    std::cout << "Вторая матрица:\n";
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            std::cout << b[i][j] << " ";
        }
        std::cout <<"\n";
    }
    std::cout <<"\n";

    // Вывод полученной матрицы 
    std::cout << "Матрица  полученная произведением матриц:\n";
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
            std::cout << c[i][j] << "  ";
        std::cout << "\n";
    }

    //очищение памяти для всех 3 матриц
    for (int i = 0; i < row1; i++) {
        free(a[i]);
    }
    for (int i = 0; i < row2; i++) {
        free(b[i]);
    }
    for (int i = 0; i < col1; i++) {
        free(c[i]);
    }

    free(a);
    free(b);
    free(c);

    return 0;
}
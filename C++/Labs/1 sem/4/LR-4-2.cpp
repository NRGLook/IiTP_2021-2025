// LR-4-2 Выполнил:Тиханёнок Илья
/*Задание 2:Инициализировать при объявлении статический двумерый массив целых чисел размеров N*M.
Выполнить в соответствии с номером варианта индивидуальное задание и вывести на экранисходные данные и полученый результат.
Найти сумму элементов, расположенных в четных(по номеру) строках матрицы.*/

#include <iostream>

//проверка на пользовательский ввод
long double inputInt()
{
    setlocale(0," ");
    long double a, b;

    std::cout << "Ввод:";
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
    setlocale(LC_ALL, "Rus");
    int i, j, n, m;

    std::cout << "Введите размер матрицы N x M:";
    n = inputInt();
    m = inputInt();

    //инициализация двумерного массива
    int **a = new int*[n];
    for (i = 0; i < n; i++) {
        a[i] = new int[m];
    }
    //Ввод массива:
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            std::cout << "Введите a[" << i << "][" << j << "]: ";
            std::cin >> a[i][j];
        }
    std::cout << "Массив A:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            std::cout << a[i][j] << " ";
            std::cout <<"\n";
    }
    int sum = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
        {
            if ((i+1)% 2 == 0)//четная или нечентная строка?
                sum += a[i][j];
        }
    }

    std::cout << "Сумма элементов расположенных в строках матрицы равна :" << sum << "\n";

    return 0;
}
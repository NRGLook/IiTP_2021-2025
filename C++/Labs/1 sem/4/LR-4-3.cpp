// LR-4-3 Выполнил:Тиханёнок Илья
/*Задание 3:Память для массива выделить динамически.Выполнить в соответствии с номером варианта индивидуальное задание 
и вывести на экран исходные данные и полученный результат.Найти сумму и произведение указанных элементов.*/

#include <iostream>
#include <time.h>

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

int main()
{
    srand(time(NULL));

    int n, p = 1, k = -1, s=0;
   
    std::cout << "Enter the size of matrix:";
    n = inputInt();

    //инициализация двумерного массива
    int** a = new int* [n];
    for ( int i = 0; i < n; i++) {
        a[i] = new int[n];
    }
    //заполнение массива рандомными числами

    for ( int i = 0; i < n; ++i)
    {
        for ( int j = 0; j < n; ++j)
        {
            a[i][j] = rand()%10;
            std::cout << a[i][j] << "   ";
        }

        std::cout << "\n";
    }

    for (int i = 0; i < n; ++i) {
        if (n / 2 >= i) {
            k++;
        }
        else {
            k--;
        }
        for (int j = k; j < n - k; ++j) {
            s += a[i][j];
            p *= a[i][j];
        }
    }

    std::cout << "\n" << "The amount: " << s << " .\nCompozition: " << p << ".";

    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }

    delete[] a;
   
}

// LR-4-1 Выполнил:Тиханёнок Илья
/*Задание 1:Вывести одномерный статический массив из k чисел.Выполнить в соответствии с номером варианта индивидуальное задание и вывести
на экран исходные данные и полученный результат.Определить количество элементов,значение которых больше среднего значения всех
элементов.*/

#include <iostream>

//проверка на пользовательский ввод
long double inputInt()
{
    setlocale(0, " ");
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
    int  step1, laststep, j = 0, sn = 0;
    float number = 0.0;

    std::cout << "Введите кол-во элементов массива:";
    step1 = inputInt();

    int* masfirst = new int[step1];

    for (j = 0; j < step1; ++j) {
        std::cout << j+1 << " элемент: ";
        std::cin >> masfirst[j];
        number += masfirst[j];
    }

    number = number / step1;

    for (laststep = 0; laststep < step1; ++laststep) {
        if (masfirst[laststep] > number)
            ++sn;
    }

    std::cout << "Среднее значение массива равно: " << number << ".\n";
    std::cout << "Число больших , чем среднее значение: " << sn << ".\n\n";

    return 0;
}

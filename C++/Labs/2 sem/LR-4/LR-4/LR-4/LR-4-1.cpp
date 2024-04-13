// LR-4-1 Выполнил:Тиханёнок Илья
/*Задание 1:Вывести одномерный статический массив из k чисел.Выполнить в ссответствии с номером варианта индивидуальное задание и вывести
на экран исходные данные и полученный результат.Определить количество элементов,значение которых больше среднего значения всех
элементов.*/

#include <iostream>

int main()
{
    setlocale(LC_ALL, "Rus");
    int  step1, laststep, number = 0, j = 0, sn = 0;

    std::cout << "Введите кол-во элементов массива:";
    std::cin >> step1;

    int* masfirst = new int[step1];

    for (j = 0; j < step1; ++j) {
        std::cin >> masfirst[j];
        number += masfirst[j];
    }

    number = number / step1;

    for (laststep = 0; laststep < step1; ++laststep) {
            if (masfirst[laststep] > number)
                ++sn;
    }

    std::cout << "Среднее значение массива равно: " << number << "\n";
    std::cout << "Число больших , чем среднее знач " << sn;

    return 0;
}



// LR-5-2 Выполнил:Тиханенок Илья
/*Задание 2:Для заданного одномерного массива A из N элементов проверить, что существует по
крайней мере один элемент Ai, для которого выполняется условие Ai ≤ i2.Рекурсивную функцию применять каждый раз отдельно
для каждой из половин массива.Рекурсивные вызовы заканчивать, когда останется только один элемент.*/

#include <iostream>
#include <Windows.h>

/* Рекурсивная функция : в качетсве параметров принимает условный участок массива начиная с элемента под индексом end до индекса
start (проверяем от большего элемента по индексу до меньшего)*/

int main()
{
    HINSTANCE load;
    load = LoadLibrary(L"DynamicLIb.dll");
    typedef bool (*elementexist)(int*, int, int);
    elementexist elementExist = (elementexist)GetProcAddress(load, "elementExist");
    setlocale(LC_ALL, "");
    int size;
    std::cout << "Enter the number of elements of matrix:";
    std::cin >> size;

    int* A = new int [size];

    //Enter and generate array(input elements of array):
    for (int i = 0; i < size; i++)
        {
            std::cout << "Enter B[" << i << "]: ";
            std::cin >> A[i];
        }
    //Output array:
    std::cout << "Array:\n";
    for (int i = 0; i < size; i++)
    {
        std::cout << A[i] << "  ";
    }

    bool temp1, temp2;

    //Проверка первой половины массива
    temp1 = elementExist(A, 0, (size / 2) - 1);
    //Проверка второй половины массива
    temp2 = elementExist(A, size / 2, size - 1);

    if (temp1 || temp2) std::cout << "Элемент ai <= i*i в данном массиве существует!\n";
    else std::cout << "Элемент ai <= i*i в данном массиве не существует!\n";

    system("pause");
    FreeLibrary(load);

    return 0;
}

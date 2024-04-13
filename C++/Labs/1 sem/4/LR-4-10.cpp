// LR-4-10 Выполнил:Тиханёнок Илья
//Задание 10:Построить магический квадрат любого порядка.

#include <iostream>
#include <malloc.h>

//проверка на пользовательский ввод
long double inputInt()
{
    setlocale(0, "");
    long double a;

    std::cout << "Enter:";
    std::cin >> a;

    while (std::cin.peek() == ' ')
        std::cin.ignore(1, ' ');
    while (std::cin.fail() || std::cin.peek() != '\n' || a <= 0 || a != (long double)a || a != round(a)) {
        //cin.peek - не пропускает пробелы
        std::cin.clear();//очищает
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid value.Try again(or restart programm)";
        std::cin >> a;
        while (std::cin.peek() == ' ')
            std::cin.ignore(1, ' ');
    }
    return a;
}

int main()                  
{
    //Магический квадрат(для нечетн)
    srand(time(NULL));
    int size = 0;
    std::cout << "Enter the size of square: ";
    size = inputInt();

    if (!(size & 1)) {
        std::cout << "Enter an odd integer:";
        std::cin.get();
        return(1);
    }

    int max_size = size + (size - 1);

    int* square = (int*)malloc(max_size * max_size * 4);
    int i, j;
    for (i = 0; i < max_size; i++)
        for (j = 0; j < max_size; j++)
            square[i * max_size + j] = 0;
    int k = 1;
    i = (max_size >> 1);
    j = 0;
    while (i < max_size) {
        int i1 = i;
        int j1 = j;
        int edge = size >> 1; //edge-расстояние от границы увеличенного массива
        while (j1 < ((j + (max_size >> 1)) + 1)) {
                square[i1 * max_size + j1] = k;
            if ((i1 > (edge)) && (j1 < (edge))) //левая грань
                square[i1 * max_size + j1 + size] = k;
            if ((i1 > (size + edge) - 1) && (j1 > (edge)))
                square[(i1 - size) * max_size + j1] = k; //нижняя грань
            if ((i1 < (edge)) && (j1 > (edge)))
                square[(i1 + size) * max_size + j1] = k; //верхняя грань
            if ((i1 > (edge)) && (j1 > (size + edge) - 1))
                square[i1 * max_size + j1 - size] = k; //правая грань
            --i1;
            ++j1;
            ++k;
        }
        ++i;
        ++j;
    }

    std::cout << "Magic square:\n\n ";

    int a = (size >> 1) * max_size;   //размер верхней грани
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++)
            std::cout << square[a + (size >> 1) + i * (size - 1) + i * size + j] << " ";  // size >> 1 - элементы слева;i * (size - 1) - элементы слева и справа;i * size - элементы, которые мы вывели раньше
        std::cout << "\n";
    }

    free(square);

    std::cin.get();
    return 0;
}

// LR-4-7 Выполнил:Тиханёнок Илья
/*Задание 7:Дано натуральное число n.Требуется подсчитать количество цифр
числа и определить, какая цифра стоит в разряде с номером i(разряды нумеруются с конца,
т.е.разряд единиц имеет номер 0).*/

#include <iostream>

//проверка на пользовательский ввод
long double inputInt()
{
    setlocale(0, "");
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
    int temp,I;
    std::cout << "Введите натуральное число N (N-число, возникающее естественным образом при счёте): ";
    temp = inputInt();
    const int N = temp;
    int count = 1;
    temp = N;

    while (temp /= 10)//проверяем "правильность" массива
        count++;
    int* p = new int[count];//инициализация одномерного массива
    int i = 0;
    temp = N;
    //прибавляем пока не закончится наш массив
    do {
        p[i++] = temp % 10;
        temp /= 10;
    } while (temp);

    std::cout << "Введите номер разряда i: ";
    I = inputInt();
    std::cout << "\n";

    //случай если пользователь введет "разряд" больший чем есть(согласование слов разряд и число...(как и грибы))
    if (I >= count) {
        if (count - 1 % 10 == 1) {
            if (count - 1 == 11) {
                std::cout << "В числе всего " << count - 1 << " разрядов." <<"\n";
            }
            else {
                std::cout << "В числе всего " << count - 1 << " разряд." <<"\n";
            }
        }
        else {
            if ((count - 1 % 10 >= 2) && (count - 1 % 10 <= 4)) {
                if ((count - 1 >= 12) && (count - 1 <= 14)) {
                    std::cout << "В числе всего " << count - 1 << " разрядов." <<"\n";
                }
                else {
                    std::cout << "В числе всего " << count - 1 << " разряда." <<"\n";
                }
            }
            else {
                std::cout << "В числе всего " << count - 1 << " разрядов." << "\n";
            }
        }
    }
    //обычный случай,когда корректный ввод
    else if ((I < count) && (I != 0)) {
        std::cout << "Цифра " << I << " разряда " << p[I];
    }
    else {
        std::cout << "Цифра " << I << " разряда " << p[I];
    }

    //выводим количество цифр в заданном пользователем числе
    std::cout << "\n";
    std::cout << "Количество цифр в числе:" << count;

    return 0;
}


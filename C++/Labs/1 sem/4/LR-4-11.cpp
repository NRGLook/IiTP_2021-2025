// LR-4-11 Выполнил:Тиханенок Илья
//Задание 11:Для заданной матрицы найти диагональ с наибольшей суммой.

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

int main() {
    int n;
    setlocale(LC_ALL, "Rus");
    std::cout << "Введите размер матрицы 'n'.";
    n = inputInt();
    int zi = n, yi = n, xi = n;
    int sum1 = 0,sum2=0,sum3=0,sum4=0;
    int*** a = new int** [n];
    for (int i = 0; i < zi; i++) {
        a[i] = new int*[yi];

        for (int j = 0; j < yi; j++) {
            a[i][j] = new int[xi];
        }
    }

    for (int z = 0; z < zi; z++) {
        for (int y = 0; y < yi; y++) {
            for (int x = 0; x < xi; x++) {
                a[z][y][x] = rand() % 90 + 10;
            }
        }
    }
    for (int z = 0; z < zi; z++) {
        std::cout << "Сторона " << (z + 1) << std::endl;
        for (int y = 0; y < yi; y++) {
            for (int x = 0; x < xi; x++) {
                std::cout << a[z][y][x] << "  ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    for (int z = 0; z < zi; z++) {
        int x = zi - z - 1;
        sum1 += a[z][z][z];
        sum2 += a[z][zi - 1 - z][zi - 1 - z];
        sum3 += a[z][z][x];
        sum4 += a[z][x][z];
    }
     
    std::cout << "Сумма 1:" << sum1 << "\n";
    std::cout << "Сумма 2:" << sum2 << "\n";
    std::cout << "Сумма 3:" << sum3 << "\n";
    std::cout << "Сумма 4:" << sum4 << "\n";

    if (sum1 >= sum2 && sum1 >= sum3 && sum1 >= sum4) {
        std::cout << "Диагональ с наибольшей суммой: " << sum1;
    }
    else if (sum2 >= sum1 && sum2 >= sum3 && sum2 >= sum4) {
        std::cout << "Диагональ с наибольшей суммой: " << sum2;
    }
    else if (sum3 >= sum1 && sum3 >= sum2 && sum3 >= sum4) {
        std::cout << "Диагональ с наибольшей суммой: " << sum3;
    }
    else if (sum4 >= sum1 &&  sum4 >= sum3 && sum4 >= sum2) {
        std::cout << "Диагональ с наибольшей суммой: " << sum4;
    }
    
    return 0;
}

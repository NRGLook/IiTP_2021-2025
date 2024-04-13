// LR-3-5 Выполнил:Тиханенок Илья
/*Задача 5. Необходимо разложить функцию Y(x) из своего варианта в ряд S(x), затем с помощью полученного ряда найти значение функции
и сравнить его со значением, вычисленным с помощью стандартных функций. Программа должна запросить у пользователя количество членов 
ряда (n), затем запросить у пользователя количество чисел, от которых он хочет посчитать функцию, затем пользователь вводит по одному
числу (x от 0.1, до 1), программа считает значение функции с помощью ряда и с помощью стандартных функций и выводит оба значения.
Использование <cmath> запрещено.*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>//printf-scanf

using namespace std;

long double inputInt()
{
    setlocale(LC_ALL, "Rus");
    long double k;

    cout << "Введите кол-во членов ряда:";
    cin >> k;

    while (cin.peek() == ' ')
        cin.ignore(1, ' ');
    while (cin.fail() || cin.peek() != '\n' || k <= 0 || k != (long double)k || k != round(k)) {
        //cin.peek - не пропускает пробелы
        cin.clear();//очищает
        cin.ignore(10000, '\n');
        cout << "Некорректный ввод.Попробуйте снова.";
        cout << "Введите кол-во членов ряда:";
        cin >> k;
        while (cin.peek() == ' ')
            cin.ignore(1, ' ');
    }

    return k;
    
}
long double inputInt2()
{
    setlocale(LC_ALL, "Rus");
    long double num;

    cout << "Введите количество чисел, для которых вы хотите посчитать функцию:";
    cin >> num;

    while (cin.peek() == ' ')
        cin.ignore(1, ' ');
    while (cin.fail() || cin.peek() != '\n' || num <= 0 || num != (long double)num  || num != round(num)) {
        //cin.peek - не пропускает пробелы
        cin.clear();//очищает
        cin.ignore(10000, '\n');
        cout << "Некорректный ввод.Попробуйте снова.";
        cout << "Введите количество чисел, для которых вы хотите посчитать функцию:";
        cin >> num;
        while (cin.peek() == ' ')
            cin.ignore(1, ' ');
    }

    return num;

}

//использую функцию для подсчета степени
long double look (long double x, long double c) {
    if (c == 0) {
        return 1;
    }
    else {
        return x *= look(x, --c);
    }
}

int main() {
    setlocale(0, "");

    double y = 1;
    double u = 1;
    double s = 0, sn, sk, x, ux = 1;
    long double k= inputInt();
    long double num = inputInt2();

    if (num != 1) {
        for (int i = 1; i <= num; i++) {
            cout << "\nВведите х:";
            cin >> x;
            if (x < 0.1 || x > 1) {
                cout << "\nОшибка!Попробуйте снова.Введите х:";
                cin >> x;
            }
            sk = log(1 / (2 + 2 * x + x * x));
            cout << setprecision(9) << "\nCode with cmath:" << sk;

            for (int j = 1; j <= k; j++) {
                sn = look(-1, (j)) * look((1 + x), (2 * j)) / j;
                s += sn;
            }
            cout << "\nCode without cmath:" << s;
        }
    }
    else {
        cout << "\nВведите х:";
        cin >> x;
        if (x < 0.1 || x > 1) {
            cout << "\nОшибка!Введите х:";
            cin >> x;
        }
        sk = log(1 / (2 + 2 * x + x * x));
        cout << setprecision(9) << "\nCode with cmath:" << sk;
        for (int j = 1; j <= k; j++) {
            sn = look(-1, (j)) * look((1 + x), (2 * j)) / j;
            s += sn;
        }
        cout << "\nCode without cmath:" << s;
    }

    return 0;

}




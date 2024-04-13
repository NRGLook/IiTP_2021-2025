// LR-6-9 Выполнил:Тиханёнок Илья
/*Задание 9:Сумма чисел в строке .В заданной строке, состоящей из букв, цифр и прочих символов, найдите 
сумму всех чисел*/

#include <iostream>
#include <sstream>
#include<Windows.h>
#include <iomanip>

using namespace std;


string input(int minValue, int maxValue) {
    string str;
    while (true)
    {
        getline(cin, str);
        if (str.length() < maxValue && str.length() > minValue)
            return str;
        cin.clear();
        cin.ignore(32000, '\n');
        str = "";
        cout << "Enter correct word: ";
    }
}

double Sum(string str1) {

    double sum = 0, tmp, count = 0, f, s;
    bool M, N;

    while (count < str1.length()) {
        M = false;

        if (isdigit(str1[count])) {
            if (count != 0 && str1[count - 1] == '-')
            {
                tmp = str1[count] - '0';

                M = true;
            }
            else {
                tmp = str1[count] - '0';
            }

            ++count;

            while (isdigit(str1[count])) {
                tmp = tmp * 10 + (str1[count] - '0');

                ++count;
            }

            f = 1;

            if (str1[count] == '.' && isdigit(str1[count + 1])) {
                ++count;

                while (isdigit(str1[count])) {
                    f *= 10;

                    tmp = tmp + (long double)(str1[count] - '0') / f;

                    ++count;
                }
            }

            if ((str1[count] == 'e' || str1[count] == 'E') && (isdigit(str1[count + 1]) || (str1[count + 1] == '+' && isdigit(str1[count + 2])) || (str1[count + 1] == '-' && isdigit(str1[count + 2])))) {
                N = false;

                ++count;

                if (str1[count] == '-') {
                    N = true;
                    ++count;
                }
                else if (str1[count] == '+') {
                    ++count;
                }

                s = str1[count] - '0';

                ++count;

                while (isdigit(str1[count])) {
                    s = s * 10 + (str1[count] - '0');
                    ++count;
                }

                if (N) {
                    s *= -1;
                }

                tmp *= pow(10, s);
            }

            if (M) {
                tmp *= -1;
            }


            sum += tmp;
        }

        ++count;
    }

    return sum;
}

int main() {
    setlocale(0, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Enter the word where you should find the amount of numbers: \n";

    string str1 = input(0, 101);
    cout<<fixed<<setprecision(5) << Sum(str1);
    return 0;
}
// Pashyk.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;
int TMP(int Value, int System) {
    int a = Value, tmp = 0, b;
    while (a > System - 1)
    {
        b = a % System;
        tmp++;
        a /= System;
    }
    tmp++;
    return tmp;
}
int SysConTo10(char str[], int sys) {
    float k, res = 0, st = 0, tmp = strlen(str);
    for (int i = tmp - 1; i >= 0; i--) {
        switch (str[i]) {
        case 'a': k = 10;
            break;
        case 'b': k = 11;
            break;
        case 'c': k = 12;
            break;
        case 'd': k = 13;
            break;
        case 'e': k = 14;
            break;
        case 'f': k = 15;
            break;
        default: k = (int)str[i];
            break;
        }
        if (k >= 48) {
            k -= 48;
        }
        if (k >= sys) {
            cout << "Число " << k << " не может находиться в данной системе счисления.\n";
            break;
            return 0;
        }
        else if (k != sys) {
            res += pow(sys, st) * k;
            st++;
        }
    }
    return res;
}

void main()
{
    setlocale(LC_CTYPE, "rus");
    int m, res = 0, st = 0; // m - основание системы счисления, res - результат, st - степень, val - строка в которую введено число;
    char val[100] = " ";
    cout << "Введите число: "; gets_s(val);
    cout << "Введите основание системы счисления: ";
    cin >> m;
    res = SysConTo10(val, m); // Функиция, переводящая в 10-ную систему счисления;
    int m2 = 0;
    cout << "В какую систему счисления вы хотите перевести число ?" << endl;
    cin >> m2;
    int tmp2 = TMP(res, m2);
    for (int i = 0; i < tmp2; i++) {
        int b = res % m2;
        switch (b)
        {
        case 10: {
            val[i] = 'a';
            res /= m2;
        }
               break;
        case 11: {
            val[i] = 'b';
            res /= m2;
        }
               break;
        case 12: {
            val[i] = 'c';
            res /= m2;
        }
               break;
        case 13: {
            val[i] = 'd';
            res /= m2;
        }
               break;
        case 14: {
            val[i] = 'e';
            res /= m2;
        }
               break;
        case 15: {
            val[i] = 'f';
            res /= m2;
        }
               break;
        default: {
            if (b < 48) {
                b += 48;
            }
            val[i] = b;
            res /= m2;
        }
               break;
        }
    }
    for (int i = tmp2 - 1; i > -1; i--)
        cout << val[i];
    cout << endl;
}


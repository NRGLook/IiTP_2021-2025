#include <iostream>

using namespace std;

long double fact(long double k) {
    if (k == 0 || k == 1) {
        return 1;
    } else {
        return k * fact(k - 1);
    }
}

long double power(long double n, long double m) {
    long double k = 1;

    while (m > 0) {
        k = k * n;

        m--;
    }

    return k;
}

int main() {
    long double x, a, b, c, aPow, aFact, ax;
    int sign;

    cout << "Введите x: ";
    cin >> x;
    cout << endl;

    ax = x;

    if (ax > 0) {
        while (ax > 10) {
            ax -= 6.28318530718;
        }
    } else {
        while (ax < -10) {
            ax += 6.28318530718;
        }
    }

    for (int i; i != 20; i++) {
        sign = power(-1, i);

        aPow = power(ax, 2 * i + 1);

        aFact = fact(2 * i + 1);

        a = a + (sign * aPow) / aFact;
    }

    aPow = 0;
    aFact = 0;

    for (int i; i != 20; i++) {
        sign = power(-1, i + 1);

        aPow = power(ax, 2 * i);

        aFact = fact(2 * i);

        b += (sign * aPow) / aFact;
    }

    b = 1 - b;

    if ( x >= 0 && x <= 2) {
        x -= 1;

        for (int i = 1; i < 10000; i += 2) {
            c += (power(x, i) / (long double)i - power(x, i + 1) / (long double)(i + 1));
        }
    }
    else if (x > 2) {
        x = (x / (x - 1));

        for (int i = 1; i < 20000; i++) {
            c += 1 / (i * power(x,i));
        }
    }

    cout << "Наименьшее значение имеет функция ";

    if (ax != 0) {
        if (a > b && b > c) {
            cout << "ln(x) = " << c;
        } else if (a > b && b < c) {
            cout << "cos(x) = " << b;
        } else {
            cout << "sin(x) = " << a;
        }
    } else {
        if (a > b) {
            cout << "cos(x) = " << b;
        } else {
            cout << "sin(x) = " << a;
        }
    }

    return 0;
}

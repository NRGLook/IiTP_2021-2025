// LR-2-10 Выполнил:Тиханёнок Илья
/*Задача 10. Из величин, определяемых выражениями a = sinx, b = cosx, c = ln|x|
при заданном х, определить и вывести на экран дисплея минимальное
значение. Библиотеку <cmath> использовать запрещено.*/


#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	long double sin, xk, ck, x, k, z, cos, ln, min_value, xl, xl3, xl5, xl7, xl9, xl11, xl13, xl15, xl17;
	setlocale(LC_ALL, "Rus");

	cout << "Введите x:";
	cin >> x;

	xl = x; //дополнительная переменная для логарифма
	x = x - ((int)(x / 6.2831853)) * 6.2831853;
	xk = x;
	sin = xk;

	for (k = 0; k <= 1000000; k++)
	{
		xk = xk * (-1) * x * x / ((2 * k + 2) * (2 * k + 3));
		sin = sin + xk;
	}

	cout << setprecision(6) << "sinx = " << sin << endl;

	ck = 1;
	cos = ck;

	for (k = 0; k <= 1000000; k++)
	{
		ck = ck * (-1) * x * x / ((2 * k + 1) * (2 * k + 2));
		cos = cos + ck;
	}

	cout << setprecision(6) << "cosx = " << cos << endl;

	//нахождение обратной функции

	if (xl < 0)
	{
		xl = (-xl - 1) / (-xl + 1);
	}
	else
	{
		xl = (xl - 1) / (xl + 1);
	}

	if (x == 0)
	{
		cout << "Логарифм не существует, поэтому наименьшим будет sin :" << sin << endl;
	}
	else if (x < 0)
	{
		cout << "Логарифм не существует.\n";
		min_value = (sin < cos) ? sin : cos;
		cout << "Минимальное значение : " << min_value << endl;
	}

	if (x > 0)
	{
		ln = 0;

		for (double i = xl, n = 1; n <= 1000; i = i * xl * xl, n = n + 2)
		{
			ln = ln + i / n;
		}
		ln = 2 * ln;
		cout << setprecision(9) << "ln|x| = " << ln << endl;
	}

	if (x >= 0)
	{
		min_value = (sin < cos) ? sin : cos;
		if (x != 0)
		{
			min_value = (min_value < ln) ? min_value : ln;
		}
		cout << "Минимальное значение :" << min_value;

		/*if ((sin < cos) && (sin < ln))
		{
			cout << "наименьшее значение это sinx = " << sin << endl;
		}
		else if ((cos < sin) && (cos < ln))
		{
			cout << "наименьшее значение это cosx = " << cos << endl;
		}
		else if ((ln < sin) && (ln < cos))
		{
			cout << "наименьшее значение это ln|x| = " << ln << endl;
		}*/
	}

	return 0;
}

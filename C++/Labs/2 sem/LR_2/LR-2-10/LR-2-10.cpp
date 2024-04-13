// LR-2-10 Выполнил:Тиханёнок Илья
/*Задача 10. Из величин, определяемых выражениями a = sinx, b = cosx, c = ln|x| 
при заданном х, определить и вывести на экран дисплея минимальное 
значение. Библиотеку <cmath> использовать запрещено.*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	double sin, xn, cn, x, n, z, cos, ls, ln;
	setlocale(LC_ALL, "Rus");

	cout << "Программа позволяет определить минИмальное значение функции.(из 3 заданных-sin,cos,ln)\n.Введем аргумент x:";
	cin >> x;

	x = x - ((int)(x / 6.2831853) * 6.2831853);
	xn = x;
	sin = xn;

	for (n = 0; n <= 1000000; n++) {
		xn = xn * (-1) * x * x / ((2 * n + 2) * (2 * n + 3));
		sin = sin + xn;
	}

	cout << setprecision(6) << "\nsin(X)=" << sin;

	cn = 1;
	cos = cn;

	for (n = 0; n <= 1000000; n++) {
		cn = cn * (-1) * x * x / ((2 * n + 1) * (2 * n + 2));
		cos = cos + cn;
	}

	cout << setprecision(6) << "\ncos(x)=" << cos;

	z = (x - 1) / (x + 1);
	ls = z;
	ln = 2 * ls;

	if (x == 0)
		cout << "\nln(x) doesn't exist ( \nThe smalest is sin(x):" << sin << "\n\n\n";
	else if (x < 0) {
		cout << "\nln(x) doen't exist ( \n";
		if (sin < cos)
			cout << "\nsin(x) is the smalest:" << sin << "\n\n\n";
		else if (cos < sin)
			cout << "\ncos(x) is the smalest:" << cos << "\n\n\n";
		else if (sin == cos)
			cout << "\ncos(x) is equal to sin(x) and the're equal to" << sin << "\n\n\n";
	}
	else
	{
		for (n = 0; n < 1000000; n++)
		{
			ls = ls * z * z * (2 * n + 1) / (2 * n + 3);
			ln = ln + 2 * ls;
		}
		cout << setprecision(6) << "\nln(x)=" << ln;
	}

	if (x > 0) {
		if ((sin < cos) && (sin < ln))
			cout << "\nThe smalest is sin(x):" << sin << "\n\n\n";
		else if ((cos < sin) && (cos < ln))
			cout << "\nThe smalest is cos(x):" << cos << "\n\n\n";
	else if ((ln < sin) && (ln < cos))
		cout << "\nThe smalest is ln(x):" << ln << "\n\n\n";
	else if ((sin == cos) && (sin < ln))
		cout << "\nsin(x) is equal to cos(x) and they're the smalest:" << sin << "\n\n\n";
	else if ((sin == ln) && (sin < cos))
		cout << "\nsin(x) is equal to ln(x) and they're the smalest:" << ln << "\n\n\n";
	else if ((cos == ln) && (cos < sin))
		cout << "\ncos(x) is equal to ln(x)and they're the smalest:" << cos << "\n\n\n";
	else if ((sin == cos) && (sin == ln))
		cout << "\nWow,they're all equal:" << sin << "\n\n\n";
}

return 0;

}
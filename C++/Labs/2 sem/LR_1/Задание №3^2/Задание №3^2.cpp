//Лабораторная 1,задание 3.Выполнена:Тиханёнок Илья Александрович
/*На вход даны 6 чисел x1, y1; x2, y2; x3, y3 - координаты вершин А, В, С 
соответственно. Необходимо вычислить:
1. Длину всех сторон треугольника.
2. Длину всех высот треугольника.
3. Длину всех медиан треугольника.
4. Длину всех биссектрис треугольника.
5. Градусную и радианную меру углов треугольника.
6. Радиусы вписанной и описанной окружностей треугольника.
7. Найти площадь и длину этих окружностей.
8. Площадь и периметр треугольника.*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long double x1,y1,x2,y2,x3,y3, AB, BC, CA, hAB, hBC, hCA, mAB, mBC, mCA, bAB, bBC, bCA, cosAB, cosBC, cosCA, cosAB2, cosBC2, cosCA2, r, R, Sr, SR, LR, Lr, S1, S2, S3, p, P,x,y,z;
	double PI = 3.1415926;
	setlocale(LC_ALL, "Rus");

	cout << "Программа позволяет найти все необходимые параметры треугольника.\n Для этого нам нужно будет ввести координаты точек треугольника.\nВведите координаты точки A:";
	cin >> x1 >> y1;
	cout << "\nВведите координаты точки B:";
	cin >> x2 >> y2;
	cout << "\nВведите координаты точки C:";
	cin >> x3 >> y3;

	AB = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	BC = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
	CA = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));

	cout << "\nЗадание 1):" << AB << ";" << BC << ";" << CA << ".\n";

	p = (AB + BC + CA) / 2;
	S1 = sqrt(p * (p - AB) * (p - BC) * (p - CA));
	hAB = (2 * S1) / AB;
	hBC = (2 * S1) / BC;
	hCA = (2 * S1) / CA;
	
	cout << "Задание 2):" << hAB << ";" << hBC << ";" << hCA << ".\n";

	mAB = 0.5 * sqrt(2 * BC * BC + 2 * CA * CA - AB * AB);
	mBC = 0.5 * sqrt(2 * AB * AB + 2 * CA * CA - BC * BC);
	mCA = 0.5 * sqrt(2 * AB * AB + 2 * BC * BC - CA * CA);

	cout << "Задание 3):" << mAB << ";" << mBC << ";" << mCA << ".\n";

	bAB = (sqrt(BC * CA * (AB + BC + CA) * (BC + CA - AB))) / (BC + CA);
	bBC = (sqrt(AB * CA * (AB + BC + CA) * (AB + CA - BC))) / (AB + CA);
	bCA = (sqrt(AB * BC * (AB + BC + CA) * (AB + BC - CA))) / (AB + BC);
	
	cout << "Задание 4):" << bAB << ";" << bBC << ";" << bCA << ".\n";

	cosAB = (AB * AB + CA * CA - BC * BC) / (2 * AB * CA);
	cosBC = (AB * AB + BC * BC - CA * CA) / (2 * AB * BC);
	cosCA = (BC * BC + CA * CA - AB * AB) / (2 * BC * CA);
	acos(cosAB);//перевод в радианы путем взятия функции arccos(cosx)
	acos(cosBC);
	acos(cosCA);
	x = (acos(cosAB)) * (180 / PI);
	y = (acos(cosBC) * (180 / PI));
	z = (acos(cosCA) * (180 / PI));

	cout <<"Задание 5):"<<acos(cosAB) << ";" << acos(cosBC) << ";" << acos(cosCA) << ".\n" << x << ";" << y << ";" << z << ".\n";

	r = S1/ p;
	R = (AB * BC * CA) / 4 * S1;

	cout << "Задание 6):" << r << "." << R << ".\n";

	Sr = PI * r * r;
	SR = PI * R * R;
	Lr = 2 * PI * r;
	LR = 2 * PI * R;

	cout << "Задание 7):" << Sr << ";" << SR << "." << Lr << ";" << LR << ".\n";

	S2 = (AB * BC * CA) / 4 * R;
	S3 = p * r;
	P = AB + BC + CA;

	cout <<"Задание 8):"<< S3 << " ; " << P << ".\n";

	return 0;
}
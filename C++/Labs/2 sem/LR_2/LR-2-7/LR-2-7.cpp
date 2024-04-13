// LR-2-7   Выполнил:Тиханёнок Илья
/*Задача 7. Составить программу для решения уравнений трёх видов :
7.1 ax ^ 4 + bx ^ 2 + c = 0;
7.2 ax ^ 4 + bx ^ 3 + cx ^ 2 + bx + a = 0;
7.3 x ^ 3 + px + q = 0.*/


#include <iostream>

using namespace std;

int main()
{
    long double a, b, c, d, d1, d2, x, x1, x2, x3, x4, y, y1, y2, D1, D2, D, f, p, q, PI=3.1415926, t1, t2, t3, t4;
    int choice;
    setlocale(LC_ALL, "Rus");

    cout << "Программа может решить одно из 3-х  уравнений разных типов.\nВыберите нужное вам уравнение:\n1)ax ^ 4 + bx ^ 2 + c = 0;\n2)ax ^ 4 + bx ^ 3 + cx ^ 2 + bx + a = 0;\n3)x ^ 3 + px + q = 0.\n";
    cin >> choice;

    if (choice <= 0 || choice >= 4) {
        cout << "Ошибка!Выберите пункт от 7-1(1) до 7-3(3)!";
    }

    else {
        switch (choice) {
        case 1:
            cout << "Выбранное уравнение:ax ^ 4 + bx ^ 2 + c = 0.\nДля вычисления корней уравнения нам понадобится значение переменных(a,b,c).\nВведем a:";
            cin >> a;
            cout << "Введем b:";
            cin >> b;
            cout << "Введем c:";
            cin >> c;

            d = b * b - 4 * a * c;
            //D>0
            if (d > 0 && a != 0 && b != 0 && c != 0) {
                t1 = ((-b + sqrt(d)) / (2 * a));
                t2 = ((-b - sqrt(d)) / (2 * a));
                if (t2 <= 0) {
                    x1 = sqrt(t1);
                    x2 = -x1;
                    cout << "\n Корни уравнения равны :" << x1 << " и " << x2;
                }
                else if (t1 <= 0) {
                    x1 = sqrt(t2);
                    x2 = -x1;
                    cout << "\n Корни уравнения равны :" << x1 << " и " << x2;
                }
                else if (t1 >= 0 && t2 >= 0) {
                    x1 = sqrt(t1);
                    x2 = -x1;
                    x3 = sqrt(t2);
                    x4 = -x3;
                    cout << "\n Корни уравнения равны :" << x1 << " и " << x2 << " , " << x3 << " и " << x4;
                }

            }
            //D==0
            else if (d == 0 && a != 0 && b != 0) {
                t1 = t2 = (-b) / (2 * a);
                if (t1 < 0) {
                    cout << "Нет корней уранения.";
                }
                else if (t1 >= 0) {
                    x1 = sqrt(t1);
                    x2 = -x1;
                    cout << "\n Корни уравнения равны :" << x1 << " и " << x2;
                }
            }
            //D<0
            else if (d < 0 && a != 0 && b != 0) {
                cout << " Т.к дискриминант <0,то уравнение не имеет корней.";
            }
            //один из коэффициентов равен 0
            else if (b == 0 && c <= 0) {
                x1 = (powl((-c / a), 0.25));
                x2 = -(powl((-c / a), 0.25));
                cout << "Первый корень уравнения равен : " << x1 << "\nВторой корень уравнения равен :" << x2;
            }
            //один из коэффициентов равен 0
            else if (a == 0 && c <= 0) {
                x1 = (powl((-c / b), 0.5));
                x2 = (powl((-c / b), 0.5));
                cout << "Первый корень уравнения равен : " << x1 << "\nВторой корень уравнения равен :" << x2;
            }
            //свободный член равен 0
            else if (a != 0 && b != 0 && c == 0) {
                t1 = ((-b + sqrt(d)) / (2 * a));
                t2 = ((-b - sqrt(d)) / (2 * a));
                t3 = 0;
                x1 = sqrt(t1);
                x2 = -x1;
                x3 = 0;
                cout << "\nКорни уравнения равны :" << x1 << " и " << x2 << " и " << x3;
            }
            else {
                cout << "Нет корней уравнения.";
            }
			break;
		case 2:
			cout << "Выбранное уравнение:ax^4 + bx^3 + cx^2 + bx + a = 0.\n";
			cout << "Введите a:";
			cin >> a;
			cout << "\nВведите b:";
			cin >> b;
			cout << "\nВведите c:";
			cin >> c;

			if ((a != 0 && b != 0 && c != 0) || (a != 0 && b != 0 && c == 0))
			{
				// y = x + 1 / x;
				D = b * b - 4 * a * c + 8 * a * a;
				if (D < 0)
				{
					cout << "Действительных корней нет.\n";
				}
				else
				{
					t1 = (-b + sqrt(D)) / (2 * a);
					t2 = (-b - sqrt(D)) / (2 * a);
					d1 = t1 * t1 - 4;
					if (d1 < 0)
					{
						cout << "Действительных корней x1 и x2 нет.\n";
					}
					else
					{
						x1 = (t1 + sqrt(d1)) / 2;
						cout << "x1 = " << x1 << endl;
						x2 = (t1 - sqrt(d1)) / 2;
						cout << "x2 = " << x2 << endl;
					}
					d2 = t2 * t2 - 4;
					if (d2 < 0)
					{
						cout << "Действительных корней x3 и x4 нет.\n";
					}
					else
					{
						x3 = (t2 + sqrt(d2)) / 2;
						cout << "x3 = " << x3 << endl;
						x4 = (t2 - sqrt(d2)) / 2;
						cout << "x4 = " << x4 << endl;
					}

				}
			}
			else if (a != 0 && b == 0 && c != 0)
			{
				D = c * c - 4 * a * a;
				if (D < 0)
				{
					cout << "Действительных корней нет.\n";
				}
				else
				{
					t1 = (-c + sqrt(D)) / (2 * a);
					if (t1 < 0)
					{
						cout << "Действительных корней x1 и x2 нет.\n";
					}
					else
					{
						x1 = sqrt(t1);
						cout << "x1 = " << x1 << endl;
						x2 = -sqrt(t1);
						cout << "x2 = " << x2 << endl;
					}
					t2 = (-c - sqrt(D)) / (2 * a);
					if (t2 < 0)
					{
						cout << "Действительных корней x3 и x4 нет.\n";
					}
					else
					{
						x3 = sqrt(t2);
						cout << "x3 = " << x3 << endl;
						x4 = -sqrt(t2);
						cout << "x4 = " << x4 << endl;
					}

				}
			}
			else if (a == 0 && b != 0 && c != 0)
			{
				x1 = 0;
				cout << "x1 = " << x1 << endl;
				D = c * c - 4 * b * b;
				if (D < 0)
				{
					cout << "Других действительных корней нет.\n";
				}
				else
				{
					x2 = (-c + sqrt(D)) / (2 * b);
					cout << "x2 = " << x2 << endl;
					x3 = (-c - sqrt(D)) / (2 * b);
					cout << "x3 = " << x3 << endl;
				}
			}
			else if (a != 0 && b == 0 && c == 0)
			{
				cout << "Действительных корней нет.\n";
			}
			else if (a == 0 && b != 0 && c == 0)
			{
				cout << "x1 = 0, других действительных корней нет.\n";
			}
			else if (a == 0 && b == 0 && c != 0)
			{
				cout << "x = 0\n";
			}
			else
			{
				cout << "Уравнение не имеет корней.\n";
			}
			break;

		case 3:
			cout << "Выбранное уравнение: x^3 + px + q = 0.\n";
			cout << "Введите p:";
			cin >> p;
			cout << "\nВведите q:";
			cin >> q;

			if (p != 0 && q != 0)
			{
				t1 = -q / 2;
				t2 = p / 3;
				D = t1 * t1 + t2 * t2 * t2;
				if (D < 0)
				{
					if (q < 0)
					{
						f = atan((sqrt(-D)) / t1);
					}
					else
					{
						if (q > 0)
						{
							f = atan((sqrt(-D)) / t1) + PI;
						}
						else
						{
							f = PI / 2;
						}
					}

					x1 = 2 * sqrt(-t2) * cos(f / 3);
					x2 = 2 * sqrt(-t2) * cos((f / 3) + 2 * PI / 3);
					x3 = 2 * sqrt(-t2) * cos((f / 3) + 4 * PI / 3);

					cout << "x1 = " << x1 << ", x2 = " << x2 << ", x3 = " << x3 << endl;
				}
				else
				{
					if (D > 0)
					{
						x = cbrt(t1 + sqrt(D)) + cbrt(t1 - sqrt(D));
						cout << "x = " << x << endl;
					}
					else
					{
						x1 = 2 * cbrt(-t1);
						x2 = -cbrt(t1);
						cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
					}
				}
			}
			else if (p != 0 && q == 0)
			{
				x1 = 0;
				cout << "x1 = " << x1 << endl;
				t1 = -p;
				if (t1 < 0)
				{
					cout << "Действительных корней x2 и x3 нет.\n";
				}
				else
				{
					x2 = sqrt(t1);
					cout << "x2 = " << x2 << endl;
					x3 = -sqrt(t1);
					cout << "x3 = " << x3 << endl;
				}
			}
			else if (p == 0 && q != 0)
			{
				t1 = -q;
				x = pow(t1, 1.0 / 3);
				cout << "x = " << x << endl;
			}
			else
			{
				x = 0;
				cout << "x = " << x << endl;
			}
			break;
		}
		return 0;
	}
        
        return 0;
    }
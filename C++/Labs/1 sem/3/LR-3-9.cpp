// LR-3-9 Выполнил:Тиханёнок Илья
/*Задание 9:Вычислить значение выражения.Входные данные таковы,что результат может быть вычислен без переполнения.
Использование вещественной арифметики запрещено.*/

#include <iostream>
#include <cstdlib>//printf-scanf
#include <cmath>
#include <iomanip>//флаги и манипуляторы
#include <ctime>

using namespace std;

long double inputInt()
{
	setlocale(LC_ALL,"Rus");
	long double n;

	cout << "Введите количество членов ряда(n):";
	cin >> n;

	while (cin.peek() == ' ')//цик продолжается до тех пор пока пользователь не введет корректное значение(cin.fail если предыдущее извлечение оказалось удачным)
		cin.ignore(1, ' ');//пропускает до следующего перевода на строку
	while (cin.fail() || cin.peek() != '\n' || n <= 0 || n!= (long double) n || n!=round(n)) {
		//cin.peek - не пропускает пробелы
		cin.clear();//очищает и возвращаем cin в обычный режим
		cin.ignore(1.7e+308, '\n');//удаляем символы из входного буфера(значения предыдущего ввода)
		cout << "Некорректный ввод.Попробуйте снова.";
		cout << "\nВведите натуральное число:";
		cin >> n; 
		while (cin.peek() == ' ')
			cin.ignore(1, ' ');
	}
	return n;
}

int main()
{ 
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	int c = inputInt();
	int an;
	int sn,s=0;


	for ( int a = 1; a <= c; ++a) {
		an = rand() % 9 + 1;
		sn = (powl(2, (a-1)) * powl((-1), (a-1))) * an;
		s=s+sn;
	}
   
	cout << "\nСумма ряда чисел равна:" << s;

	return 0;
}


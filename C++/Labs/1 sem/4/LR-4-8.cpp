// LR-4-8 Выполнил:Тиханёнок Илья
/*Задача 8. Заменить нулями все элементы, которые находятся в ячейках между минимальным и максимальным элементами 
(не включая их). Изначально все элементы в массиве различные. Если после данного действия большая часть массива будет
содержать нули, то удалить все нулевые элементы из массива (c сохранением порядка следования остальных элементов).*/

#include <iostream>

//проверка на пользовательский ввод
long double inputInt()
{
	setlocale(0, "");
	long double a, b;

	std::cout << "Ввод:";
	std::cin >> a;

	while (std::cin.peek() == ' ')
		std::cin.ignore(1, ' ');
	while (std::cin.fail() || std::cin.peek() != '\n' || a <= 0 || a != (long double)a || a != round(a)) {
		//cin.peek - не пропускает пробелы
		std::cin.clear();//очищает
		std::cin.ignore(10000, '\n');
		std::cout << "Некорректный ввод.Попробуйте снова(или перезапустите программу для дальнейшей работы с ней):";
		std::cin >> a;
		while (std::cin.peek() == ' ')
			std::cin.ignore(1, ' ');
	}
	return a;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, a = 0, imin = 0, imax = 0, count = 0, count1 = 0;
	std::cout << "Введите кол-во элементов массива: ";
	std::cin >> n;
	std::cout << "\n";

	int* arr = new int[n];

	int N = n;

	/*можно выбрать рандом или нет(если рандом - мало нулей; если нет - наоборот)
	заполняем рандомными числами*/

	for (int i = 0; i < n; ++i)
	{
		arr[i] = rand() % 90 + 10;
	}

	//вводим по отдельности каждый элемент c проверкой на корректный ввод
	/*double k;
	for (int i = 0; i < n; i++) {
		std::cout << "Введите " << i + 1 << " элемент массива: ";
		k=inputInt();
		std::cout << "\n";
	}*/
	
	int min = arr[0];
	int max = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
			imin = i;
		}
		if (arr[i] > max) {
			max = arr[i];
			imax = i;
		}
	}

	if (imax > imin) {
		for (int i = imin + 1; i < imax; i++) {
			arr[i] = 0;
			a += 1;
		}
	}
	else {
		for (int i = imax + 1; i < imin; i++) {
			arr[i] = 0;
			a += 1;
		}
	}


	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << "  ";
	}

	std::cout << "\n\n";

	if (a > n / 2) {
		if (imax > imin) {
			for (int i = imax + 1; i < n; i++) {
				count += 1;
			}
			arr[imin + 1] = arr[imax];
			for (int i = imin + 2; i <= N; i++) {
				arr[i] = arr[imax + 1];
				imax++;
				N--;
			}
			for (int i = 0; i <= imin + 1; i++) {
				std::cout << arr[i] << "  ";
				count1 += 1;
			}
			for (int i = imin + 2; i <= count + count1 - 1; i++) {
				std::cout << arr[i] << "  ";
			}
		}
		else {
			for (int i = imin + 1; i < n; i++) {
				count += 1;
			}
			arr[imax + 1] = arr[imin];
			for (int i = imax + 2; i <= N + 2; i++) {
				arr[i] = arr[imin + 1];
				imin++;
				N--;
			}
			for (int i = 0; i <= imax + 1; i++) {
				std::cout << arr[i] << "  ";
			}
			for (int i = imax + 2; i <= count + 1; i++) {
				std::cout << arr[i] << "  ";
			}
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			std::cout << arr[i] << "  ";
		}
	}

	return 0;
}

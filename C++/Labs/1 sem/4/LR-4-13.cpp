// LR-4-13 Выполнил:Тиханёнок Илья
/*Задание 13: У Миши в общежитии всего лишь 1 розетка. Дабы исправить это недоразумение, Миша купил N удлинителей таких, 
что i-й удлинитель имеет a[i] входов. Вычислите, сколько розеток получится у Миши, если он оптимально соединит удлинители?*/

#include <iostream>

//проверка на пользовательский ввод
long double inputInt()
{
    setlocale(LC_ALL, "Rus");
    long double a;

    std::cout << "Enter the number of extension cable:";
    std::cin >> a;

    while (std::cin.peek() == ' ')
        std::cin.ignore(1, ' ');
    while (std::cin.fail() || std::cin.peek() != '\n' || a <= 0 || a != (long double)a || a != round(a)) {
        //cin.peek - не пропускает пробелы
        std::cin.clear();//очищает
        std::cin.ignore(10000, '\n');
        std::cout << "Please!Enter correct value:";
        std::cin >> a;
        while (std::cin.peek() == ' ')
            std::cin.ignore(1, ' ');
    }
    return a;
}

int main()
{
	int a, r = 1;
	std::cout << "Hello!\nProgramm help you to find all outlets.\n";
    a = inputInt();

	for (int i = 1; i <= a; i++)
	{
		r += i - 1;
	}

	std::cout << "The number of outlets:" << r;

	return 0;
}
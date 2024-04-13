//Выполнил:Тиханёнок Илья
/*Задание 2:Информация, обрабатываемая программой, должна храниться в  файле,результат работы занести в другой файл и
отобразить наэкране.Использовать динамический массив структур, содержащий поля согласно варианту индивидуального задания.
Программа должна содержать необходимые комментарии.Следует  предусмотреть простейший вывод на экран входных и выходных
данных.В каждом варианте задания реализовать следующие функции для  работы со структурой:инициализации данных,
добавления, удаления, корректировки и просмотра записей файла.Для получения места в общежитии формируется список
студентов, который включает Ф.И.О. студента, группу, средний балл, доход начлена семьи. Общежитие в первую очередь
предоставляется тем, у кого доход на члена семьи меньше двух минимальных зарплат, затем остальным в
порядке уменьшения среднего балла. Вывести список очередности предоставления мест в общежитии.*/


#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>

struct list {
	std::string name;
	std::string n;
	std::string average;
	std::string income;
};

void output(list* lists, int& size) {
	setlocale(0, "");
	std::cout << "\nСписок:\n\n";
	for (short i = 0; i < size; ++i)
		std::cout << lists[i].name << '\n' << lists[i].n << '\n' << lists[i].average << '\n' << lists[i].income << "\n\n";
}

void result(list* lists, int& size) {
	setlocale(0, "");
	std::cout << "\nСписок:\n\n";
	for (short i = 0; i < size; ++i)
		std::cout << lists[i].name << '\n' << lists[i].n << '\n' << lists[i].average << '\n' << lists[i].income << "\n\n";

	std::ofstream result;
	result.open("Result.txt");
	if (!result.is_open()) std::cout << "Не удалось открыть файл указанный файл";

	for (short i = 0; i < size; ++i)
		result << lists[i].name << '\n' << lists[i].n << '\n' << lists[i].average << '\n' << lists[i].income << "\n\n";

	result.close();
}

void change_element(list* lists, int& size) {
	setlocale(0, "");
	char answer;
	std::cout << "Хотите изменить какой - нибудь элемент ? (1 / 0): ";
	std::cin >> answer;

	switch (answer) {
	case '1': break;
	case '0': return;
	}

	short number, field;
	std::string input;
	std::cout << "Укажите номер элемента: ";
	std::cin >> number;
	--number;
	std::cout << "Выберите пункт для редактирования (1 - ФИО студента, 2 - группа студента, 3 - средний балл, 4 -  доход на члена семьи): ";
	std::cin >> field;

	if (field > size || field <= 0 || std::cin.fail()) {
		std::cout << "Некорректный ввод. Завершение программы.\n"; exit(1);
	}

	std::cout << "Введите значение:\t";
	std::cin >> input;

	switch (field) {
	case 1: lists[number].name = input; break;
	case 2: lists[number].n = input; break;
	case 3: lists[number].average = input; break;
	case 4: lists[number].income = input;
	}
	output(lists, size);
}

list* delete_element(list* lists, int& size) {
	setlocale(0, "");
	char answer;
	std::cout << "Хотите удалить какой-нибудь элемент? (1/0): ";
	std::cin >> answer;

	switch (answer) {
	case '1': break;
	case '0': return lists;
	}

	short number;
	std::string input;

	std::cout << "Укажите номер элемента: ";
	std::cin >> number;
	--number;

	int j = 0;
	list* newlist = new list[size - 1];
	for (int i = 0; i < size; i++) {
		if (i != number) {
			newlist[j] = lists[i];
			j++;
		}
		else
			continue;
	}
	size--;
	delete[] lists;
	output(newlist, size);

	return newlist;
}

list* Delete(list* lists, int& size) {
	const int salary = 800;
	list* newlist = new list[size];

	for (int i = 0, j = 0; i < size; i++) {
		int coast = atoi(lists[i].income.c_str());
		if (coast > salary) {
			newlist[j].name = lists[i].name;
			newlist[j].n = lists[i].n;
			newlist[j].average = lists[i].average;
			newlist[j].income = lists[i].income;
			j++;
		}
	}

	delete[] lists;

	return newlist;
}

list* sort(list* lists, int& size) {
	const int salary = 800;
	int newsize;
	list* newlist = new list[size];

	for (int i = 0, j = 0; i < size; i++) {
		int coast = atoi(lists[i].income.c_str());
		if (coast < salary) {
			newlist[j].name = lists[i].name;
			newlist[j].n = lists[i].n;
			newlist[j].average = lists[i].average;
			newlist[j].income = lists[i].income;
			newsize = j;
			j++;
		}
	}

	lists = Delete(lists, size);

	int i, j, step;
	double tmp;
	list buff;

	for (step = size / 2; step > 0; step /= 2) {
		for (i = step; i < size; i++) {
			tmp = atof(lists[i].average.c_str());
			buff = lists[i];

			for (j = i; j >= step; j -= step) {
				if (tmp > atof(lists[j - step].average.c_str()))
					lists[j] = lists[j - step];
				else
					break;
			}

			lists[j] = buff;
		}
	}


	std::cout << "size: " << size << " new size: " << newsize;


	for (int j = newsize + 1, i = 0; j < size; i++, j++) {
		newlist[j].name = lists[i].name;
		newlist[j].n = lists[i].n;
		newlist[j].average = lists[i].average;
		newlist[j].income = lists[i].income;
	}

	return newlist;
}

int main() {
	setlocale(0,"");

	int size = 4;

	std::fstream fin;
	fin.open("file", std::fstream::in | std::fstream::out | std::fstream::app);

	if (!fin.is_open()) std::cout << "Не удалось открыть файл.";

	std::string buff;
	int a;
	bool b = false;
	std::cout << "Добавить элемент в список? (1/0): ";
	std::cin >> a;
	if (a == 1) b = true;
	if (b) {
		size++;
		std::string temp;
		std::string a, b, c;

		fin << "\n";
		std::cout << "Введите ФИО студента: ";
		std::cin >> a >> b >> c;
		temp = a + " " + b + " " + c;
		temp += "\n"; fin << temp;
		std::cout << "Введите номер группы студента: ";
		std::cin >> temp;
		temp += "\n";
		fin << temp;
		std::cout << "Средний балл студента: ";
		std::cin >> temp;
		temp += "\n";
		fin << temp;
		std::cout << "Доход на члена семьи : ";
		std::cin >> temp;
		temp += "\n";
		fin << temp;
	}

	list* lists = new list[size];

	int j = 0, i = 0;

	fin.seekp(0);

	while (!fin.eof()) {
		if (i == size) break;
		buff = "";
		getline(fin, buff);
		if (buff == "") continue;
		if (j == 4) {
			j = 0;
			++i;
		}
		if (i == size) break;
		switch (j) {
		case 0: lists[i].name = buff; break;
		case 1: lists[i].n = buff; break;
		case 2: lists[i].average = buff; break;
		case 3: lists[i].income = buff; break;
		}
		++j;
	}

	output(lists, size);
	change_element(lists, size);
	lists = delete_element(lists, size);
	lists = sort(lists, size);
	result(lists, size);

	delete[] lists;

	fin.close();
}

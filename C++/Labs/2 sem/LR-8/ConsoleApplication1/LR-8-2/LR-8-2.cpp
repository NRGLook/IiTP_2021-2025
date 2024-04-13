//Выполнил:Тиханёнок Илья
/*Задание 2:Информация, обрабатываемая программой, должна храниться в  файле,результат работы занести в другой файл и 
отобразить наэкране.Использовать динамический массив структур, содержащий поля согласно варианту индивидуального задания.
Программа должна содержать необходимые комментарии.Следует  предусмотреть простейший вывод на экран входных и выходных
данных.В каждом варианте задания реализовать следующие функции для  работы со структурой:инициализации данных,
добавления, удаления, корректировки и просмотра записей файла.Для получения места в общежитии формируется список
студентов, который включает Ф.И.О. студента, группу, средний балл, доход начлена семьи. Общежитие в первую очередь
предоставляется тем, у кого доход на члена семьи меньше двух минимальных зарплат, затем остальным в
порядке уменьшения среднего балла. Вывести список очередности предоставления мест в общежитии.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Hostel {
	char NameStudent[100];
	int Group;
	float averagemarks;
	float earnings;
};

Hostel* AddStruct(Hostel* Obj, int& OldSize, int& NewSize) { // выделить память для структуры
	NewSize = OldSize + NewSize;
	if (OldSize == 0) {
		Obj = (Hostel*)calloc(NewSize, sizeof(Hostel));
	}
	else {
		Hostel* temp_Obj = (Hostel*)calloc(NewSize, sizeof(Hostel));
		for (int i = 0; i < OldSize; i++) {
			temp_Obj[i] = Obj[i];
		}
		free(Obj);
		Obj = temp_Obj;
	}
	return Obj;
}

void SetData(Hostel* Obj, int& OldSize, int NewSize) { // ввод данный в структуру
	int index;
	cout << "Выберите, как ввести данные(1 - заполнить всю память, 2 - заполнить до определённого элемента):\n";
	while (!(cin >> index)) {
		cout << "Введите корректное значение\n";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	if (index == 1) {
		for (int i = OldSize; i < NewSize; i++) {
			printf("Введите ФИО студента:\n");
			rewind(stdin);
			while (!(cin >> Obj[i].NameStudent)) {
				cout << "Введите корректное значение:\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			printf("Введите номер группы:\n");
			rewind(stdin);
			cin>>Obj[i].Group;
			printf("Введите средний балл студента:\n");
			rewind(stdin);
			cin>>Obj[i].averagemarks;
			printf("Введите доход на члена семьи:\n");
			while (!(cin >> Obj[i].earnings)) {
				cout << "Введите корректное значение:\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
		}
		OldSize = NewSize;
	}
	else if (index == 2) {
		cout << "Выберите элемент(1 - ФИО студента ,2 - номер группы, 3 - средний балл, 4 - доход на члена семьи):\n";
		int count;
		while (!(cin >> count)) {
			cout << "Введите корректное значение:\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		string value;
		cout << "Введите значение:\n";
		while (!(cin >> value)) {
			cout << "Введите корректное значение:\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		for (int i = OldSize; i < NewSize; i++) {
			printf("Введите ФИО студента:\n");
			rewind(stdin);
			while (!(cin >> Obj[i].NameStudent)) {
				cout << "Введите корректное значение\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			if (count == 1 && (Obj[i].NameStudent) == value) {
				break;
			}
			printf("Введите номер группы:\n");
			while (!(cin >> Obj[i].Group)) {
				cout << "Введите корректное значение:\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			if (count == 2 && (to_string(Obj[i].Group) == value)) {
				break;
			}
			printf("Введите средний балл:\n");
			while (!(cin >> Obj[i].averagemarks)) {
				cout << "Введите корректное значение:\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			if (count == 3 && (to_string(Obj[i].averagemarks) == value)) {
				break;
			}
			printf("Введите доход на члена семьи:\n");
			while (!(cin >> Obj[i].earnings)) {
				cout << "Введите корректное значение\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			if (count == 4  && (to_string(Obj[i].earnings) == value)) {
				break;
			}
		}
	}
}

void ShowData(Hostel* Obj, int NewSize) { // вывести структуру
	for (int i = 0; i < NewSize; i++) {
		cout << Obj[i].NameStudent << endl;
		cout << Obj[i].Group << endl;
		cout << Obj[i].averagemarks << endl;
		cout << Obj[i].earnings << endl;
		cout << "_________________\n";
	}
}
void OutputData(Hostel* Obj, int NewSize) {
	ofstream fout;
	fout.open("task2-output.txt");
	if (!fout.is_open()) {
		cout << "Ошибка открытия файла!\n";
	}
	else {
		for (int i = 0; i < NewSize; i++) {
			cout << Obj[i].NameStudent << endl;
			cout << Obj[i].Group << endl;
			cout << Obj[i].averagemarks << endl;
			cout << Obj[i].earnings << endl;
			cout << "===============\n";
		}
	}
	fout.close();
}
void InputData(Hostel* Obj, int& OldSize, int NewSize) {
	ifstream fin;
	fin.open("task2-input.txt");
	if (!fin.is_open()) {
		cout << "Ошибка открытия файла!\n";
	}
	else {
		for (int i = OldSize; i < NewSize; i++) {
			fin >> Obj[i].NameStudent;
			fin >> Obj[i].Group;
			fin >> Obj[i].averagemarks;
			fin >> Obj[i].earnings;
		}
	}
	fin.close();
}

void FindData(Hostel* Obj, int NewSize) { // поиск по элементу
	int N;
	cout << "Выберите элемент для поиска(1 - ФИО студента ,2 - номер группы, 3 - средний балл, 4 - доход на члена семьи)\n";
	while (!(cin >> N)) {
		cout << "Введите корректное значение\n";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	if (N == 1) {
		string k;
		cout << "Введите заначение\n";
		while (!(cin >> k)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		for (int i = 0; i < NewSize; i++) {
			if (Obj[i].NameStudent > k) {
				cout << Obj[i].NameStudent << endl;
				cout << Obj[i].Group << endl;
				cout << Obj[i].averagemarks << endl;
				cout << Obj[i].earnings << endl;
				cout << "===============\n";
			}
		}
	}
	else if (N == 2) {
		int k;
		cout << "Введите значение\n";
		while (!(cin >> k)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		for (int i = 0; i < NewSize; i++) {
			if (Obj[i].Group> k) {
				cout << Obj[i].NameStudent << endl;
				cout << Obj[i].Group << endl;
				cout << Obj[i].averagemarks << endl;
				cout << Obj[i].earnings << endl;
				cout << "===============\n";
			}
		}
	}
	else if (N == 3) {
		int k;
		cout << "Введите значение\n";
		while (!(cin >> k)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		for (int i = 0; i < NewSize; i++) {
			if (Obj[i].averagemarks > k) {
				cout << Obj[i].NameStudent << endl;
				cout << Obj[i].Group << endl;
				cout << Obj[i].averagemarks << endl;
				cout << Obj[i].earnings << endl;
				cout << "===============\n";
			}
		}
	}
	else if (N == 4) {
		int k;
		cout << "Введите значение\n";
		while (!(cin >> k)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		for (int i = 0; i < NewSize; i++) {
			if (Obj[i].earnings > k) {
				cout << Obj[i].NameStudent << endl;
				cout << Obj[i].Group << endl;
				cout << Obj[i].averagemarks << endl;
				cout << Obj[i].earnings << endl;
				cout << "===============\n";
			}
		}
	}
}
Hostel* DeleteStruct(Hostel* Obj, int& Size) { // удаление/изменение структуры
	int k;
	cout << "1 - удалить структуру, 2 - изменить структуру\n";
	while (!(cin >> k)) {
		cout << "Введите корректное значение\n";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	if (k == 1) {
		int m;
		ShowData(Obj, Size);
		cout << "Выберите элемент, который хотите удалить\n";
		while (!(cin >> m)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		int j = 0;
		Hostel* temp_Obj = (Hostel*)calloc(Size - 1, 3 * sizeof(string) + 3 * sizeof(int));
		for (int i = 0; i < Size; i++) {
			if (i != m - 1) {
				temp_Obj[j] = Obj[i];
				j++;
			}
			else
				continue;
		}
		Size--;
		free(Obj);
		Obj = temp_Obj;
	}
	else if (k == 2) {
		int m;
		ShowData(Obj, Size);
		cout << "Выберите элемент, который хотите изменить\n";
		while (!(cin >> m)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		m--;
		printf("Введите регистрационный номер\n");
		rewind(stdin);
		while (!(cin >> Obj[m].NameStudent)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		printf("Введите автора\n");
		while (!(cin >> Obj[m].Group)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		printf("Введите название книги\n");
		while (!(cin >> Obj[m].averagemarks)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		printf("Введите год издания\n");
		while (!(cin >> Obj[m].earnings)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
	return Obj;
}

void ShakerSort(Hostel* Obj, int size) { // сортирово4ка
	int left = 0, right = size - 1;
	bool swapped = true;
	cout << "Выберите, по какому элементу сортировать(1 - ФИО студента, 2 - группа, 3 - средний балл, 4 - доход на члена семьи)\n";
	int index;
	while (!(cin >> index) || index > 6) {
		cout << "Введите корректное значение\n";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	while ((left < right) && swapped) {
		swapped = false;
		Hostel temp;
		for (int i = left; i < right; i++)
			if (index == 1) {
				if (Obj[i].NameStudent > Obj[i + 1].NameStudent) {
					temp = Obj[i];
					Obj[i] = Obj[i + 1];
					Obj[i + 1] = temp;
					swapped = true;
				}
			}
			else if (index == 2) {
				if (Obj[i].Group > Obj[i + 1].Group) {
					temp = Obj[i];
					Obj[i] = Obj[i + 1];
					Obj[i + 1] = temp;
					swapped = true;
				}
			}
			else if (index == 3) {
				if (Obj[i].averagemarks > Obj[i + 1].averagemarks) {
					temp = Obj[i];
					Obj[i] = Obj[i + 1];
					Obj[i + 1] = temp;
					swapped = true;
				}
			}
			else if (index == 4) {
				if (Obj[i].earnings > Obj[i + 1].earnings) {
					temp = Obj[i];
					Obj[i] = Obj[i + 1];
					Obj[i + 1] = temp;
					swapped = true;
				}
			}
		right--;
		for (int i = right; i > left; i--) {
			if (index == 1) {
				if (Obj[i].NameStudent < Obj[i - 1].NameStudent) {
					temp = Obj[i];
					Obj[i] = Obj[i - 1];
					Obj[i - 1] = temp;
					swapped = true;
				}
			}
			else if (index == 2) {
				if (Obj[i].Group < Obj[i - 1].Group) {
					temp = Obj[i];
					Obj[i] = Obj[i - 1];
					Obj[i - 1] = temp;
					swapped = true;
				}
			}
			else if (index == 3) {
				if (Obj[i].averagemarks < Obj[i - 1].averagemarks) {
					temp = Obj[i];
					Obj[i] = Obj[i - 1];
					Obj[i - 1] = temp;
					swapped = true;
				}
			}
			else if (index == 4) {
				if (Obj[i].earnings < Obj[i - 1].earnings) {
					temp = Obj[i];
					Obj[i] = Obj[i - 1];
					Obj[i - 1] = temp;
					swapped = true;
				}
			}
		}
		left++;
	}
}
int main() {
	setlocale(LC_ALL, "Russian");
	Hostel* Hostels = 0;
	int OldSize = 0;
	int NewSize = 0;
	do {
		int sw;
		cout << "Выберите действие(1 - создать массив структур, 2 - просмотреть данные,3 - найти по элементу,4 - сортировка,\n5 - удалить/изменить, ";
		cout << "6 - записать в файл, 7 - записать из файла, 8 - очистить консоль, 0 - выход из программы):\n";
		while (!(cin >> sw) || sw > 8) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
		if (sw == 1) {
			printf("Введите размер массива\n");
			scanf_s("%d", &NewSize);
			Hostels = AddStruct(Hostels, OldSize, NewSize);
			SetData(Hostels, OldSize, NewSize);
			OldSize = NewSize;
		}
		else if (sw == 2) {
			ShowData(Hostels, NewSize);
		}
		else if (sw == 3) {
			if (Hostels != 0)
				FindData(Hostels, NewSize);
		}
		else if (sw == 4) {
			if (Hostels != 0)
				ShakerSort(Hostels, NewSize);
		}
		else if (sw == 5) {
			if (Hostels != 0)
				Hostels = DeleteStruct(Hostels, NewSize);
		}
		else if (sw == 8) {
			system("cls");
		}
		else if (sw == 6) {
			OutputData(Hostels, NewSize);
		}
		else if (sw == 7) {
			printf("Введите размер массива\n");
			scanf_s("%d", &NewSize);
			Hostels = AddStruct(Hostels, OldSize, NewSize);
			InputData(Hostels, OldSize, NewSize);
			OldSize = NewSize;
		}
		else if (sw == 0) {
			break;
		}
	} while (true);
	return 0;
}
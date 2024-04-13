// LR-6-5 Выполнил:Тиханёнок Илья
/*Задание 5:Во многих прикладных задачах, таких как поиск в сети или расшифровка генома, требуется совершать
некоторые действия со строками. Например, часто требуется по некоторым данным о строке восстановить ее саму. 
Вам даны две строки S1 и S2. Известно, что одна из них была суффиксом искомой строки S, а другая — ее префиксом.
Также известна длина искомой строки L, а также то, что строка S состояла только из строчных букв 
латинского алфавита. Необходимо определить число строк, удовлетворяющих этим ограничениям. Так как это число может
быть достаточно большим, то необходимо вывести его по модулю m. 
**Входные данные**
Первая строка содержит одно целое число t (1 ≤ t ≤ 100) — количество наборов входных данных, которые необходимо обработать. 
Описание каждого из наборов входных данных содержит три строки. Первая из них содержит два целых числа: L и m (1 ≤ L ≤ 109,
1 ≤ m ≤ 104). Вторая и третья строки содержат соответственно строки S1 и S2. Они непусты, состоят из строчных букв латинского
алфавита, их длины не превышают 200 символов. 
**Выходные данные**
Для каждого набора входных данных выведите в отдельной строке остаток от деления числа строк, удовлетворяющих требованиям
условия, на m.*/

#include <iostream>
#include <cmath>

using namespace std;

bool function1(char* arr1, char* arr2, int length, int difference) {
	int n = 0;
	for (int i = length - difference + 1; i <= length; i++) {
		if (arr1[i] != arr2[n]) {
			return false;
			break;
		}
		n++;
	}
	return true;
}

bool function2(char* arr1, char* arr2, int length, int difference) {
	int N = 1;
	for (int i = length - difference; i < length; i++) {
		if (arr1[i] != arr2[N]) {
			return false;
			break;
		}
		N++;
	}
	return true;
}

int main()
{

	cout << "Input the number of sets to be procceeded:\t";
	int a;
	cin >> a;
	cout << endl;
	int A = 1;
	int NUMBER;
	while (A <= a) {
		int m;
		long long int L;
		cout << "Now input L, length of the source string and m, possible ammount division module.\t";
		cin >> L >> m;
		char s1[200], s2[200];
		char* s = new char[L];
		cout << "\n Input the strings. Then we'll see the ammount of possible variaties of the source string.\n";
		cin.getline(s1, 200, ' ');
		cin.getline(s2, 200, ' ');
		int L1 = -1, L2 = 0;
		for (int i = 0; s1[i] != 0; i++) {
			L1++;
		}
		for (int i = 0; s2[i] != 0; i++) {
			L2++;
		}

		if (L1 > L || L2 > L) NUMBER = 0;
		else {
			if (L >= L1 + L2) NUMBER = 2 * pow(26, (L - (L1 + L2)));
			else if (L1 + L2 > L) {
				int difference = L1 + L2 - L;
				bool alpha = function1(s1, s2, L1, difference);
				bool betha = function2(s2, s1, L2, difference);
				if (alpha && betha) NUMBER = 2;
				else if (!(alpha || betha)) NUMBER = 0;
				else NUMBER = 1;
			}
		}

		cout << "\n\nThe ammount of possible cases according to your data is equal to:   " << NUMBER % m << "\n\n\n";
		A++;
	}

	return 0;
}

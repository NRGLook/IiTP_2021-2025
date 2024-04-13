// iteratoraccordingtosimpletoVector.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> Myvector = { 1,2,3,4 };

	vector<int> :: iterator iterator1 = Myvector.begin();

	cout << *iterator1;

//	Myvector.insert(iterator1, 23);

	for (int i = 0; i < Myvector.size(); i++)
		std::cout << Myvector[i] << std::endl;


	return 0;
}
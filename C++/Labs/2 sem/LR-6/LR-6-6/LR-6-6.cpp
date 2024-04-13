// LR-6-6 Выполнил:Тиханёнок Илья
/*Задание 6:Анаграммой слова называется любая перестановка всех букв слова. Например, из слова SOLO можно получить
12 анаграмм: SOLO, LOSO,OSLO, OLSO, OSOL, OLOS, SLOO, LSOO, OOLS, OOSL, LOOS, SOOL. 
Напишите программу, которая выводит количество различных анаграмм, которые могут получиться из этого слова. 
**Входные данные**
Слово, количество букв в котором не превышает 14. 
**Выходные данные**
Количество различных анаграмм.*/


#include <iostream>
#include <string>
#include <cstdlib>


bool lettersallowed(std::string* arr, int it) {
	std::string word = *arr;
	for (int i = 0; i < it; i++) {
		if (word.at(it) == word.at(i)) {
			return false;
			break;
		}
	}
	return true;
}

long int while_fact(int let, int* times) {
	long int p = 1;
	for (int i = 0; i < let; i++) {
		int new_str = times[i];
		p *= fact(new_str);
	}
	return p;
}

int letterscount(std::string* arr, int it, char* letters) {
	std::string word = *arr;
	int times = 0;
	for (int i = 0; i < word.size(); i++) {
		if (letters[it] == word.at(i))
			times++;
	}
	return times;
}

int fact(int justnumber) {
	if (justnumber == 1) return 1;
	else return fact(justnumber - 1) * justnumber;
}


int main() {
	std::cout << "Program can show us the number of anagrams.\nEnter your word:  ";
	std::string str;
	std::string word;
	std::string* need_word = &word;
	int anagram;
	std::getline(std::cin, str);
	int position = str.find(' ');//find space
	if (position < 14 && position > 0)
		word = str.substr(0, position);//make a copy
	else {
		position = 14;
		word = str.substr(0, position);
	}

	int left = 1;
	for (int i = 1; i < position; i++) {
		if (lettersallowed(need_word, i))
			left++;
	}
	char* letters = new char[left];//make new string 'letters'
	letters[0] = word.at(0);
	int* times = new int[left];
	int n = 1;

	for (int i = 1; i < position; i++) {
		if (lettersallowed(need_word, i) && n < left) {
			letters[n] = word.at(i);//copy to new string
			n++;
		}
		else continue;
	}
	for (int i = 0; i < left; i++) {
		times[i] = letterscount(need_word, i, letters);
	}

	anagram = fact(word.size()) / while_fact(left, times);
	std::cout  << "\nThe numbers of anagrams: " << anagram << "\n\n\n";

	return 0;
}

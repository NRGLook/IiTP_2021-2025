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


bool no_letters_allowed(std::string* arr, int it) {
	std::string word = *arr;
	for (int i = 0; i < it; i++) {
		if (word.at(it) == word.at(i)) {
			return false;
			break;
		}
	}
	return true;
}

int letters_count(std::string* arr, int it, char* letters) {
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

long int viele_fact(int let, int* times) {
	long int p = 1;
	for (int i = 0; i < let; i++) {
		int new_str = times[i];
		p *= fact(new_str);
	}
	return p;
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

	int let = 1;
	for (int i = 1; i < position; i++) {
		if (no_letters_allowed(need_word, i))
			let++;
	}
	char* letters = new char[let];//make new string 'letters'
	letters[0] = word.at(0);
	int* times = new int[let];
	int n = 1;

	for (int i = 1; i < position; i++) {
		if (no_letters_allowed(need_word, i) && n < let) {
			letters[n] = word.at(i);//copy to new string
			n++;
		}
		else continue;
	}
	for (int i = 0; i < let; i++) {
		times[i] = letters_count(need_word, i, letters);
	}

	anagram = fact(word.size()) / viele_fact(let, times);
	std::cout  << "\nThe numbers of anagrams: " << anagram << "\n\n\n";

	return 0;
}

/*#include <iostream>
#include <string>
#include <iomanip>

 int fact(int N)
{
	if (N < 0)
		return 0;
	if (N == 0)
		return 1;
	else
		return N * fact(N - 1);
}
int main() {
	int Z,X,Y,N,V;
	std::cout << "Programm can help you to find all anagrams in your word.And shows the number of anagram.";
	std::string inputword;
	int temp = 0, temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0, temp5 = 0, temp6 = 0, temp7 = 0, temp8 = 0, temp9 = 0, temp10 = 0, temp11 = 0, temp12 = 0, temp13 = 0, temp14 = 0, temp15 = 0, temp16 = 0, temp17 = 0, temp18 = 0, temp19 = 0, temp20 = 0, temp21 = 0, temp22 = 0, temp23 = 0, temp24 = 0, temp25 = 0, temp26 = 0, temp27 = 0;

	std::cin >> inputword;
	N=inputword.length();

	for (int i = 0; i < N; i++) {
		if (temp1 = inputword.find_first_of("aA")) {
			temp1 += 1;
		}
		else if (temp2 = inputword.find_first_of("bB")) {
			temp2 += 1;
		}
		else if (temp3 = inputword.find_first_of("cC")) {
			temp3 += 1;
		}
		else if (temp4 = inputword.find_first_of("dD")) {
			temp4 += 1;
		}
		else if (temp5 = inputword.find_first_of("eE")) {
			temp5 += 1;
		}
		else if (temp6 = inputword.find_first_of("fF")) {
			temp6 += 1;
		}
		else if (temp7 = inputword.find_first_of("gG")) {
			temp7 += 1;
		}
		else if (temp8 = inputword.find_first_of("hH")) {
			temp8 += 1;
		}
		else if (temp9 = inputword.find_first_of("iI")) {
			temp9 += 1;
		}
		else if (temp10 = inputword.find_first_of("jJ")) {
			temp10 += 1;
		}
		else if (temp11 = inputword.find_first_of("kK")) {
			temp11 += 1;
		}
		else if (temp12 = inputword.find_first_of("lL")) {
			temp12 += 1;
		}
		else if (temp13 = inputword.find_first_of("mM")) {
			temp13 += 1;
		}
		else if (temp14 = inputword.find_first_of("nN")) {
			temp14 += 1;
		}
		else if (temp15 = inputword.find_first_of("oO")) {
			temp15 += 1;
		}
		else if (temp16 = inputword.find_first_of("pP")) {
			temp16 += 1;
		}
		else if (temp17 = inputword.find_first_of("qQ")) {
			temp17 += 1;
		}
		else if (temp18 = inputword.find_first_of("rR")) {
			temp18 += 1;
		}
		else if (temp19 = inputword.find_first_of("sS")) {
			temp19 += 1;
		}
		else if (temp20 = inputword.find_first_of("tT")) {
			temp20 += 1;
		}
		else if (temp21 = inputword.find_first_of("uU")) {
			temp21 += 1;
		}
		else if (temp22 = inputword.find_first_of("vV")) {
			temp22 += 1;
		}
		else if (temp23 = inputword.find_first_of("wW")) {
			temp23 += 1;
		}
		else if (temp24 = inputword.find_first_of("xX")) {
			temp24 += 1;
		}
		else if (temp25 = inputword.find_first_of("yY")) {
			temp25 += 1;
		}
		else if (temp26 = inputword.find_first_of("zZ")) {
			temp26 += 1;
		}
	}

	temp = temp1 + temp2 + temp3 + temp4 + temp5 + temp6 + temp7 + temp8 + temp9 + temp10 + temp11 + temp12 + temp13 + temp14 + temp15 + temp16 + temp17 + temp18 + temp19 + temp20 + temp21 + temp22 + temp23 + temp24 + temp25 + temp26;
	std::cout << temp;

	Z = fact(N);
	X = fact(temp);
	Y = fact(temp-1);

	V = Z / (X * Y);
	std::cout << "Fact:" << V;


	return 0;
}*/

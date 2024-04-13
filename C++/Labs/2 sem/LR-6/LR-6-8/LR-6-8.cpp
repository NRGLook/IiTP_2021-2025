// LR-6-8 Выполнил:Тиханёнок Илья
/*Задание 8: У вас есть строка s и фишка, которую вы можете поставить на любой символ 
этой строки.После того, как вы поставите фишку, вы можете подвинуть ее вправо несколько (возможно, ноль) раз,
то есть сделать следующее действие несколько раз: если текущая позиция фишки обозначена как i, фишка 
перемещается в позицию i+1. Конечно же, это действие невозможно, если фишка находится в последней позиции строки.
После того, как вы закончите двигать фишку вправо, вы можете подвинуть ее влево несколько (возможно, ноль) раз,
то есть сделать следующее действие несколько раз: если текущая позиция фишки обозначена как i, фишка 
перемещается в позицию i−1. Конечно же, это действие невозможно, если фишка находится в первой позиции строки.
Когда вы ставите фишку или перемещаете ее, вы выписываете символ, на котором оказалась фишка. Например, 
если строка s — abcdef, вы ставите фишку на 3-й символ, двигаете ее вправо 2 раза, а затем двигаете ее влево 3 
раза, вы выпишете строку cdedcb.Вам даны две строки s и t. Ваше задание — определить, можно ли так 
выполнить описанные операции со строкой s, что в результате вы выпишете строку t.
**Входные данные**
В первой строке задано одно целое число q (1≤q≤500) — количество наборов входных данных.
Каждый набор входных данных состоит из двух строк. В первой строке задана строка s (1≤|s|≤500),
во второй строке — строка t (1≤|t|≤2⋅|s|−1). Обе строки состоят из строчных букв латинского алфавита.
Гарантируется, что сумма |s| по всем наборам входных данных не превосходит 500.
**Выходные данные**
Для каждого набора выходных данных выведите «YES», если можно выписать строку t, проводя описанные в условии действия 
со строкой s, или «NO» в противном случае.Каждую букву можно выводить в любом регистре (YES, yes, Yes будут 
распознаны как положительный ответ, NO, no и nO будут распознаны как 
отрицательный ответ).*/


#include <iostream>

using namespace std;

int getInput()
{
	setlocale(0, "");
	int input;

	std::cout << "Enter:";
	std::cin >> input;

	while (std::cin.peek() == ' ')
		std::cin.ignore(1, ' ');
	while (std::cin.fail() || std::cin.peek() != '\n' || input <= 0 || input != (long double)input || input != round(input)) {
		//cin.peek - не пропускает пробелы
		std::cin.clear();//очищает
		std::cin.ignore(10000, '\n');
		std::cout << "Syntaxis is invalid.Please, try again:";
		std::cin >> input;
		while (std::cin.peek() == ' ')
			std::cin.ignore(1, ' ');
	}
	return input;
}

bool possiblestrings(string str1, string str2, int index)
{
	for (; str2.length() > 0 && index >= 0 && str1[index] == str2[0]; index--)
	{
		str2 = str2.substr(1);
	}
	if (str2.length() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool possibleinput(string str1, string str2, int index)
{
	int str1Len = str1.length();
	int curIndex = index;

	for (int curIndex = index; str1[curIndex] == str2[curIndex - index] && curIndex < str1Len; curIndex++)
	{
		if (possiblestrings(str1, str2.substr(curIndex - index), curIndex))
		{
			return true;
		}
	}
	return false;
}

bool possibleoutput(string str1, string str2)
{
	int str1Len = str1.length();
	for (int i = 0; i < str1Len;i++)
	{
		if (possibleinput(str1, str2, i))
		{
			return true;
		}
	}
	return false;
}

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "The program finds whether, using a chip, going first to the right and then to the left along the line, it is possible to get a substring.\n";
	cout << "Enter the number of input data requests:n>>> ";

	int a = getInput();

	while (a != 0)
	{
		string str1, str2;

		cout << "Enter string:\n>>> ";
		cin >> str1;

		cout << "Enter the substring:\n>>> ";
		cin >> str2;

		if (possibleoutput(str1, str2))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}

		--a;
	}

	return 0;
}
// codepahsi.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

bool IsPalindrome(char* word) {
    int k = 0; while (word[k])++l; k=l;
    for (int i = 0; i < k / 2; ++i)
        if (word[i] != word[k - i - 1])
            return false;
    return true;
}
int main()
{
    char s[100];

    cout << "введите строку" << endl;
    cin.getline(s, 100);


    IsPalindrome(s);
    cout << "палиндром " << endl;

    return 0;
}


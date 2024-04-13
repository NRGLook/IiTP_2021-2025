// LR-6-4 Выполнил:Тиханёнок Илья
/*Задание 4:1 апреля 20?? года будет проведена реформа английского языка, позволяющая облегчить его освоение 
иностранцамии английскими школьниками. Во-первых, из алфавита уберут четыре буквы C, Q, W и X (на клавиатуре компьютера
вместоних будут клавиши, вызывающие программы Word, eXcel и другие). Вместо c перед буквами e, i, y нужно будет писать 
букву s, а в остальных случаях – букву k. Вместо буквы q нужно будет писать букву k, вместо сочетания qu – kv,
вместо x – ks, а вместо w – v. Во-вторых, сочетание букв ph будет записываться как f, you и oo – как u, ee – как i,
th – как z. Кроме того, все двойные согласные (включая образовавшиеся после замен), вызывающие большие трудности у
учащихся, станут одинарными, например, apple после реформы нужно писать как aple.
** Входные данные **
Во входном файле содержится текст на английском языке, без 
переносов слов. Длина строк не превышает 100 символов.
** Выходные данные **
В выходной файл вывести тот же текст, но уже соответствующий 
реформе. Если первая буква заменяемого сочетания букв была прописной, 
то первая буква замены должна быть также прописной. Вторая буква в 
заменах x→ks, qu→kv должна быть всегда строчной.*/

#include<iostream>
#include<string>
#include <fstream>
#include<conio.h>

using namespace std;

void func4(string str)
{

    int i = 100;
    while (i) {
        for (int i = 0; i < size(str); i++) {
            if (str[i] == 'c' && (str[i + 1] == 'e' || str[i + 1] == 'i' || str[i + 1] == 'y')) {
                str.replace(i, 1, "s");
            }
            if (str[i] == 'C' && ((str[i + 1] == 'e' || str[i + 1] == 'i' || str[i + 1] == 'y') || (str[i + 1] == 'E' || str[i + 1] == 'I' || str[i + 1] == 'Y'))) {
                str.replace(i, 1, "S");
            }
            if (str[i] == 'c' && (str[i + 1] != 'e' || str[i + 1] != 'i' || str[i + 1] != 'y')) {
                str.replace(i, 1, "k");
            }
            if (str[i] == 'C' && ((str[i + 1] != 'e' || str[i + 1] != 'i' || str[i + 1] != 'y') || (str[i + 1] != 'E' || str[i + 1] != 'I' || str[i + 1] != 'Y'))) {
                str.replace(i, 1, "K");
            }
            if (str[i] == 'q' && str[i + 1] == 'u') {
                str.replace(i, 2, "kv");
            }
            if (str[i] == 'Q' && ((str[i + 1] == 'u') || (str[i + 1] == 'U'))) {
                str.replace(i, 2, "Kv");
            }
            if (str[i] == 'q') {
                str.replace(i, 1, "k");
            }
            if (str[i] == 'Q') {
                str.replace(i, 1, "K");
            }
            if (str[i] == 'x') {
                str.replace(i, 1, "ks");
            }
            if (str[i] == 'X') {
                str.replace(i, 1, "Ks");
            }
            if (str[i] == 'w') {
                str.replace(i, 1, "v");
            }
            if (str[i] == 'W') {
                str.replace(i, 1, "V");
            }
            if (str[i] == 'p' && str[i + 1] == 'h') {
                str.replace(i, 2, "f");
            }
            if (str[i] == 'P' && ((str[i + 1] == 'h') || (str[i + 1] == 'H'))) {
                str.replace(i, 2, "F");
            }
            if (str[i] == 'y' && str[i + 1] == 'o' && str[i + 2] == 'u') {
                str.replace(i, 3, "u");
            }
            if (str[i] == 'Y' && (str[i + 1] == 'o' || str[i + 1] == 'O') && (str[i + 2] == 'u' || str[i + 2] == 'U')) {
                str.replace(i, 3, "U");
            }
            if (str[i] == 'o' && str[i + 1] == 'o') {
                str.replace(i, 2, "u");
            }
            if (str[i] == 'O' && (str[i + 1] == 'o' || str[i + 1] == 'O')) {
                str.replace(i, 2, "U");
            }
            if (str[i] == 'e' && str[i + 1] == 'e') {
                str.replace(i, 2, "i");
            }
            if (str[i] == 'E' && (str[i + 1] == 'e' || str[i + 1] == 'E')) {
                str.replace(i, 2, "I");
            }
            if (str[i] == 't' && str[i + 1] == 'h') {
                str.replace(i, 2, "z");
            }
            if (str[i] == 'T' && (str[i + 1] == 'h' || str[i + 1] == 'H')) {
                str.replace(i, 2, "Z");
            }
            if (str[i] == str[i + 1]) {
                str.replace(i + 1, 1, "");
            }
        }
        i--;
    }
    cout << str;
}

int main() {
    setlocale(0, "");
    string s[100], m;
    const int MAXLEN_STR = 256;
    const char* PATH = "D:\\C++\\Важные работы\\LR-6\\LR-6-4\\1.txt";
    const char* PATH1 = "D:\\C++\\Важные работы\\LR-6\\LR-6-4\\2.txt";
    char* S;
    int count = 0;
    cout << "input string count: ";
    (cin >> count).ignore();
    S = new char[MAXLEN_STR];
    ofstream out(PATH);
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". ";
        cin.getline(S, MAXLEN_STR);

        out << S << endl;
    }
    out.close();
    cout << endl;

    char ch = 0;
    ifstream in(PATH);
    char S2[MAXLEN_STR];
    int i = 0;
    while ((ch = in.get()) != EOF) {
        s[i] = ch;
        i++;
    }

    in.close();

        for (int i = 0; i < 100; i++) {
            m += s[i];
        }
    cout << m;
    ofstream out1(PATH1);
    for (int i = 0; i < count; i++) {

        out1 << m << endl;
    }
    out.close();
    func4(m);


    return 0;
}
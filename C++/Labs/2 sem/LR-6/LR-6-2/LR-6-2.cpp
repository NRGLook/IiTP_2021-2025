// LR-6-2 Выполнил:Тиханёнок Илья
/*Задание 2:Рассматривать строки как указатель типа чар. В тексте нет слов, начинающихся одинаковыми буквами. 
Напечатать слова текста в таком порядке, чтобы последняя буква каждого слова совпадала с первой буквой последующего
слова. Если все слова нельзя напечатать в таком порядке, найти такую цепочку, состоящую из наибольшего количества 
слов.*/
 
#include <iostream>
#include <cstring>

char* strIn() {
    char* str = new char[1];
    int len = 0;

    std::cout << "Enter line: ";

    while (std::cin.peek() != '\n') {
        *(str + len) = std::getchar();

        ++len;

        str = (char*)realloc(str, (len + 1) * sizeof(char));//changing the size of the allocated memory
    }

    *(str + len) = '\0';//adding zero

    return str;
}

char* f(char* str) {
    char* newStr = new char[strlen(str)];//changing the size of the allocated memory
    int k = 0;

    char* first = new char[26];//create array
    char* last = new char[26];

    int pos1[26], pos2[26];

    bool kStr[26];
    for (int i = 0; i < 26; ++i) {
        kStr[i] = false;
    }

    bool lst = true, lstWrd;

    int count = 0, position = 0, usage;

    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] == ' ') {
            *(last + count) = *(str + i - 1);//work with pointers
            *(first + count + 1) = *(str + i + 1);

            pos1[count + 1] = i + 1;
            pos2[count] = i - 1;

            ++count;
        }
        else if (i == strlen(str) - 1) {
            *(last + count) = *(str + i);
        }
        else if (i == 0) {
            *(first + count) = *(str + i);
        }
    }

    pos1[0] = 0;
    pos2[count] = strlen(str) - 1;

    ++count;

    usage = count - 1;

    for (int i = 0; i < count; ++i) {
        kStr[i] = true;

        for (int j = 0; j < count; ++j) {
            if (i != j && *(first + i) == *(last + j)) {//we add a pointer everywhere since this is the main aim of the task
                kStr[i] = false;

                break;
            }
        }

        if (kStr[i]) {
            for (int j = pos1[i]; j < pos2[i] + 1; ++j) {
                *(newStr + k) = *(str + j);
                ++k;
            }

            *(newStr + k) = ' ';
            ++k;

            position = i;

            break;
        }
    }

    for (int i = 0; i < count; ++i) {
        if (kStr[i]) lst = false;
    }

    if (lst) {
        for (int i = pos1[0]; i < pos2[0] + 1; ++i) {
            *(newStr + k) = *(str + i);
            ++k;
        }

        *(newStr + k) = ' ';
        ++k;
    }

    while (usage) {
        lst = true;

        for (int i = 0; i < count; ++i) {
            if (kStr[i] == true || i == position) continue;

            if (*(last + position) == *(first + i)) {

                kStr[i] = true;
                position = i;
                --usage;
                lst = false;

                for (int j = pos1[i]; j < pos2[i] + 1; ++j) {
                    *(newStr + k) = *(str + j);
                    ++k;
                }

                *(newStr + k) = ' ';
                ++k;
            }
        }

        if (lst) {
            for (int i = 0; i < count; ++i) {
                lstWrd = false;

                if (kStr[i] == false) {
                    for (int j = 0; j < count; ++j) {
                        if (i != j && *(first + i) == *(last + j)) {
                            lstWrd = true;

                            break;
                        }
                    }

                    if (lstWrd) continue;

                    lst = false;
                    kStr[i] = true;
                    position = i;
                    --usage;

                    for (int j = pos1[i]; j < pos2[i] + 1; ++j) {
                        *(newStr + k) = *(str + j);
                        ++k;
                    }

                    *(newStr + k) = ' ';
                    ++k;
                }
            }
        }

        if (lst) {
            for (int i = 0; i < count; ++i) {
                if (kStr[i] == false) {
                    kStr[i] = true;
                    position = i;
                    --usage;

                    for (int j = pos1[i]; j < pos2[i] + 1; ++j) {
                        *(newStr + k) = *(str + j);
                        ++k;
                    }

                    *(newStr + k) = ' ';
                    ++k;
                }
            }
        }
    }

    *(newStr + k - 1) = '\0';

    return newStr;
}

int main() {
    char* str = strIn();
    std::cout << "\n New line: " << f(str);//output new line
}
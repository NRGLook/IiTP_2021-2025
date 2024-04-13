// LR-8-3.cpp Выполнил:Тиханёнок Илья
/*Задание 3:                          /* Реализовать любой из 30 вариантов (кроме уже реализованных вами)
заданий используя классы. Реализовать корректировку записей внутри файла без
полной перезаписи файла. Все методы класса должны иметь модификатор public,
а остальные поля – private;*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class PhoneInfo {
public:
    void showStruct() {
        cout << "Дата: " << data << endl;
        cout << "Код: " << kod << endl;
        cout << "Город: " << city << endl;
        cout << "Врмея разговора: " << talkTime << endl;
        cout << "Тариф: " << tariff << endl;
        cout << "Номер города: " << cityNum << endl;
        cout << "Номер Абонента: " << subNum << endl;
    }
    void changeStruct() {
        printf("Введите дату\n");
        cin >> data;
        printf("Введите код\n");
        rewind(stdin);
        cin >> kod;
        printf("Введите название города\n");
        rewind(stdin);
        cin >> city;
        printf("Введите время разговора\n");
        rewind(stdin);
        cin >> talkTime;
        printf("Введите тариф\n");
        rewind(stdin);
        cin >> tariff;
        printf("Введите номер города\n");
        rewind(stdin);
        cin >> cityNum;
        printf("Введите номер абонента\n");
        rewind(stdin);
        cin >> subNum;
    }
    void InputData(int& n) {
        ifstream fin;
        fin.open("task3-input.txt");
        fin.seekg(n);
        if (!fin.is_open()) {
            cout << "Ошибка открытия файла!\n";
        }
        else {
            fin >> data;
            fin >> kod;
            fin >> city;
            fin >> talkTime;
            fin >> tariff;
            fin >> cityNum;
            fin >> subNum;
        }
        n = fin.tellg();
        fin.close();
    }
    void OutputData() {
        ofstream fout;
        fout.open("task3-output.txt", ifstream::app);
        if (!fout.is_open()) {
            cout << "Ошибка открытия файла!\n";
        }
        else {
            fout << data << endl;
            fout << kod << endl;
            fout << city << endl;
            fout << talkTime << endl;
            fout << tariff << endl;
            fout << cityNum << endl;
            fout << subNum << endl;
        }
        fout.close();
    }
private:
    char data[15];
    int kod;
    char city[20];
    long talkTime;
    int tariff;
    char cityNum[20];
    char subNum[20];

};
PhoneInfo* delStruct(PhoneInfo* Obj, int& Size) {
    int m;
    cout << "Выберите элемент,который хотите удалить:\n";
    while (!(cin >> m)) {
        cout << "Введите корректное значение:\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    int j = 0;
    PhoneInfo* temp_Obj = (PhoneInfo*)calloc(Size - 1, sizeof(PhoneInfo));
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
    return Obj;
}
PhoneInfo* addStruct(PhoneInfo* Obj, int& OldSize, int& NewSize) {
    NewSize = OldSize + NewSize;
    if (OldSize == 0) {
        Obj = (PhoneInfo*)calloc(NewSize, sizeof(PhoneInfo));
    }
    else {
        PhoneInfo* temp_Obj = (PhoneInfo*)calloc(NewSize, sizeof(PhoneInfo));
        for (int i = 0; i < OldSize; i++) {
            temp_Obj[i] = Obj[i];
        }
        free(Obj);
        Obj = temp_Obj;
    }
    return Obj;
}
int main() {
    setlocale(LC_ALL, "ru");
    PhoneInfo* data = 0;
    int oldSize = 0;
    int newSize = 0;
    ofstream output;
    ifstream input;
    do {
        int action;
        cout << "Выберите действие:\n 1 - создать структуру\n 2 - изменить структуру\n 3 - записать в файл\n 4 - записать из файла \n 5 - удалить\n 6 - показать структуру\n 0 - выход\n";
        while (!(cin >> action) || action > 6) {
            cout << "Введите корректное значение:\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        if (action == 1) { // добавляет структуру
            printf("Введите размер:\n");
            scanf_s("%d", &newSize);
            data = addStruct(data, oldSize, newSize);
            for (int i = oldSize; i < newSize; i++)
                data[i].changeStruct();
            oldSize = newSize;
        }
        else if (action == 2) { // изменяет структуру
            int ind;
            printf("Введите номер структуры, которую хотите изменить");
            scanf_s("%d", &ind);
            ind--;
            data[ind].changeStruct();
        }
        else if (action == 3) { // записать в файл
            for (int i = 0; i < newSize; i++) {
                data[i].OutputData();
            }
        }
        else if (action == 4) { // записать из файла
            printf("Введите размер:\n");
            scanf_s("%d", &newSize);
            int n = 0;
            data = addStruct(data, oldSize, newSize);
            for (int i = 0; i < newSize; i++) {
                data[i].InputData(n);
            }
            oldSize = newSize;
        }
        else if (action == 5) { // удалить структуру
            if (data != 0)

                data = delStruct(data, newSize);
        }
        else if (action == 6) {
            for (int i = 0; i < newSize; i++) {
                data[i].showStruct();
            }
        }
        else if (action == 0) {
            break;
        }
    } while (true);
    return 0;
}
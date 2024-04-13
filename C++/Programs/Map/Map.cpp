#include <iostream>
#include <map>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    pair<int, string> ourpair(1, "telephone");


    map<int, string> MyMap;

    

    MyMap.insert(make_pair(1, "telephone"));
    MyMap.insert(pair<int, string>(2, "laptop"));//либо копирует либо перемещает()

    MyMap.emplace(3, "aaaa");//создает во время добавления

    MyMap[123] = "Вася"; // создаться новый элемент
    MyMap[123] = "Петя"; // новый не добавился - ключ тот же - просто заменилось значение хранящаеся под тем ключом

    MyMap.at(123) = "Петька";// все ок - заменилось
    MyMap.at(999) = "Арбузик";//исключение так как такого ключа нет 

    cout << MyMap[123];


    cout << ourpair.second;

    cout << MyMap[2];





    return 0;
}

/*#include <iostream>
#include <map>

using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    map <int, int>  street; // создали журнал
    int n;

    cout << "Введите количество домов на улице: "; cin >> n;      // считываем количество 
    cout << "Укажите дом и сколько в нем живет людей: " << endl;  // домов 

    for (int i = 0; i < n; i++) {
        int house, people;
        cout << i << ") Дом ";
        cin >> house; cin >> people;  // считываем введенные значения
        street.insert(make_pair(house, people));
    }

    int q;
    cout << endl << "Введите количество операций: ";
    cin >> q;

    for (int i = 0; i < q; i++) {
        cout << i << ") ";
        int a; cin >> a;

        if (a == 0) { // начала первой операция
            int house;
            cout << "Укажите номер дома: "; cin >> house;
            if (street.count(house)) {
                cout << "Количество людей: " <<
                    street[house] << endl;
            }
            else {
                cout << "Такого дома не существует! " << endl;
            }
        }
        if (a == 1) { // начала второй операции
            int deleter;
            cout << "Какой дом удалить: ";  cin >> deleter;
            if (street.find(deleter) == street.end()) {
                cout << "Его нет в списке, возможно уже разрушен :)";
            }
            else {
                street.erase(street.find(deleter));
                cout << "Элемент удален! " << endl;
            }
        }

        if (a == 2) { // начала третьей операции
            int house, people;
            cout << "Какой дом добавить: "; cin >> house;
            cout << "Какое количество людей там проживает: "; cin >> people;
            street[house] = people;
        }
    }

    return 0;
}

*/
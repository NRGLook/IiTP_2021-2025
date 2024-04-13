#include <iostream>
#include <list>

using namespace std;

template <typename T> 
void PrintList(const list<T> &list1) {



    for (auto i = list1.cbegin(); i != list1.cend(); ++i)
        cout  << *i << endl;
}

int main()
{

    setlocale(LC_ALL, "Rus");

    list<int> Mylist;

    Mylist.push_back(12);
    Mylist.push_front(21);
    Mylist.push_front(123);
    Mylist.push_front(999);

    Mylist.sort();
    
    PrintList(Mylist);

    auto Myiterator = Mylist.begin();
    ++Myiterator;
    Mylist.insert(Myiterator, 123);

    cout << "After insert:";
    PrintList(Mylist);

    Mylist.sort();
    cout << "After sorting:";
    PrintList(Mylist);

    advance(Myiterator, 3);//сдвигает итератор на 5 элементов так как тот не перегружен
    cout << "After сдвиг:";
    PrintList(Mylist);

}


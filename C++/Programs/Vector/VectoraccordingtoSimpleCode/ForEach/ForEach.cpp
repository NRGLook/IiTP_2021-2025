
#include <iostream>

using namespace std;

int main()
{
    double math[] = { 0, 1, 4, 5, 7, 8, 10, 12, 15, 17, 30, 41 };

    /*for (int number : math) // итерация по массиву math - number - не индекс массива ей просто присваивается значение из массива
        std::cout << number << ' ';// получаем доступ к элементу массива в этой итерации через переменную number
    */ 

    for(auto var:math)
    {
        cout << var << endl;
    }
    // если передать var по ссылке &var то станет все тем чем захотели (присвоили в цикле -1 станут все элементы -1)


    return 0;
}



// ReadyForEx.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
/*#include <iostream>

using namespace std;

int main() {
    bool exit = false;
    int i, j = 10, sum;

    for (i = 0, sum = 0; i < 5 && !exit; i++, j--) {
        sum += i * j;

        if (sum > 10)
            exit = true;
    }

    cout << sum << endl;

    return 0;
}*/
#include <iostream>

using namespace std;


/*int main() {
    // 1 1 2 3 5 8 13 21 ...
    const unsigned long limit = 4294967295;
    unsigned long next = 0, last = 1;

    while (next < limit / 2) {
        cout << last << " ";
        unsigned long sum = next + last;
        next = last;
        last = sum;
    }
    for (;;) {

    }

}*/
/*int main(int argc, char** argv) {
    int x = 0, y = 0;

    if (x++ && y++)
        y += 2;

    std::cout << x + y << std::endl;//2
    return 0;
}*/
int main() {
    int a = 10; // Lost and unknown

    int* ptr = &a;

    cout << "Variable value: " << *ptr << endl;

    return 0;
}










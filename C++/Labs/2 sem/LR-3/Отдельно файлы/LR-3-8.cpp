#include<iostream>
int main()
{
    long long number, a, b, c, d;
    std::cin >> number;

    a = number / 1000;
    b = (number / 100) % 10;
    c = (number / 10) % 10;
    d = number % 10;
    if ((number >= 1000 && number <= 9999) && a == 2 && b == 0 && c == 1 && d == 2) {
        std::cout << "Yes";
    }
    else if ((number >= 1000 && number <= 9999) && a == 2 && b == 1 && c == 0 && d == 2) {
        std::cout << "Yes";
    }
    else if ((number >= 1000 && number <= 9999) && a == 2 && b == 2 && c == 1 && d == 0) {
        std::cout << "Yes";
    }
    else if ((number >= 1000 && number <= 9999) && a == 2 && b == 2 && c == 0 && d == 1) {
        std::cout << "Yes";
    }
    else if ((number >= 1000 && number <= 9999) && a == 2 && b == 0 && c == 2 && d == 1) {
        std::cout << "Yes";
    }
    else if ((number >= 1000 && number <= 9999) && a == 2 && b == 1 && c == 2 && d == 0) {
        std::cout << "Yes";
    }
    else if ((number >= 1000 && number <= 9999) && a == 1 && b == 0 && c == 2 && d == 2) {
        std::cout << "Yes";
    }
    else if ((number >= 1000 && number <= 9999) && a == 1 && b == 2 && c == 0 && d == 2) {
        std::cout << "Yes";
    }
    else if ((number >= 1000 && number <= 9999) && a == 1 && b == 2 && c == 2 && d == 0) {
        std::cout << "Yes";
    }
    else {
        std::cout << "No";
    }

    return 0;
}
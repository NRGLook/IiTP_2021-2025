#include "pch.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool negative;

void system3(int a, string& Digit) {
    if (a / 3)
        system3(a / 3, Digit);
    string temp = to_string(a % 3);
    Digit.push_back(temp[0]);
}
string newSystem3(string digit3, string& Digit, int i) {
    string temp3; temp3[0] = digit3[i];
    short a;
    if (atoi(temp3.c_str()) < 1) {
        string temp = to_string(atoi(temp3.c_str()) + 3);
        Digit[i] = temp[0];
        if (i == 0) {
            string newDigit;
            newDigit.resize(Digit.length() + 1);
            newDigit[0] = '2';
            for (short j = 0, k = 1; j < Digit.length(); ++j, ++k) newDigit[k] = Digit[j];
            return newDigit;
        }
        temp[0] = digit3[i - 1];
        a = atoi(temp.c_str()) - 1;
        if (a >= 0) {
            temp.erase(0, 1);
            string y = to_string(a);
            temp.push_back(y[0]);
            digit3[i - 1] = temp[0];
        }
        else {
            bool zero = 0;
            a += 3;
            temp.erase(0, 1);
            string y = to_string(a);
            temp.push_back(y[0]);
            if (digit3[i - 1] == '0') zero = 1;
            digit3[i - 1] = temp[0];
            if (zero) {
                temp[0] = digit3[i - 2];
                a = atoi(temp.c_str()) - 1;
                temp = to_string(a);
                digit3[i - 2] = temp[0];
            }
        }
    }
    else Digit[i] = digit3[i];
    if (i - 1 == 0 && digit3[i - 1] == '0') {
        if (negative)
            putchar('-');
        Digit.erase(0, 1);
        return Digit;
    }
    if (i == 0) {
        if (negative)
            putchar('-');
        return Digit;
    }
    return newSystem3(digit3, Digit, --i);
}

//////////
/////////

std::string arabicToRoman(int n) {

    std::string rom_str[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

    std::string result = "";

    for (int i = 0; i < 13; ++i)
    {
        while (n - values[i] >= 0)
        {
            result += rom_str[i];
            n -= values[i];
        }
    }
    return result;
}

//////////
/////////

std::string reverseCode(std::string straight_code) {
    std::string reverse_code;
    int str_size = 0;
    for (int i = 0; straight_code[i] != '\0'; i++)
        str_size++;
    for (int i = 0; i < str_size; i++)
    {
        if (i == 0)
            reverse_code += straight_code[0];
        if (straight_code[0] == '0' && i > 0)
            reverse_code += straight_code[i];
        else
            if (i > 0 && straight_code[i] == '0')
                reverse_code += '1';
            else if (i > 0 && straight_code[i] == '1')
                reverse_code += '0';
    }
    return reverse_code;
}

//////////
/////////

int convert(char a) {
    if (a == '0') return 0;
    if (a == '1') return 1;
    if (a == '2') return 2;
    if (a == '3') return 3;
    if (a == '4') return 4;
    if (a == '5') return 5;
    if (a == '6') return 6;
    if (a == '7') return 7;
    if (a == '8') return 8;
    if (a == '9') return 9;
    if (a == 'A') return 10;
    if (a == 'B') return 11;
    if (a == 'C') return 12;
    if (a == 'D') return 13;
}
int convert_to_10() {
    char num;
    std::cin >> num;
    int size = std::cin.rdbuf()->in_avail();
    int number = convert(num);

    if (size != 1) {
        return number * pow(14, size - 1) + convert_to_10();
    }
    else {
        return number * pow(14, size - 1);
    }
}
void convert_to_3(int ten) {
    int number, integer, mod;
    integer = ten / 3;
    number = integer * 3;
    mod = ten - number;

    if (integer == 0) {
        std::cout << mod;
        return;
    }

    convert_to_3(ten /= 3);

    std::cout << mod;
}

/*string system12(long long num, int size) {
    int num1 = 0;
    for (int i = 0; i < size; i++)
    {
        num1 += (num % 10) * pow(7, i);
        num /= 10;
    }
    int rem;
    char* str = new char[size];
    for (int i = size - 1; i > 0; i--)
    {
        rem = num1 % 12;
        num1 = (num1 - rem) / 12;
        if (rem == 10)
            str[i] = 'a';
        else {
            str[i] = (char)(rem + 48);
        }
    }
    if (num1 == 10)
        str[0] = 'a';
    else if (num1 == 0)
        str[0] = ' ';
    else {
        str[0] = (char)(num1 + 48);
    }
    for (int i = 0; i < size; i++) {
        if (str[i] == ';')
            str[i] = 'b';
        if (str[1] == '0')
            str[1] = ' ';
    }
    return str;
}*/

///////////
//////////
char getnum(short n)
{
    const char* const a = "0123456789ABCDEFG\0";

    for (short i = 0; a[i] != '\0'; ++i) {
        if (i == n) {
            return a[i];
        }
    }
}

string convert(int n)
{
    string out;
    while (n > 0)
    {
        out = getnum(n % 17) + out;
        n /= 17;
    }

    return out;
}

string convert1(int n)
{
    string out1;
    while (n > 0)
    {
        out1 = getnum(n % 17) + out1;
        n /= 17;
    }

    return out1;
}

string func1(int number) {
    int number1 = 0, number2 = 0, count = 1, num = 0;
    string s;
    int result = 0, result1 = 0;
    number1 = number;
    number2 = number;
    while ((number1 /= 10) > 0)
    {
        count++;
    }
    char* p;
    p = new char[count];
    for (int i = count - 1; i >= 0; i--) {
        p[i] = number2 % 10 + 48;
        number2 /= 10;
    }

    num = atoi(p);
    for (int i = 0; number != 0; i++)
    {
        result += (number % 10) * pow(3, i);
        number /= 10;
    }
    for (int i = 0; num != 0; i++)
    {
        result1 += (num % 10) * pow(3, i);
        num /= 10;
    }
    //cout « "Перевод в семнадцатеричную систему 1 вариантом: " « convert(result) « "\n";
    s = convert(result);
    return s;

}

std::string reverse(std::string str, int size) {
    if (size == -1)
        return "";
    else
    {
        char a;
        a = str[size];
        return a + reverse(str, size - 1);
    }
}

std::string additionalCode(std::string str) {
    std::string additional_code;
    int a = 0;
    for (int i = 0; i < 8; i++) {
        if (str[0] == '-') {
            a = 8;
        }
        if (i == 0 && a == 8)
        {
            additional_code += '1';
        }
        if (a == 8 && i > 0) {
            if (str[i] == '1') additional_code += '0';
            if (str[i] == '0') additional_code += '1';
        }
        else if (!a) {
            if (str[i] == '0')
                additional_code += '0';
            else if (str[i] == '1')
                additional_code += '1';
        }
    }
    int size = 0;
    for (int i = 0; additional_code[i] != '\0'; i++)
        size++;
    additional_code = reverse(additional_code, size);
    for (int i = 0; i < 8; i++) {
        if (a == 8 && i > size - 1) {
            additional_code += '1';
        }
        if (!a && i > size - 1)
            additional_code += '0';
    }
    additional_code = reverse(additional_code, 8);
    for (int i = 7; i >= 0; i--) {
        if (a == 8) {
            if (additional_code[i] == '0') {
                additional_code[i] = '1';
                break;
            }
            if (additional_code[i] == '1')
                additional_code[i] = '0';
        }
    }
    return additional_code;
}

std::string sumInAddCode(std::string str1, std::string str2) {
    std::string  add_sum;
    for (int i = 7; i >= 0; i--) {
        if (str1[i] != str2[i]) {
            add_sum += '1';
        }
        else if (str1[i] == str2[i] && str1[i] == '0') {
            add_sum += '0';
        }
        else if (str1[i] == str2[i] && str1[i] == '1') {
            if (str1[i + 1] != str2[i + 1] && (str1[i + 1] == '1' || str1[i + 1] == '0')) {
                add_sum += '0';
                if (str1[i - 1] != '1') str1[i - 1] = '1';
                else if (str1[i - 1] == '1') str2[i - 1] = '1';
            }
            else {
                add_sum += "011";
                i -= 2;
            }

        }
    }
    for (int i = 0; i < 8; i++) {
        if (add_sum[i] == ' ')
            add_sum.erase(i, 1);
    }
    add_sum = reverse(add_sum, 8);
    return add_sum;
}

//////////
/////////

int subtr(int x, int y) {
    while (y) {
        int borrow = (~x) & y;
        x = x ^ y;
        y = borrow << 1;
    }
    return x;
}
int inc(int i) {
    int mask = 1;
    while (i & mask) {
        i &= ~mask;
        mask <<= 1;
    }
    i |= mask;
    return i;
}
int diV(int n, int d) {
    int q = 0;
    while (n >= d) {
        int i = 0, temp_d = d;
        while (n >= (temp_d << 1)) {
            i = inc(i);
            temp_d <<= 1;
        }
        q |= 1 << i;
        n = subtr(n, temp_d);
    }
    return q;
}
int add(int x, int y) {
    while (y) {
        int carry = x & y;
        x = x ^ y;
        y = carry << 1;
    }
    return x;
}
int mult(int a, int b) {
    int result = 0;
    while (b) {
        if (b & 01) result = add(result, a);
        a <<= 1; b >>= 1;
    }
    return result;
}
int mod(int a, int b) {
    int r = diV(a, b);
    return subtr(a, mult(r, b));
}

/////////
////////

long long S(long long n) {
    if (n == 0)
        return 0;
    return (n % 10) + S(n / 10);
}

long long interesting(long long num) {
    S(num);
    return (num + 1) / 10;
}

TEST(task1, test1) {
    EXPECT_EQ("B", convert(11));
    EXPECT_TRUE(true);
}
TEST(task1, test2) {
    EXPECT_EQ("5F", convert(100));
    EXPECT_TRUE(true);
}
TEST(task1, test3) {
    EXPECT_EQ("2B2", convert(767));
    EXPECT_TRUE(true);
}
TEST(task1, test4) {
    EXPECT_EQ("", convert(0));
    EXPECT_TRUE(true);
}
TEST(task1, test5) {
    EXPECT_EQ("F67", convert(4444));
    EXPECT_TRUE(true);
}
TEST(task1, test6) {
    EXPECT_EQ("20A4", convert(10000));
    EXPECT_TRUE(true);
}

TEST(task1, test7) {
    EXPECT_EQ("4", func1(11));
    EXPECT_TRUE(true);
}
TEST(task1, test8) {
    EXPECT_EQ("9", func1(100));
    EXPECT_TRUE(true);
}
TEST(task1, test9) {
    EXPECT_EQ("53", func1(767));
    EXPECT_TRUE(true);
}
TEST(task1, test10) {
    EXPECT_EQ("", func1(0));
    EXPECT_TRUE(true);
}
TEST(task1, test11) {
    EXPECT_EQ("97", func1(4444));
    EXPECT_TRUE(true);
}
TEST(task1, test12) {
    EXPECT_EQ("4D", func1(10000));
    EXPECT_TRUE(true);
}

TEST(task9, test1) {
    int digit = 6;
    string Digit;
    system3(digit, Digit);
    string digit3 = Digit;
    EXPECT_EQ("13", newSystem3(digit3, Digit, Digit.length() - 1));
    EXPECT_TRUE(true);
}

TEST(task9, test2) {
    int digit = 7;
    string Digit;
    system3(digit, Digit);
    string digit3 = Digit;
    EXPECT_EQ("21", newSystem3(digit3, Digit, Digit.length() - 1));
    EXPECT_TRUE(true);
}

TEST(task9, test3) {
    int digit = 22;
    string Digit;
    system3(digit, Digit);
    string digit3 = Digit;
    EXPECT_EQ("211", newSystem3(digit3, Digit, Digit.length() - 1));
    EXPECT_TRUE(true);
}

TEST(task9, test4) {
    int digit = 2000000000;
    string Digit;
    system3(digit, Digit);
    string digit3 = Digit;
    EXPECT_EQ("11233323323111313232", newSystem3(digit3, Digit, Digit.length() - 1));
    EXPECT_TRUE(true);
}
TEST(task9, test5) {
    int digit = 9651;
    string Digit;
    system3(digit, Digit);
    string digit3 = Digit;
    EXPECT_EQ("33312333", newSystem3(digit3, Digit, Digit.length() - 1));
    EXPECT_TRUE(true);
}

TEST(task9, test6) {
    int digit = 1;
    string Digit;
    system3(digit, Digit);
    string digit3 = Digit;
    EXPECT_EQ("1", newSystem3(digit3, Digit, Digit.length() - 1));
    EXPECT_TRUE(true);
}

TEST(task5, test1) {
    EXPECT_EQ("X", arabicToRoman(10));
    EXPECT_TRUE(true);
}

TEST(task5, test2) {
    EXPECT_EQ("CMXCIX", arabicToRoman(999));
    EXPECT_TRUE(true);
}

TEST(task5, test3) {
    EXPECT_EQ("M", arabicToRoman(1000));
    EXPECT_TRUE(true);
}

TEST(task5, test4) {
    EXPECT_EQ("I", arabicToRoman(1));
    EXPECT_TRUE(true);
}

TEST(task5, test5) {
    EXPECT_EQ("CCXXXVII", arabicToRoman(237));
    EXPECT_TRUE(true);
}

TEST(task5, test6) {
    EXPECT_EQ("DCLI", arabicToRoman(651));
    EXPECT_TRUE(true);
}

TEST(task2, test1) {
    EXPECT_EQ("11101101", reverseCode("10010010"));
    EXPECT_TRUE(true);
}

TEST(task2, test2) {
    EXPECT_EQ("0101001", reverseCode("0101001"));
    EXPECT_TRUE(true);
}

TEST(task2, test3) {
    EXPECT_EQ("10101010", reverseCode("11010101"));
    EXPECT_TRUE(true);
}

TEST(task2, test4) {
    EXPECT_EQ("10000000", reverseCode("11111111"));
    EXPECT_TRUE(true);
}

TEST(task2, test5) {
    EXPECT_EQ("01111111", reverseCode("01111111"));
    EXPECT_TRUE(true);
}

TEST(task7, test1) {
    int num = 89, check_div1 = 3;
    EXPECT_EQ(2, mod(num, check_div1));
    EXPECT_TRUE(true);
}

TEST(task7, test2) {
    int num = 126, check_div1 = 3;
    EXPECT_EQ(0, mod(num, check_div1));
    EXPECT_TRUE(true);
}

TEST(task7, test3) {
    int num = 512, check_div1 = 37;
    EXPECT_EQ(31, mod(num, check_div1));
    EXPECT_TRUE(true);
}

TEST(task7, test4) {
    int num = 222, check_div1 = 37;
    EXPECT_EQ(0, mod(num, check_div1));
    EXPECT_TRUE(true);
}

TEST(task7, test5) {
    int num = 317, check_div1 = 89;
    EXPECT_EQ(50, mod(num, check_div1));
    EXPECT_TRUE(true);
}

TEST(task7, test6) {
    int num = 1246, check_div1 = 89;
    EXPECT_EQ(0, mod(num, check_div1));
    EXPECT_TRUE(true);
}

TEST(task6, test1) {
    int num = 1;
    EXPECT_EQ(0, interesting(num));
    EXPECT_TRUE(true);
}

TEST(task6, test2) {
    int num = 9;
    EXPECT_EQ(1, interesting(num));
    EXPECT_TRUE(true);
}

TEST(task6, test3) {
    int num = 10;
    EXPECT_EQ(1, interesting(num));
    EXPECT_TRUE(true);
}

TEST(task6, test4) {
    int num = 34;
    EXPECT_EQ(3, interesting(num));
    EXPECT_TRUE(true);
}

TEST(task6, test5) {
    int num = 880055535;
    EXPECT_EQ(88005553, interesting(num));
    EXPECT_TRUE(true);
}

TEST(task6, test6) {
    int num = 619;
    EXPECT_EQ(62, interesting(num));
    EXPECT_TRUE(true);
}

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

string change(string str)
{

    int i = 100;
    while (i) {
        for (int i = 0; i < size(str); i++) {
            if (str[i] == 'c' && (str[i + 1] == 'e' || str[i + 1] == 'i' || str[i + 1] == 'y'))
                str.replace(i, 1, "s");
            if (str[i] == 'C' && ((str[i + 1] == 'e' || str[i + 1] == 'i' || str[i + 1] == 'y') || (str[i + 1] == 'E' || str[i + 1] == 'I' || str[i + 1] == 'Y')))
                str.replace(i, 1, "S");
            if (str[i] == 'c' && (str[i + 1] != 'e' || str[i + 1] != 'i' || str[i + 1] != 'y'))
                str.replace(i, 1, "k");
            if (str[i] == 'C' && ((str[i + 1] != 'e' || str[i + 1] != 'i' || str[i + 1] != 'y') || (str[i + 1] != 'E' || str[i + 1] != 'I' || str[i + 1] != 'Y')))
                str.replace(i, 1, "K");
            if (str[i] == 'q' && str[i + 1] == 'u')
                str.replace(i, 2, "kv");
            if (str[i] == 'Q' && ((str[i + 1] == 'u') || (str[i + 1] == 'U')))
                str.replace(i, 2, "Kv");
            if (str[i] == 'q')
                str.replace(i, 1, "k");
            if (str[i] == 'Q')
                str.replace(i, 1, "K");
            if (str[i] == 'x')
                str.replace(i, 1, "ks");
            if (str[i] == 'X')
                str.replace(i, 1, "Ks");
            if (str[i] == 'w')
                str.replace(i, 1, "v");
            if (str[i] == 'W')
                str.replace(i, 1, "V");
            if (str[i] == 'p' && str[i + 1] == 'h')
                str.replace(i, 2, "f");
            if (str[i] == 'P' && ((str[i + 1] == 'h') || (str[i + 1] == 'H')))
                str.replace(i, 2, "F");
            if (str[i] == 'y' && str[i + 1] == 'o' && str[i + 2] == 'u')
                str.replace(i, 3, "u");
            if (str[i] == 'Y' && (str[i + 1] == 'o' || str[i + 1] == 'O') && (str[i + 2] == 'u' || str[i + 2] == 'U'))
                str.replace(i, 3, "U");
            if (str[i] == 'o' && str[i + 1] == 'o')
                str.replace(i, 2, "u");
            if (str[i] == 'O' && (str[i + 1] == 'o' || str[i + 1] == 'O'))
                str.replace(i, 2, "U");
            if (str[i] == 'e' && str[i + 1] == 'e')
                str.replace(i, 2, "i");
            if (str[i] == 'E' && (str[i + 1] == 'e' || str[i + 1] == 'E'))
                str.replace(i, 2, "I");
            if (str[i] == 't' && str[i + 1] == 'h')
                str.replace(i, 2, "z");
            if (str[i] == 'T' && (str[i + 1] == 'h' || str[i + 1] == 'H'))
                str.replace(i, 2, "Z");
            if (str[i] == str[i + 1]) {
                str.replace(i + 1, 1, "");
            }
        }
        i--;
    }
    return str;
}
TEST(N4, num1) {
    EXPECT_EQ("Tu svift", change("Too swift"));
    EXPECT_TRUE(true);
}
TEST(N4, num2) {
    EXPECT_EQ(" for Ziks", change(" for Theex"));
    EXPECT_TRUE(true);
}
TEST(N4, num3) {
    EXPECT_EQ("tu kvik for Galov", change("too quick for Gallow"));
    EXPECT_TRUE(true);
}
TEST(N4, num4) {
    EXPECT_EQ("Prinse Josef", change("Prince Joseph"));
    EXPECT_TRUE(true);
}
int pow(int k, int n, int mod) {
    k %= mod;
    if (n == 0) {
        return 1 % mod; //k ^ 0
    }
    if (n % 2) {
        return (k * pow((k * k), n / 2, mod)) % mod; //k * k ^ (n - 1)
    }
    return pow((k * k), n / 2, mod) % mod; //k ^ (n / 2) * k ^ (n / 2)
}

bool Equal(const char* s1, const char* s2, int c) {
    bool Equal = true;
    for (int i = 0; i < c; ++i) {
        if (s1[i] != s2[i]) {
            Equal = false;
        }
    }
    return Equal;
}


TEST(task5, test1) {
    EXPECT_EQ(0, pow(20, 10, 1));
    EXPECT_TRUE(true);
}
TEST(task5, test2) {
    EXPECT_EQ(4, pow(10, 11, 6));
    EXPECT_TRUE(true);
}
TEST(task5, test3) {
    EXPECT_EQ(0, pow(10, 11, 4));
    EXPECT_TRUE(true);
}
TEST(task5, test4) {
    EXPECT_EQ(0, pow(4, 5, 2));
    EXPECT_TRUE(true);
}
TEST(task5, test5) {
    EXPECT_EQ(4, pow(4, 5, 5));
    EXPECT_TRUE(true);
}
TEST(task5, test6) {
    EXPECT_EQ(2, pow(4, 5, 7));
    EXPECT_TRUE(true);
}


TEST(task5, test11) {
    EXPECT_EQ(1, Equal("asd", "asd", 4));
    EXPECT_TRUE(true);
}
TEST(task5, test21) {
    EXPECT_EQ(0, Equal("asdf", "asd", 4));
    EXPECT_TRUE(true);
}
TEST(task5, test31) {
    EXPECT_EQ(1, Equal("asdqwerasdf", "asdqwerasdf", 4));
    EXPECT_TRUE(true);
}
TEST(task5, test41) {
    EXPECT_EQ(1, Equal("QwErTyUi", "QwErTyUi", 10));
    EXPECT_TRUE(true);
}
TEST(task5, test51) {
    EXPECT_EQ(0, Equal("Qsd", "qsd", 3));
    EXPECT_TRUE(true);
}
TEST(task5, test61) {
    EXPECT_EQ(1, Equal("aaaaaasd", "aaaasd", 4));
    EXPECT_TRUE(true);
}

bool func1(string* arr, int it) {
    string word = *arr;
    for (int i = 0; i < it; i++) {
        if (word.at(it) == word.at(i)) {
            return false;
            break;
        }
    }
    return true;
}

int count(string* arr, int it, char* letters) {
    string word = *arr;
    int times = 0;
    for (int i = 0; i < word.size(); i++) {
        if (letters[it] == word.at(i))
            times++;
    }
    return times;
}

int faktorial(int justnumber) {
    if (justnumber == 1) return 1;
    else return faktorial(justnumber - 1) * justnumber;
}

long int vf(int let, int* times) {
    long int p = 1;
    for (int i = 0; i < let; i++) {
        int new_str = times[i];
        p *= faktorial(new_str);
    }
    return p;
}
long double fact(int N)
{
    if (N < 0)
        return 0;
    if (N == 0)
        return 1;
    else
        return N * fact(N - 1);
}

double Sum(string str1) {

    double sum = 0, tmp, count = 0, f, s;
    bool M, N;

    while (count < str1.length()) {
        M = false;

        if (isdigit(str1[count])) {
            if (count != 0 && str1[count - 1] == '-')
            {
                tmp = str1[count] - '0';

                M = true;
            }
            else {
                tmp = str1[count] - '0';
            }

            ++count;

            while (isdigit(str1[count])) {
                tmp = tmp * 10 + (str1[count] - '0');

                ++count;
            }

            f = 1;

            if (str1[count] == '.' && isdigit(str1[count + 1])) {
                ++count;

                while (isdigit(str1[count])) {
                    f *= 10;

                    tmp = tmp + (long double)(str1[count] - '0') / f;

                    ++count;
                }
            }

            if ((str1[count] == 'e' || str1[count] == 'E') && (isdigit(str1[count + 1]) || (str1[count + 1] == '+' && isdigit(str1[count + 2])) || (str1[count + 1] == '-' && isdigit(str1[count + 2])))) {
                N = false;

                ++count;

                if (str1[count] == '-') {
                    N = true;
                    ++count;
                }
                else if (str1[count] == '+') {
                    ++count;
                }

                s = str1[count] - '0';

                ++count;

                while (isdigit(str1[count])) {
                    s = s * 10 + (str1[count] - '0');
                    ++count;
                }

                if (N) {
                    s *= -1;
                }

                tmp *= pow(10, s);
            }

            if (M) {
                tmp *= -1;
            }


            sum += tmp;
        }

        ++count;
    }

    return sum;
}
TEST(task6, test1) {
    EXPECT_EQ(120, fact(5));
    EXPECT_TRUE(true);
}
TEST(task6, test2) {
    EXPECT_EQ(3628800, fact(10));
    EXPECT_TRUE(true);
}
TEST(task6, test3) {
    EXPECT_EQ(1, fact(1));
    EXPECT_TRUE(true);
}
TEST(task6, test4) {
    EXPECT_EQ(1, fact(0));
    EXPECT_TRUE(true);
}
TEST(task6, test5) {
    EXPECT_EQ(0, fact(-5));
    EXPECT_TRUE(true);
}
TEST(task6, test6) {
    EXPECT_EQ(87178291200, fact(14));
    EXPECT_TRUE(true);
}

TEST(task9, test1) {
    EXPECT_EQ(7, Sum("dfg1dfhg6"));
    EXPECT_TRUE(true);
}
TEST(task9, test2) {
    EXPECT_EQ(55555, Sum("dhghadsjfhajsfh55555"));
    EXPECT_TRUE(true);
}
TEST(task9, test3) {
    EXPECT_EQ(2468, Sum("1234ggggg1234"));
    EXPECT_TRUE(true);
}
TEST(task9, test4) {
    EXPECT_EQ(10.32, Sum("1234e-2e-2e-2e-2"));
    EXPECT_TRUE(true);
}
TEST(task9, test5) {
    EXPECT_EQ(7, Sum("hwqefhdfhdsjhfd7"));
    EXPECT_TRUE(true);
}
TEST(task9, test6) {
    EXPECT_EQ(55, Sum("a1b2b3b4b5b6b7b8b9bb10"));
    EXPECT_TRUE(true);
}
int f(char str[]) {

    char brackets[] = "[{()}]", * a;
    a = brackets;
    int count[6];
    int count2 = 0;
    for (int i = 0; i < 6; i++) {
        count[i] = 0;
    }



    for (int i = 0; i < strlen(str); i++) {
        if (strchr(brackets, str[i])) {
            count[strchr(brackets, str[i]) - a]++;
            count2++;
        }
    }
    // std::cout << "—кобки :" << std::endl;


    for (int i = 0; i < 6; i++) {
        // std::cout << brackets[i] << " - " << count[i] << std::endl;
    }

    return count2;
}

TEST(task1, test1) {
    EXPECT_EQ(4, f("{}{}"));
    EXPECT_TRUE(true);
}
TEST(task1, test2) {
    EXPECT_EQ(4, f("{}[]p"));
    EXPECT_TRUE(true);
}
TEST(task1, test3) {
    EXPECT_EQ(2, f("{}"));
    EXPECT_TRUE(true);
}
TEST(task1, test4) {
    EXPECT_EQ(7, f("()()()("));
    EXPECT_TRUE(true);
}
string f3(string a, string b) {


    int count1 = 0;
    int count2 = 0;
    for (int i = 0; a[i] != '\0'; ++i) {
        count1 += 1;
    }
    for (int i = 0; b[i] != '\0'; ++i) {
        count2 += 1;
    }
    if (count1 != count2)
    {
        cout << "NO\n";
        return "NO";
    }
    else
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if (a != b)
        {
            cout << "NO\n";
            return "NO";
        }
        else
        {
            cout << "YES\n";
            return "YES";
        }
    }


}
TEST(task3, test1) {
    EXPECT_EQ("YES", f3("solo", "loso"));
    EXPECT_TRUE(true);
}
TEST(task3, test2) {
    EXPECT_EQ("NO", f3("sfghj", "losdxfg"));
    EXPECT_TRUE(true);
}
TEST(task3, test3) {
    EXPECT_EQ("NO", f3("srtfy", "rxdctfvygb"));
    EXPECT_TRUE(true);
}
TEST(task3, test4) {
    EXPECT_EQ("YES", f3("куб", "бук"));
    EXPECT_TRUE(true);
}
TEST(task3, test5) {
    EXPECT_EQ("YES", f3("пук", "куп"));
    EXPECT_TRUE(true);
}
TEST(task3, test6) {
    EXPECT_EQ("YES", f3("поп", "поп"));
    EXPECT_TRUE(true);
}
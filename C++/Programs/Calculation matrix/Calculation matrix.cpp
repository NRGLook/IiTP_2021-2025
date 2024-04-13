// Calculation matrix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>

using namespace std;
void Starline() {
    cout << '\n';
    for (int i = 0; i < 50; ++i)
        cout << '*';
    cout << '\n';
    return;
}
int main() {
    const int n = 5;
    bool r1[n][n];
    bool r2[n][n];
    Starline();
    cout << "Enter first matrix";
    Starline();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> r1[i][j];
    Starline();
    cout << "Enter second matrix";
    Starline();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> r2[i][j];
    Starline();
    cout << "r1 or r2";
    Starline();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << (r1[i][j] || r2[i][j]) << ' ';
        }
        cout << '\n';
    }
    Starline();
    cout << "r1 and r2";
    Starline();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << (r1[i][j] && r2[i][j]) << ' ';
        }
        cout << '\n';
    }
    Starline();
    cout << "r1 \\ r2";
    Starline();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << (r1[i][j] && !r2[i][j]) << ' ';
        }
        cout << '\n';
    }
    Starline();
    bool c[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++)
                c[i][j] = (c[i][j] || (r1[i][k] && r2[k][j]));
        }
    }
    cout << "r1 * r2";
    Starline();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
    Starline();
    bool c1[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c1[i][j] = 0;
            for (int k = 0; k < n; k++)
                c1[i][j] = (c1[i][j] || (r1[i][k] && r2[j][k]));
        }
    }
    cout << "r1 * r2 -1";
    Starline();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << c1[i][j] << " ";
        cout << endl;
    }
    Starline();

    cout << "r1 ^ r2";
    Starline();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ((!r1[i][j] && r2[i][j]) || (!r2[i][j] && r1[i][j])) << ' ';
        }
        cout << '\n';
    }
    Starline();
}
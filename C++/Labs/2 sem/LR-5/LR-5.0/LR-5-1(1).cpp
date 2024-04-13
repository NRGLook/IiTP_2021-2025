// LR-5-1(1) Выполнил:Тиханенок Илья
//Задание 1:Составить программу вычисления элементов в двумерном динамическом массиве.

#include <iostream>
#include "..\LR-5\StaticLib\Header1.h";
#include <iomanip>

int main(){
    int n, n1;

    std::cout << "Enter the size of matrix B (remember that matrix is square): ";
    std::cin >> n;
    std::cout << "Enter the size of matrix C (remember that matrix is square and should have the same size as matrix B): ";
    std::cin >> n1;

    //initializing a two-dimensional array
    int** B = new int* [n];
    for (int i = 0; i < n; i++) {
        B[i] = new int[n];
    }
    //Enter and generate array(input elements of array):
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            std::cout << "Enter B[" << i << "][" << j << "]: ";
            std::cin >> B[i][j];
        }

    MatrixB(B,n);

    //initializing a two-dimensional array
    int** C = new int* [n1];
    for (int i = 0; i < n1; i++) {
        C[i] = new int[n1];
    }
    //Enter and generate array:
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n1; j++)
        {
            std::cout << "Enter C[" << i << "][" << j << "]: ";
            std::cin >> C[i][j];
        }

    MatrixC(C,n1);

    //initializing a two-dimensional array
    int** A = new int* [n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
    }
    //Enter and generate array:
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (fabs(B[i][j]) > fabs(C[i][j])) {
                A[i][j] = B[i][j];
            }
            else if (fabs(B[i][j]) <= fabs(C[i][j])) {
                A[i][j] = C[i][j];
            }
        }
   //Output array:
    std::cout << "Array A:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            std::cout << A[i][j] << " ";
        std::cout << "\n";

    }
}



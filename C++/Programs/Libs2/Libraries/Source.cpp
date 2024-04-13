#include <iostream>
int MatrixB(int n) {
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
    //Output array:
    std::cout << "Array B:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
           std::cout << B[i][j] << "  ";
           std::cout << "\n";
    }
     
    return 0;
}
int MatrixC(int n1) {
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
    //Output array:
    std::cout << "Array C:\n";
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n1; j++)
            std::cout << C[i][j] << "  ";
        std::cout << "\n";
    }
    return 0;
}
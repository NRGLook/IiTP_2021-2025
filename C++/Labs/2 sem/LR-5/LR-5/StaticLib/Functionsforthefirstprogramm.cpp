#include <iostream>
void MatrixB(int** B,int n) {
    //Output array:
    std::cout << "Array B:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            std::cout << B[i][j] << "  ";
        std::cout << "\n";
    }
}
void MatrixC(int** C,int n1) {
    //Output array:
    std::cout << "Array C:\n";
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n1; j++)
            std::cout << C[i][j] << "  ";
        std::cout << "\n";
    }
}
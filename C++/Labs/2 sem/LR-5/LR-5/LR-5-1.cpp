// LR-5-1 Выполнил:Тиханёнок Илья
//Задание 1:

#include <iostream>

int MatrixB(int n) {
    std::cout << "Enter the size of matrix B:(matrix is square):";
    std::cin >> n;
    //initializing a two-dimensional array
    int** B = new int* [n];
    for (int i = 0; i < n; i++) {
        B[i] = new int[n];
    }
    //Enter and generate array:
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
}

int main()
{ 
    int n, n1, n2;
    std::cout << "Enter the size of matrix B:(matrix is square):";
    std::cin >> n;
    //initializing a two-dimensional array
    int MatrixB();
    std::cout << "Remember that the size of matrix B should equal to the size of matrix C.\nEnter the size of matrix C:(matrix is square):";
    std::cin >> n1;
    //initializing a two-dimensional array
    int MatrixC();
    //initializing a two-dimensional array
    std::cout << "Enter the size of matrix A:(matrix is square):";
    std::cin >> n2;
    if (fabs(B[i][j]) > fabs(C[i][j])) {
        int** A = new int* [n2];
        for (int i = 0; i < n2; i++) {
            A[i] = new int[n2];
        }
        //Enter and generate array:
        for (int i = 0; i < n2; i++)
            for (int j = 0; j < n2; j++)
            {
                A[i][j]=B[i][j];
            }
        //Output array:
        std::cout << "Array A:\n";
        for (int i = 0; i < n2; i++)
        {
            for (int j = 0; j < n2; j++)
                std::cout << A[i][j] << " ";
            std::cout << "\n";
        }
    }
    else if(fabs(B[i][j])<=fabs(C[i][j])) {
        int** A = new int* [n2];
        for (int i = 0; i < n2; i++) {
            A[i] = new int[n2];
        }
        //Enter and generate array:
        for (int i = 0; i < n2; i++)
            for (int j = 0; j < n2; j++)
            {
                A[i][j] = C[i][j];
            }
        //Output array:
        std::cout << "Array A:\n";
        for (int i = 0; i < n2; i++)
        {
            for (int j = 0; j < n2; j++)
                std::cout << A[i][j] << "  ";
            std::cout << "\n";
        }
    }
   
    return 0;
}


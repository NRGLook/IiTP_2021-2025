// VectoraccordingtoSimpleCode.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

int main()
{
    setlocale(LC_ALL, "Rus");
    std::vector<int> Myvector;

    Myvector.push_back(2);
    Myvector.push_back(3);

    std::cout << "The number of elements in the vector:" << Myvector.size() << std::endl;
    
    Myvector.push_back(4);
    Myvector.push_back(5);


    std::cout << "\n" << "After adding:" << Myvector.size() << std::endl;

    for (int i = 0; i < Myvector.size(); i++)
        std::cout << Myvector[i] << std::endl;

    std::cout << "Index:" << Myvector.at(0);

    std::cout << std::endl << "Capacity:" << Myvector.capacity();

    Myvector.push_back(2);
    Myvector.push_back(3);
    Myvector.reserve(1000);

    std::cout << std::endl << std::endl << "New capacity:" << Myvector.capacity() << std::endl << Myvector.size();

    Myvector.shrink_to_fit();
    std::cout << std::endl << std::endl << "New capacity after shrink_to_fit:" << Myvector.size();

    Myvector.resize(20);
    std::cout << std::endl << "After resize:" << Myvector.size();

    for (int i = 0; i < Myvector.size(); i++)
        std::cout << Myvector[i] << std::endl;
}


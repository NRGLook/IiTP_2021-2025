#include <iostream>
#include <Windows.h>

int main() {
	HINSTANCE load;
	load = LoadLibrary(L"DynamicLib.dll");
	typedef int (*sum) (int, int);
	sum Sum;
	Sum = (sum)GetProcAddress(load, "Sum");
	int a = 100;
	int b = 20;
    std::cout << Sum(a, b);
	FreeLibrary(load);
}
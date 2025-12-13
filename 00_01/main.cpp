#include <Windows.h>
#include <iostream>
int main()
{
	/// Set console output to UTF-8
	SetConsoleOutputCP(65001);
	char str[] = "たけのこの里";
	std::cout << str;
	return 0;
}
#include <Windows.h>
#include <cstdio>

int main()
{
	/// Set console output to UTF-8
	SetConsoleOutputCP(65001);
	char str[] = "たけのこの里";
	printf("%s", str);
	return 0;
}
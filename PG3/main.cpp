#include<Windows.h>
#include<iostream>
int main()
{
	SetConsoleOutputCP(65001);
	char str[] = "たけのこの里";
	printf("%s", str);
	return 0;
}
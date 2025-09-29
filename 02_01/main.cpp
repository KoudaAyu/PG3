#include<stdio.h>
template<typename T>
T Min(T a, T b)
{
	return (a < b) ? a : b;
}

int main()
{
	printf("Min(3, 5) = %d\n", Min(3, 5));
	printf("Min(3.5f, 2.5f) = %f\n", Min(3.5f, 2.5f));
	printf("Min(0.5, 2.5) = %f\n", Min(0.5, 2.5));

	return 0;
}
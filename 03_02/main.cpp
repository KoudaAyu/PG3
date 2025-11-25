#include <iostream>
#include <string>
#include "comparison.h"

int main()
{
    MinClass<int> mi(7, 3);
    std::cout << "Min<int>: " << mi.Min() << "\n";

    MinClass<double> md(2.5, 3.1);
    std::cout << "Min<double>: " << md.Min() << "\n";

	MinClass<float> mf(4.2f, 1.9f);
	std::cout << "Min<float>: " << mf.Min() << "\n";

  

    return 0;
}
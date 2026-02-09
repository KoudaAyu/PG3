#include <iostream>
#include <string>
#include <iomanip>
#include "comparison.h"


int main()
{
    MinClass<int> mi(7, 3);
    std::cout << "Min<int>: " << mi.Min() << "\n";

    MinClass<double> md(2.5, 3.1);
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "Min<double>: " << md.Min() << "\n";

    MinClass<float> mf(4.2f, 1.9f);
    std::cout << "Min<float>: " << mf.Min() << "\n";

  
    MinClassMixed<int, float> mix1(5, 3.7f);
    std::cout << "Min<int, float>: " << mix1.Min() << "\n";

    MinClassMixed<double, int> mix2(1.2, 2);
    std::cout << "Min<double, int>: " << mix2.Min() << "\n";

  
    MinClassMixed<float, double> mix3(2.2f, 2.5);
    std::cout << "Min<float, double>: " << mix3.Min() << "\n";

    MinClassMixed<double, float> mix4(2.75, 2.9f);
    std::cout << "Min<double, float>: " << mix4.Min() << "\n";

    return 0;
}
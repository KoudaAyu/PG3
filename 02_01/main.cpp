#include <iostream>

// 関数テンプレートを用いて、小さい値を返す関数Min()を作成
template <typename T>
T Min(T a, T b)
{
    return (a < b) ? a : b;
}

int main()
{
    // int型、float型、double型の3対の引数を用意して呼び出す

    // int型
    int i1 = 3, i2 = 5;
    std::cout << "Min(int): " << Min(i1, i2) << std::endl;

    // float型
    float f1 = 3.5f, f2 = 2.5f;
    std::cout << "Min(float): " << Min(f1, f2) << std::endl;

    // double型
    double d1 = 0.5, d2 = 2.5;
    std::cout << "Min(double): " << Min(d1, d2) << std::endl;

    return 0;
}
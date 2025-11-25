#pragma once


// 二つの値を比較し、小さい方の値を返すクラステンプレート
template<typename T>
class MinClass
{
public:
	T a;
	T b;

	MinClass(T first, T second)
		: a(first), b(second)
	{
	}

	// 小さい方の値を返す（operator< が使用可能であることが前提）
	T Min() const
	{
		return (a < b) ? a : b;
	}
};

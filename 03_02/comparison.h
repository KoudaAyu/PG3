#pragma once
#include <type_traits>


// 二つの値を比較し、小さい方の値を返すクラステンプレート（同一型版）
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

// 異なる型 A, B を受け取り、共通型で比較・返却するテンプレート
// std::common_type によって A と B の共通の型を決定します
template<typename A, typename B>
class MinClassMixed
{
public:
	A a;
	B b;

	MinClassMixed(A first, B second)
		: a(first), b(second)
	{
	}

	using Common = typename std::common_type<A, B>::type;

	Common Min() const
	{
		return (a < b) ? static_cast<Common>(a) : static_cast<Common>(b);
	}
};


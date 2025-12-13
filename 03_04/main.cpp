#include <iostream>
#include <vector>
#define _USE_MATH_DEFINES
#include <cmath> 
#include <iomanip> 


#ifndef M_PI
constexpr double M_PI = 3.14159265358979323846;
#endif


class IShape
{
public:

	virtual double Size() const = 0;


	virtual void Draw() const = 0;


	virtual ~IShape() = default;
};



// 円（Circle）クラス
class Circle : public IShape
{
private:

	double radius_; // 半径

public:
	// コンストラクタ
	Circle(double radius) : radius_(radius) {}

	// Size()のオーバーライド: 円の面積を計算
	double Size() const override
	{
		// 面積 = 半径 * 半径 * π

		return radius_ * radius_ * M_PI;
	}

	// Draw()のオーバーライド: 面積を表示
	void Draw() const override
	{
		std::cout << "図形: 円" << std::endl;
		std::cout << "半径: " << radius_ << std::endl;

		// Size()を呼び出して面積を表示 (小数点以下2桁)
		std::cout << "面積: " << std::fixed << std::setprecision(2) << Size() << std::endl;
	}
};

// -----------------------------------------------------

class Rectangle : public IShape
{
private:

	double width_;  // 幅
	double height_; // 高さ

public:
	// コンストラクタ
	Rectangle(double width, double height) : width_(width), height_(height) {}

	// Size()のオーバーライド: 長方形の面積を計算
	double Size() const override
	{
		// 面積 = 幅 * 高さ
		return width_ * height_;
	}

	// Draw()のオーバーライド: 面積を表示
	void Draw() const override
	{
		std::cout << "図形: 四角形" << std::endl;
		std::cout << "幅: " << width_ << ", 高さ: " << height_ << std::endl;

		// Size()を呼び出して面積を表示 (小数点以下2桁)
		std::cout << "面積: " << std::fixed << std::setprecision(2) << Size() << std::endl;
	}
};

// -----------------------------------------------------


int main()
{

	std::vector<IShape*> shapes;

	// 図形インスタンスを動的に作成し、ベクタに追加
	shapes.push_back(new Circle(5.0));
	shapes.push_back(new Rectangle(4.0, 6.0));
	shapes.push_back(new Circle(10.0));
	shapes.push_back(new Rectangle(12.5, 3.0));

	std::cout << "--- 図形の面積表示プログラム ---" << std::endl;


	for (const auto& shape : shapes)
	{
		std::cout << "-----------------------------------" << std::endl;

		shape->Draw();
	}

	std::cout << "-----------------------------------" << std::endl;


	for (const auto& shape : shapes)
	{
		delete shape;
	}

	return 0;
}
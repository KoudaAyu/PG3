#include <iostream>
#include <memory>
#include <vector>
#include <iomanip>

class IShape {
public:
    virtual ~IShape() = default;
    // 面積を計算して返す
    virtual double Size() const = 0;
    // 面積を表示する（Draw）
    virtual void Draw() const = 0;
};

class Circle : public IShape {
public:
    explicit Circle(double r) : radius_(r) {}

    double Size() const override {
        static constexpr double PI = 3.14159265358979323846;
        return PI * radius_ * radius_;
    }

    void Draw() const override {
        std::cout << "Circle: radius=" << radius_
                  << " area=" << std::fixed << std::setprecision(2) << Size()
                  << std::endl;
    }

private:
    double radius_;
};

class Rectangle : public IShape {
public:
    Rectangle(double w, double h) : width_(w), height_(h) {}

    double Size() const override {
        return width_ * height_;
    }

    void Draw() const override {
        std::cout << "Rectangle: " << width_ << " x " << height_
                  << " area=" << std::fixed << std::setprecision(2) << Size()
                  << std::endl;
    }

private:
    double width_;
    double height_;
};

int main() {
    std::vector<std::unique_ptr<IShape>> shapes;
    shapes.emplace_back(std::make_unique<Circle>(2.5));
    shapes.emplace_back(std::make_unique<Rectangle>(3.0, 4.0));

    for (const auto &s : shapes) {
        s->Draw();
    }

    return 0;
}

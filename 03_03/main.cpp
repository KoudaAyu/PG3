#include <iostream>
#include <memory>
#include <vector>


class Animal {
public:
    virtual ~Animal() = default;
    // speak は動物ごとに異なる鳴き声を出す
    virtual void speak() const = 0;
};

class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "犬: ワンワン！" << std::endl;
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        std::cout << "猫: ニャー" << std::endl;
    }
};

class Bird : public Animal {
public:
    void speak() const override {
        std::cout << "鳥: ピーピー" << std::endl;
    }
};

int main() {
    // 異なる動物インスタンスを基底クラスのポインタで扱うことで
    // ランタイムで適切な振る舞いが呼ばれることを示す。
    std::vector<std::unique_ptr<Animal>> zoo;
    zoo.emplace_back(std::make_unique<Dog>());
    zoo.emplace_back(std::make_unique<Cat>());
    zoo.emplace_back(std::make_unique<Bird>());

    for (const auto &a : zoo) {
        a->speak(); // 同じ呼び出しでも動的に対応する振る舞いが実行される
    }

    return 0;
}

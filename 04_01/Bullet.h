#pragma once
#include "MathUtl.h"
class Bullet
{
public:
	Bullet();
	~Bullet();
	void Initialize();
	void Update();
	void Draw();

	void SetActive(bool isActive) {
		isActive_ = isActive;
	}
	bool IsActive() const {
		return isActive_;
	}

	void SetPosition(const Vector2& pos) { position_ = pos; }
	Vector2 GetPosition() const { return position_; }
	float GetRadius() const { return radius; }

private:
	bool isActive_;
	float radius = 5.0f;
	Vector2 position_{};
	Vector2 velocity_{};

};

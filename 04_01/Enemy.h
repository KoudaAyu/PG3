#pragma once
#include "MathUtl.h"

class Enemy
{
public:
	Enemy();
	~Enemy();
	void Initialize();
	void Update();
	void Draw();

	void SetPosition(const Vector2& pos) { position_ = pos; }
	Vector2 GetPosition() const { return position_; }
	float GetRadius() const { return radius_; }
	void SetAlive(bool alive) { isAlive_ = alive; }
	bool IsAlive() const { return isAlive_; }

private:
	Vector2 position_{ 640.0f, 200.0f };
	float radius_ = 16.0f;
	bool isAlive_ = true;
};

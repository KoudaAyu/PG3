#pragma once
#include"Struct.h"

class Player
{
public:
	Player();
	~Player();
	void Initialize();
	void Update();
	void Draw();

	void MoveRight();
	void MoveLeft();

private:
	Vector2 position_ = { 640.0f,360.0f };
	float speed_ = 5.0f;
};
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
	void MoveUp();
	void MoveDown();

	const IntVector2& GetPosition() const { return position_; }

private:
	IntVector2 position_ = { 640,360 };
	int speed_ = 100;
	IntVector2 size = { 50,50 };
};
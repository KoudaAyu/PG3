#pragma once
#include<Novice.h>
#include"MathUtl.h"
#include"Bullet.h"
class Player
{
	public:
	Player();
	~Player();
	void Initialize();
	void Update();
	void Draw();

	Bullet& GetBullet() { return bullet_; }

private:
	Vector2 position_ = {640.0f,360.0f};
	Bullet bullet_;

};

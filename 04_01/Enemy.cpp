#include "Enemy.h"
#include <Novice.h>

Enemy::Enemy() {}
Enemy::~Enemy() {}

void Enemy::Initialize() {
	
	isAlive_ = true;
}

void Enemy::Update() {
}

void Enemy::Draw() {
	if (!isAlive_) return;
	Novice::DrawEllipse((int)position_.x, (int)position_.y, (int)radius_, (int)radius_, 0.0f, 0xFF0000FF, kFillModeSolid);
}

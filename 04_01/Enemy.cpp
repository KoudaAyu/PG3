#include "Enemy.h"
#include <Novice.h>

Enemy::Enemy() {}
Enemy::~Enemy() {}

void Enemy::Initialize() {
	// default position already set
	isAlive_ = true;
}

void Enemy::Update() {
	// simple idle behaviour
}

void Enemy::Draw() {
	if (!isAlive_) return;
	Novice::DrawEllipse((int)position_.x, (int)position_.y, (int)radius_, (int)radius_, 0.0f, 0xFF0000FF, kFillModeSolid);
}

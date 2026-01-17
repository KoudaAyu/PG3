#include "Enemy.h"
#include <Novice.h>

Enemy::Enemy() {}

Enemy::~Enemy() {}

void Enemy::Initialize() {
	isAlive_ = true;
	highlighted_ = false;
}

void Enemy::Update() {
}

void Enemy::Draw() {
	if (!isAlive_) return;
	int halfW = size_.x / 2;
	int halfH = size_.y / 2;
	unsigned int color = highlighted_ ? 0x00FFFF00 : 0xFF00FF00;
	Novice::DrawBox(position_.x - halfW, position_.y - halfH, size_.x, size_.y, 0.0f, color, kFillModeSolid);
}

void Enemy::SetPosition(const IntVector2& pos) {
	position_ = pos;
}

void Enemy::ToggleHighlight() {
	highlighted_ = !highlighted_;
}

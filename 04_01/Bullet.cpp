#include "Bullet.h"
#include <Novice.h>

Bullet::Bullet()
	: isActive_(false)
{
}

Bullet::~Bullet() {}

void Bullet::Initialize() {
	isActive_ = false;
	position_ = { 0.0f, 0.0f };
	velocity_ = { 0.0f, -10.0f }; // move upward by default
}

void Bullet::Update() {
	// 弾の動作更新処理
	if (!isActive_) { return; }
	position_.x += velocity_.x;
	position_.y += velocity_.y;

	
	if (position_.y < -10.0f || position_.y > 730.0f || position_.x < -10.0f || position_.x > 1290.0f) {
		isActive_ = false;
	}
}

void Bullet::Draw() {
	// 弾の描画処理
	if (isActive_)
	{
		Novice::DrawEllipse((int)position_.x, (int)position_.y, (int)radius, (int)radius, 0.0f, 0xFFFFFFFF, kFillModeSolid);
	}
}


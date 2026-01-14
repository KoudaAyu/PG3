#include "Player.h"

Player::Player() {}
Player::~Player() {}

void Player::Initialize() {
	bullet_.Initialize();
}

void Player::Update() {
	// SPACE to shoot
	char keys[256]{};
	Novice::GetHitKeyStateAll(keys);
	if (!bullet_.IsActive() && keys[DIK_SPACE]) {
		bullet_.SetActive(true);
		bullet_.SetPosition(position_);
	}
	bullet_.Update();
}

void Player::Draw() {
	// draw player (simple marker)
	Novice::DrawEllipse((int)position_.x, (int)position_.y, 50, 50, 0.0f, 0x00FF00FF, kFillModeSolid);
	bullet_.Draw();
}

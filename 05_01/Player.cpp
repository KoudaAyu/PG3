#include"Player.h"
#include<Novice.h>

Player::Player() {}

Player::~Player() {}

void Player::Initialize() {
}

void Player::Update() {
}

void Player::Draw() {
	Novice::DrawBox((int)position_.x - 25, (int)position_.y - 25, 50, 50, 0.0f, 0x00FF00FF, kFillModeSolid);
}

void Player::MoveRight() {
	position_.x += speed_;
}

void Player::MoveLeft() {
	position_.x -= speed_;
}

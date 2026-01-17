#include "Player.h"
#include <Novice.h>

Player::Player() {}

Player::~Player() {}

void Player::Initialize()
{
	
	position_.x = (position_.x / size.x) * size.x + size.x / 2;
	position_.y = (position_.y / size.y) * size.y + size.y / 2;
}

void Player::Update()
{
	
	position_.x = (position_.x / size.x) * size.x + size.x / 2;
	position_.y = (position_.y / size.y) * size.y + size.y / 2;

}

void Player::Draw()
{
	int halfW = size.x / 2;
	int halfH = size.y / 2;
	Novice::DrawBox((int)position_.x - halfW, (int)position_.y - halfH, size.x, size.y, 0.0f, 0xFF0000FF, kFillModeWireFrame);
}

void Player::MoveRight()
{

	position_.x += size.x;
}

void Player::MoveLeft()
{
	
	position_.x -= size.x;
}

void Player::MoveUp()
{
	
	position_.y -= size.y;
}

void Player::MoveDown()
{
	
	position_.y += size.y;
}

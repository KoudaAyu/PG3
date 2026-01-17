#pragma once
#include "Command.h"
#include "InputHandle.h"
#include "Player.h"
#include "Enemy.h"

class GameScene
{
public:
	GameScene();
	~GameScene();
	void Initialize();
	void Update();
	void Draw();

private:
	Player* player_ = nullptr;
	InputHandler* inputHandler = nullptr;
	ICommand* iCommand = nullptr;

	static const int kEnemyCount = 5;
	Enemy* enemies_[kEnemyCount] = {};

	int blockWidth_ = 50;
	int blockHeight_ = 50;

	char prevKeys_[256] = {};
};
#pragma once
#include"Command.h"
#include"InputHandle.h"
#include"Player.h"
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
};
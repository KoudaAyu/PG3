#include"GameScene.h"
#include<Novice.h>

GameScene::GameScene() {}

GameScene::~GameScene() {}

void GameScene::Initialize()
{
	inputHandler = new InputHandler();

	inputHandler->AssignMoveLeftCommand2PressKeyA();
	inputHandler->AssignMoveRightCommand2PressKeyD();

	player_ = new Player();
	player_->Initialize();
}

void GameScene::Update()
{
	iCommand = inputHandler->HandleInput();
	if (iCommand != nullptr) {
		iCommand->Execute(*player_);
	}
	player_->Update();
}

void GameScene::Draw()
{
	Novice::ScreenPrintf(10, 30, "Game Scene: Use Left/Right arrows to move");
	player_->Draw();
}

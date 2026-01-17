#include "GameScene.h"
#include <Novice.h>
#include <cstring>

GameScene::GameScene() {}

GameScene::~GameScene() {
    delete inputHandler;
    delete player_;
    for (int i = 0; i < kEnemyCount; ++i) {
        delete enemies_[i];
    }
}

void GameScene::Initialize()
{
    inputHandler = new InputHandler();

    inputHandler->AssignMoveLeftCommand2PressKeyA();
    inputHandler->AssignMoveRightCommand2PressKeyD();
    inputHandler->AssignMoveUpCommand2PressKeyW();
    inputHandler->AssignMoveDownCommand2PressKeyS();

    player_ = new Player();
    player_->Initialize();

    IntVector2 positions[kEnemyCount] = {
        { blockWidth_ * 2 + blockWidth_ / 2, blockHeight_ * 2 + blockHeight_ / 2 },
        { blockWidth_ * 5 + blockWidth_ / 2, blockHeight_ * 3 + blockHeight_ / 2 },
        { blockWidth_ * 8 + blockWidth_ / 2, blockHeight_ * 6 + blockHeight_ / 2 },
        { blockWidth_ * 12 + blockWidth_ / 2, blockHeight_ * 4 + blockHeight_ / 2 },
        { blockWidth_ * 15 + blockWidth_ / 2, blockHeight_ * 7 + blockHeight_ / 2 }
    };

    for (int i = 0; i < kEnemyCount; ++i) {
        enemies_[i] = new Enemy();
        enemies_[i]->Initialize();
        enemies_[i]->SetPosition(positions[i]);
    }
}

void GameScene::Update()
{
    char keys[256] = {};
    Novice::GetHitKeyStateAll(keys);

    iCommand = inputHandler->HandleInput();
    if (iCommand != nullptr) {
        iCommand->Execute(*player_);
    }
    player_->Update();

    if (keys[DIK_SPACE] && prevKeys_[DIK_SPACE] == 0) {
        int playerCol = player_->GetPosition().x / blockWidth_;
        int playerRow = player_->GetPosition().y / blockHeight_;

        for (int i = 0; i < kEnemyCount; ++i) {
            if (!enemies_[i] || !enemies_[i]->IsAlive()) continue;
            int enemyCol = enemies_[i]->GetPosition().x / blockWidth_;
            int enemyRow = enemies_[i]->GetPosition().y / blockHeight_;
            if (playerCol == enemyCol && playerRow == enemyRow) {
                enemies_[i]->ToggleHighlight();
            }
        }
    }

    memcpy(prevKeys_, keys, 256);

    for (int i = 0; i < kEnemyCount; ++i) {
        if (enemies_[i]) enemies_[i]->Update();
    }
}

void GameScene::Draw()
{
    Novice::ScreenPrintf(10, 30, "Game Scene: Use Left/Right arrows to move");
    const int screenWidth = 1280;
    const int screenHeight = 720;
    int cols = screenWidth / blockWidth_;
    int rows = screenHeight / blockHeight_;
    unsigned int gridColor = 0x00FFFFFF;

    for (int j = 0; j <= cols; ++j) {
        int x = j * blockWidth_;
        Novice::DrawLine(x, 0, x, screenHeight, gridColor);
    }
    for (int i = 0; i <= rows; ++i) {
        int y = i * blockHeight_;
        Novice::DrawLine(0, y, screenWidth, y, gridColor);
    }

    for (int i = 0; i < kEnemyCount; ++i) {
        if (enemies_[i] && enemies_[i]->IsAlive()) {
            const IntVector2& p = enemies_[i]->GetPosition();
           
            Novice::ScreenPrintf(10, 50 + i * 20, "Enemy %d: x=%d y=%d", i, p.x, p.y);
           
            IntVector2 s = enemies_[i]->GetSize();
            int halfW = s.x / 2;
            int halfH = s.y / 2;
            unsigned int color = enemies_[i]->IsHighlighted() ? 0x00FFFFFF : 0xFF00FFFF;
            Novice::DrawBox(p.x - halfW, p.y - halfH, s.x, s.y, 0.0f, color, kFillModeSolid);
           
            enemies_[i]->Draw();
        }
    }

    if (player_) player_->Draw();
}
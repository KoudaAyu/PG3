#include <Novice.h>
#include "GameScene.h"
#include "SceneManager.h"

GameScene::GameScene() {}
GameScene::~GameScene() {}

void GameScene::Initialize() {
	player_.Initialize();
	enemy_.Initialize();
}

void GameScene::Update(const char* keys, const char* preKeys) {
	(void)keys; (void)preKeys;
	player_.Update();
	enemy_.Update();

	
	Bullet& b = player_.GetBullet();
	if (b.IsActive() && enemy_.IsAlive()) {
		Vector2 bp = b.GetPosition();
		Vector2 ep = enemy_.GetPosition();
		float dx = bp.x - ep.x;
		float dy = bp.y - ep.y;
		float dist2 = dx * dx + dy * dy;
		float radiusSum = b.GetRadius() + enemy_.GetRadius();
		if (dist2 <= radiusSum * radiusSum) {
		
			enemy_.SetAlive(false);
			b.SetActive(false);
				}
	}
	
}

void GameScene::Draw() {
	Novice::ScreenPrintf(10, 30, "Game Scene: Press G to clear");
	player_.Draw();
	enemy_.Draw();
}

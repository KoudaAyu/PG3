#pragma once
#include "Scene.h"
#include "Player.h"
#include "Enemy.h"

class GameScene : public Scene
{
	public:
	GameScene();
	~GameScene();
	void Initialize() override;
	void Update(const char* keys, const char* preKeys) override;
	void Draw() override;

	bool IsCleared() const { return !enemy_.IsAlive(); }
private:
	Player player_;
	Enemy enemy_;
};
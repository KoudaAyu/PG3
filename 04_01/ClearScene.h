#pragma once
#include "Scene.h"
class ClearScene : public Scene
{
	public:
	ClearScene();
	~ClearScene();
	void Initialize() override;
	void Update(const char* keys, const char* preKeys) override;
	void Draw() override;
private:
};

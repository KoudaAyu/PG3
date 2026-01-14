#pragma once
#include "Scene.h"
class Title : public Scene
{
public:
	Title();
	~Title();
	void Initialize() override;
	void Update(const char* keys, const char* preKeys) override;
	void Draw() override;

private:
};
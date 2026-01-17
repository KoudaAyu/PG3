#pragma once
#include "Struct.h"

class Enemy
{
public:
	Enemy();
	~Enemy();

	void Initialize();
	void Update();
	void Draw();

	void SetPosition(const IntVector2& pos);
	const IntVector2& GetPosition() const { return position_; }
	void SetAlive(bool alive) { isAlive_ = alive; }
	bool IsAlive() const { return isAlive_; }

	void ToggleHighlight();

	// New getters
	IntVector2 GetSize() const { return size_; }
	bool IsHighlighted() const { return highlighted_; }

private:
	IntVector2 position_ = { 640, 360 };
	IntVector2 size_ = { 30, 30 };
	bool isAlive_ = true;
	bool highlighted_ = false;
};

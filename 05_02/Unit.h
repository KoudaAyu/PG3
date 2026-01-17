#pragma once
#include"Struct.h"

class Selector;

class Unit
{
public:
	Unit() = default;

	void Initialize(int idref);
	void Update();
	void Draw();

	void Move(IntVector2 pos);
	void MoveEnd(Selector* selector);

private:
	IntVector2 map_;
	int mapSize_ = 32;
	int id_ = 0;
	bool isSelected_ = false;

};

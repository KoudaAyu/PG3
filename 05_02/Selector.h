#pragma once
#include"Struct.h"
#include"Unit.h"

class Selector
{
public:
	Selector();

	void Initialize();
	void Update();
	void Draw();

	void Move(IntVector2 pos);
	void SelectUnit();

	int GetSelectMode() const { return selectMode_; }
	Unit* GetSelectedUnitAddress() { return selectedUnit_; }

private:
	IntVector2 map_;
	int mapSize_;

	int selectMode_;

	Unit* unit_;
	Unit* selectedUnit_;
};

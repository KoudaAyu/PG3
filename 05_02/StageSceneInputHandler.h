#pragma once

class IStageSceneCommand;
class Selector;
class Unit;

class StageSceneInputHandler
{
public:
	StageSceneInputHandler();
	void UpdateKeyState();

	IStageSceneCommand* SelectorHandleInput(Selector* selector);
	IStageSceneCommand* UnitHandleInput(Unit* unit);

private:
	char keys_[256] = { 0 };
	char preKeys_[256] = { 0 };
	Selector* selector_ = nullptr;
	Unit* unit_ = nullptr;
};

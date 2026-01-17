#pragma once
#include"ISceneCommand.h"

#include"Struct.h"

class Selector;
class Unit;

class SelectorMoveCommand : public IStageSceneCommand
{
public:
	SelectorMoveCommand(Selector* selector, IntVector2 pos);
	void Execute() override;

private:
	Selector* selector_;
	IntVector2 pos;
};

class SelectUnitCommand : public IStageSceneCommand
{
public:
	SelectUnitCommand(Selector* selector);
	void Execute() override;
private:
	Selector* selector_;
};

class UnitMoveCommand : public IStageSceneCommand
{
public:
	UnitMoveCommand(Unit* unit, IntVector2 pos);
	void Execute() override;

private:
	Unit* unit_;
	IntVector2 pos_;
};

class UnitMoveEndCommand : public IStageSceneCommand
{
public:
	UnitMoveEndCommand(Unit* unit, Selector* selector);
	void Execute() override;

private:
	Unit* unit_;
	Selector* selector_;
};

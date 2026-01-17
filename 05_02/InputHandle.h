#pragma once
#include "Command.h"

class InputHandler
{
public:

	ICommand* HandleInput();

	void AssignMoveLeftCommand2PressKeyA();
	void AssignMoveRightCommand2PressKeyD();
	void AssignMoveUpCommand2PressKeyW();
	void AssignMoveDownCommand2PressKeyS();

private:
	ICommand* pressKeyD_ = nullptr;
	ICommand* pressKeyA_ = nullptr;
	ICommand* pressKeyW_ = nullptr;
	ICommand* pressKeyS_ = nullptr;
	char prevKeys_[256] = {};
};
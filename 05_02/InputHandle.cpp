#include "InputHandle.h"
#include<Novice.h>


ICommand* InputHandler::HandleInput()
{
	char keys[256] = {};
	Novice::GetHitKeyStateAll(keys);

	ICommand* command = nullptr;
	if (keys[DIK_D] && prevKeys_[DIK_D] == 0)
	{
		command = pressKeyD_;
	}
	if (keys[DIK_A] && prevKeys_[DIK_A] == 0)
	{
		command = pressKeyA_;
	}
	if (keys[DIK_W] && prevKeys_[DIK_W] == 0)
	{
		command = pressKeyW_;
	}
	if (keys[DIK_S] && prevKeys_[DIK_S] == 0)
	{
		command = pressKeyS_;
	}
	memcpy(prevKeys_, keys, 256);
	return command;
}

void InputHandler::AssignMoveLeftCommand2PressKeyA()
{
	ICommand* command = new MoveLeftCommand();
	pressKeyA_ = command;
}

void InputHandler::AssignMoveRightCommand2PressKeyD()
{
	ICommand* command = new MoveRightCommand();
	pressKeyD_ = command;
}

void InputHandler::AssignMoveUpCommand2PressKeyW()
{
	ICommand* command = new MoveUpCommand();
	pressKeyW_ = command;
}

void InputHandler::AssignMoveDownCommand2PressKeyS()
{
	ICommand* command = new MoveDownCommand();
	pressKeyS_ = command;
}


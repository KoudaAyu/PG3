#pragma once

class Player;

class ICommand
{
public:
	virtual ~ICommand() = default;
	virtual void Execute(Player& player) = 0;
};

class MoveRightCommand : public ICommand
{
public:
	void Execute(Player& player) override;
};

class MoveLeftCommand : public ICommand
{
public:
	void Execute(Player& player) override;
};

class MoveUpCommand : public ICommand
{
public:
	void Execute(Player& player) override;
};

class MoveDownCommand : public ICommand
{
public:
	void Execute(Player& player) override;
};

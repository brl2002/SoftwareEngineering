#ifndef LIGHTATTACKCOMMAND_H
#define LIGHTATTACKCOMMAND_H

#include "Command.h"
#include <iostream>

class LightAttackCommand : public Command
{
public:
	LightAttackCommand(Character *player, Character *enemy);
	~LightAttackCommand();

	void Execute();

private:
	Character *m_player;
	Character *m_enemy;
};

#endif
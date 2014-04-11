#ifndef ATTACKCOMMAND_H
#define ATTACKCOMMAND_H

#include "Command.h"
#include <iostream>

class HeavyAttackCommand : public Command
{
public:
	HeavyAttackCommand(Character *player, Character *enemy);
	~HeavyAttackCommand();

	void Execute();

private:
	Character *m_player;
	Character *m_enemy;
};

#endif
#ifndef LIGHTATTACKCOMMAND_H
#define LIGHTATTACKCOMMAND_H

#include "Command.h"
#include <iostream>

class LightAttackCommand : public Command
{
public:
	LightAttackCommand();
	~LightAttackCommand();

	void Execute();
};

#endif
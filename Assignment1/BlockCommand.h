#ifndef BLOCKCOMMAND_H
#define BLOCKCOMMAND_H

#include "Command.h"
#include <iostream>

class BlockCommand : public Command
{
public:
	BlockCommand();
	~BlockCommand();

	void Execute();
};

#endif
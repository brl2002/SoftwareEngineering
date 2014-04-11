#ifndef COMMAND_H
#define COMMAND_H

#include "Character.h"

typedef void (Character::*ActionFunc)(Character*);

class Command
{
public:
	virtual ~Command() {}
	virtual void Execute() = 0;
};

#endif
#ifndef COMMAND_H
#define COMMAND_H

#include "Character.h"

class Command
{
public:
	virtual ~Command() {}
	virtual void Execute() = 0;

	void SetBehaviourIndex(int index) { m_behaviourIndex = index; }
	int GetBehaviourIndex() { return m_behaviourIndex; }

protected:
	int m_behaviourIndex;
};

#endif
#pragma once

#include "..\Assignment1\IBehaviour.h"
#include "..\Assignment1\AttributeHandler.h"
#include "CharacterTest.h"

class BehaviourTest : public IBehaviour
{
public:
	BehaviourTest(int health)
	{
		result = false;
		m_behaviourName = "damage";
	}

	~BehaviourTest()
	{
	}

	void TakeAction(Character *agent, Character *subject) {}

	std::string GetName() { return m_behaviourName; }

	void TakeActionTest(CharacterTest *agent, CharacterTest *subject)
	{
		if (agent && subject)
		{
			result = true;
		}
	}

	bool GetResult()
	{
		return result;
	}

private:
	bool result;
};
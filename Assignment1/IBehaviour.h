#ifndef IBEHAVIOUR_H
#define IBEHAVIOUR_H

#include "Character.h"
#include "AttributeHandler.h"
#include <string>

class Character;

class IBehaviour
{
public:
	virtual ~IBehaviour() {}
	virtual void TakeAction(Character *attacker, Character *who) = 0;

	AttributeHandler* GetAttributeHandler() { return m_attHandler; }

protected:
	AttributeHandler *m_attHandler;
	std::string m_behaviourName;
};

class HeavyAttack : public IBehaviour
{
public:
	HeavyAttack(int strength);
	~HeavyAttack();

	void TakeAction(Character *attacker, Character *who);
};

class LightAttack : public IBehaviour
{
public:
	LightAttack(int strength, int accuracy);
	~LightAttack();

	void TakeAction(Character *attacker, Character *who);
};

class Block : public IBehaviour
{
public:
	Block(int armorValue, int agility);
	~Block();

	void TakeAction(Character *attacker, Character *who);
};

class DamageBehaviour : public IBehaviour
{
public:
	DamageBehaviour(int health);
	~DamageBehaviour();

	void TakeAction(Character *attacker, Character *who);
};

#endif
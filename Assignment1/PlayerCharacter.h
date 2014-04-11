#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include "Character.h"

class PlayerCharacter : public Character
{
public:
	PlayerCharacter();
	~PlayerCharacter();

    virtual void Respond(int damage, Character *attacker, Part* attackedPart);

	virtual void TakeAction(Character *enemy);
};

#endif
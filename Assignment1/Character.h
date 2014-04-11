#ifndef CHARACTER_H
#define CHARACTER_H

#include "IBehaviour.h"
#include "IAttribute.h"
#include "Part.h"
#include <string>
#include <vector>
#include <assert.h>

class IBehaviour;
class IAttribute;
class Part;

class Character
{
public:
	Character();
	virtual ~Character();

    virtual void Respond(int damage, Character *attacker, Part* attackedPart) = 0;

    virtual void TakeAction(Character *character) = 0;

    void AddPart(Part *part);
	Part* GetNextPart(int *currentIndex);
	Part* GetPreviousPart(int *currentIndex);
	Part* GetCurrentPart(int currentIndex);

	void SelectNextEnemyPart(Character *enemy);
	void SelectPreviousEnemyPart(Character *enemy);
	void SelectCurrentEnemyPart(Character *enemy);

	Part* GetEnemyPart() { return m_enemyPart; }

	void AddBehaviour(IBehaviour *behaviour);
	
	void SetName(std::string *name) { m_name = *name; }
	std::string GetName() { return m_name; }

	void ResetEnemyTargetIndex() { m_enemyPartIndex = 0; }

protected:
	std::string m_name;

	std::vector<IBehaviour*> m_behaviours;
	std::vector<Part*> m_attackableParts;

    int m_behaviourIndex;

	int m_enemyPartIndex;
	Part* m_enemyPart;
};

#endif
#include "Character.h"

Character::Character() : m_behaviourIndex(0), m_enemyPartIndex(0), m_enemyPart(0)
{
	m_behaviours = std::vector<IBehaviour*>();
}

Character::~Character()
{
	for (int i = 0; i < m_behaviours.size(); ++i)
	{
		delete m_behaviours[i];
	}

	for (int i = 0; i < m_attackableParts.size(); ++i)
	{
		delete m_attackableParts[i];
	}

	m_behaviours.clear();
	m_attackableParts.clear();
}

void Character::AddBehaviour(IBehaviour *behaviour)
{
	m_behaviours.push_back(behaviour);
}

void Character::AddPart(Part *part)
{
	m_attackableParts.push_back(part);
}

Part* Character::GetNextPart(int *currentIndex)
{
	assert(m_attackableParts.size() > 0 && currentIndex >= 0);

	if (*currentIndex < m_attackableParts.size()-1)
	{
		return m_attackableParts[++*currentIndex];
	}

	return m_attackableParts[*currentIndex];
}

Part* Character::GetPreviousPart(int *currentIndex)
{
	assert(m_attackableParts.size() > 0 && currentIndex >= 0);

	if (*currentIndex > 0)
	{
		return m_attackableParts[--*currentIndex];
	}

	return m_attackableParts[*currentIndex];
}

Part* Character::GetCurrentPart(int currentIndex)
{
	assert(m_attackableParts.size() > 0 && currentIndex >= 0 && currentIndex < m_attackableParts.size());

	return m_attackableParts[currentIndex];
}

void Character::SelectNextEnemyPart(Character *enemy)
{
	m_enemyPart = enemy->GetNextPart(&m_enemyPartIndex);
}

void Character::SelectPreviousEnemyPart(Character *enemy)
{
	m_enemyPart = enemy->GetPreviousPart(&m_enemyPartIndex);
}

void Character::SelectCurrentEnemyPart(Character *enemy)
{
	m_enemyPart = enemy->GetCurrentPart(m_enemyPartIndex);
}
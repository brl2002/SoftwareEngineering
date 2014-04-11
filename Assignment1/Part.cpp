#include "Part.h"

Part::Part(int hp, std::string name)
{
	m_damageBehaviour = new DamageBehaviour(hp);
	m_partName = name;
}

Part::~Part()
{
	delete m_damageBehaviour;
}

DamageBehaviour* Part::GetBehaviour()
{
	return m_damageBehaviour;
}
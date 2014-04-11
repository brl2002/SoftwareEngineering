#ifndef PART_H
#define PART_H

#include "IAttribute.h"
#include "IBehaviour.h"
#include <vector>
#include <string>

class DamageBehaviour;

class Part
{
public:
	Part(int hp, std::string name);
	~Part();

	DamageBehaviour* GetBehaviour();

	std::string GetName() { return m_partName; }

private:
	std::string m_partName;
	DamageBehaviour *m_damageBehaviour;
};

#endif
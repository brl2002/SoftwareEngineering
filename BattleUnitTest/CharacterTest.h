#pragma once

#include "AttributeHandlerTest.h"
#include "CharacterTest.h"

class CharacterTest;

class IBehaviourTest
{
public:
	virtual ~IBehaviourTest() {}
	virtual void TakeAction(CharacterTest *agent, CharacterTest *subject) = 0;

	AttributeHandlerTest* GetAttributeHandler() { return m_attHandler; }

protected:
	AttributeHandlerTest *m_attHandler;
	std::string m_behaviourName;
};

class HeavyAttackTest : public IBehaviourTest
{
public:
	HeavyAttackTest(int strength)
	{
		m_attHandler = new AttributeHandlerTest();
	
		StrengthTest *str = new StrengthTest();
		str->SetValue(strength);
		m_attHandler->AddAttribute(str);

		m_behaviourName = "heavy-attack";
	}

	~HeavyAttackTest()
	{
		delete m_attHandler;
	}

	void TakeAction(CharacterTest *agent, CharacterTest *subject)
	{

	}
};

class LightAttackTest : public IBehaviourTest
{
public:
	LightAttackTest(int strength, int accuracy)
	{
		m_attHandler = new AttributeHandlerTest();

		StrengthTest *str = new StrengthTest();
		str->SetValue(strength*0.5f);
		AccuracyTest *acc = new AccuracyTest();
		acc->SetValue(accuracy);
		m_attHandler->AddAttribute(str);
		m_attHandler->AddAttribute(acc);

		m_behaviourName = "light-attack";
	}

	~LightAttackTest()
	{
		delete m_attHandler;
	}

	void TakeAction(CharacterTest *agent, CharacterTest *subject)
	{

	}
};

class BlockTest : public IBehaviourTest
{
public:
	BlockTest(int armorValue, int agility)
	{
		m_attHandler = new AttributeHandlerTest();

		ArmorTest *armor = new ArmorTest();
		armor->SetValue(armorValue);
		AgilityTest *agi = new AgilityTest();
		agi->SetValue(agility);
		m_attHandler->AddAttribute(armor);
		m_attHandler->AddAttribute(agi);

		m_behaviourName = "block";
	}

	~BlockTest()
	{
		delete m_attHandler;
	}

	void TakeAction(CharacterTest *agent, CharacterTest *subject)
	{

	}
};

class DamageBehaviourTest : public IBehaviourTest
{
public:
	DamageBehaviourTest(int health)
	{
		m_attHandler = new AttributeHandlerTest();

		HealthTest *hp = new HealthTest();
		hp->SetValue(health);
		m_attHandler->AddAttribute(hp);

		m_behaviourName = "damage";
	}

	~DamageBehaviourTest()
	{
		delete m_attHandler;
	}

	void TakeAction(CharacterTest *agent, CharacterTest *subject)
	{

	}
};

class PartTest
{
public:
	PartTest(int hp, std::string name)
	{
		m_damageBehaviour = new DamageBehaviourTest(hp);
		m_partName = name;
	}

	~PartTest()
	{
		delete m_damageBehaviour;
	}

	DamageBehaviourTest* GetBehaviour()
	{
		return m_damageBehaviour;
	}

	std::string GetName() { return m_partName; }

private:
	std::string m_partName;
	DamageBehaviourTest *m_damageBehaviour;
};

class CharacterTest
{
public:
	CharacterTest() : m_behaviourIndex(0), m_enemyPartIndex(0), m_enemyPart(0)
	{
		m_behaviours = std::vector<IBehaviourTest*>();
	}

	virtual ~CharacterTest()
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

    virtual void Respond(int damage, IBehaviourTest *attackerBehaviour, PartTest* attackedPart)
	{
		AttributeHandlerTest *handler = attackedPart->GetBehaviour()->GetAttributeHandler();
		int newDmg = handler->ComputeDamage(damage, attackerBehaviour->GetAttributeHandler());
		HealthTest* health = attackedPart->GetBehaviour()->GetAttributeHandler()->GetAttribute<HealthTest*>();
		int hp = health->GetValue();
		hp -= newDmg;

		if (hp > 0)
		{
			health->SetValue(hp);
		}
		else
		{
			health->SetValue(0);
		}
	}

    virtual void TakeAction(CharacterTest *enemy)
	{
		int damage = 0;

		StrengthTest *str = m_behaviours[m_behaviourIndex]->GetAttributeHandler()->GetAttribute<StrengthTest*>();

		if (str)
		{
			damage = str->GetValue() * 2;
		}

		this->m_behaviours[m_behaviourIndex]->TakeAction(this, enemy);
		enemy->Respond(damage, this->m_behaviours[m_behaviourIndex], enemy->GetCurrentPart(m_enemyPartIndex));
	}

    void AddPart(PartTest *part)
	{
		m_attackableParts.push_back(part);
	}

	PartTest* GetNextPart(int *currentIndex)
	{
		assert(m_attackableParts.size() > 0 && currentIndex >= 0);

		if (*currentIndex < m_attackableParts.size()-1)
		{
			return m_attackableParts[++*currentIndex];
		}

		return m_attackableParts[*currentIndex];
	}

	PartTest* GetPreviousPart(int *currentIndex)
	{
		assert(m_attackableParts.size() > 0 && currentIndex >= 0);

		if (*currentIndex > 0)
		{
			return m_attackableParts[--*currentIndex];
		}

		return m_attackableParts[*currentIndex];
	}

	PartTest* GetCurrentPart(int currentIndex)
	{
		assert(m_attackableParts.size() > 0 && currentIndex >= 0 && currentIndex < m_attackableParts.size());

		return m_attackableParts[currentIndex];
	}

	void SelectNextEnemyPart(CharacterTest *enemy)
	{
		m_enemyPart = enemy->GetNextPart(&m_enemyPartIndex);
	}
	void SelectPreviousEnemyPart(CharacterTest *enemy)
	{
		m_enemyPart = enemy->GetPreviousPart(&m_enemyPartIndex);
	}
	void SelectCurrentEnemyPart(CharacterTest *enemy)
	{
		m_enemyPart = enemy->GetCurrentPart(m_enemyPartIndex);
	}

	PartTest* GetEnemyPart() { return m_enemyPart; }

	void AddBehaviour(IBehaviourTest *behaviour)
	{
		m_behaviours.push_back(behaviour);
	}

	void SwitchBehaviour(int index) { m_behaviourIndex = index; }
	
	void SetName(std::string *name) { m_name = *name; }
	std::string GetName() { return m_name; }

	void ResetEnemyTargetIndex() { m_enemyPartIndex = 0; }

protected:
	std::string m_name;

	std::vector<IBehaviourTest*> m_behaviours;
	std::vector<PartTest*> m_attackableParts;

    int m_behaviourIndex;

	int m_enemyPartIndex;
	PartTest* m_enemyPart;
};
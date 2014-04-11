#include "IBehaviour.h"

HeavyAttack::HeavyAttack(int strength)
{
	m_attHandler = new AttributeHandler();
	
	Strength *str = new Strength();
	str->SetValue(strength);
	m_attHandler->AddAttribute(str);

	m_behaviourName = "heavy-attack";
}

HeavyAttack::~HeavyAttack()
{
	delete m_attHandler;
}

void HeavyAttack::TakeAction(Character *attacker, Character *who)
{
	
}

LightAttack::LightAttack(int strength, int accuracy)
{
	m_attHandler = new AttributeHandler();

	Strength *str = new Strength();
	str->SetValue(strength);
	Accuracy *acc = new Accuracy();
	acc->SetValue(accuracy);
	m_attHandler->AddAttribute(str);
	m_attHandler->AddAttribute(acc);

	m_behaviourName = "light-attack";
}

LightAttack::~LightAttack()
{
	delete m_attHandler;
}

void LightAttack::TakeAction(Character *attacker, Character *who)
{

}

Block::Block(int armorValue, int agility)
{
	m_attHandler = new AttributeHandler();

	Armor *armor = new Armor();
	armor->SetValue(armorValue);
	Agility *agi = new Agility();
	agi->SetValue(agility);
	m_attHandler->AddAttribute(armor);
	m_attHandler->AddAttribute(agi);

	m_behaviourName = "block";
}

Block::~Block()
{
	delete m_attHandler;
}

void Block::TakeAction(Character *attacker, Character *who)
{

}

DamageBehaviour::DamageBehaviour(int health)
{
	m_attHandler = new AttributeHandler();

	Health *hp = new Health();
	hp->SetValue(health);
	m_attHandler->AddAttribute(hp);

	m_behaviourName = "damage";
}

DamageBehaviour::~DamageBehaviour()
{
	delete m_attHandler;
}

void DamageBehaviour::TakeAction(Character *attacker, Character *who)
{

}
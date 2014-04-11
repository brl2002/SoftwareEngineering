#include "AttributeHandler.h"

AttributeHandler::AttributeHandler() : m_hp(0), m_armor(0), m_acc(0), m_str(0), m_agi(0)
{
	
}

AttributeHandler::~AttributeHandler()
{
	if (m_hp)
		delete m_hp;
	if (m_armor)
		delete m_armor;
	if (m_acc)
		delete m_acc;
	if (m_str)
		delete m_str;
	if (m_agi)
		delete m_agi;
}

void AttributeHandler::AddAttribute(IAttribute *attribute)
{
	Health *temp_hp = NULL;
	Armor *temp_armor = NULL;
	Accuracy *temp_acc = NULL;
	Strength *temp_str = NULL;
	Agility *temp_agi = NULL;

	temp_hp = dynamic_cast<Health*>(attribute);
	temp_armor = dynamic_cast<Armor*>(attribute);
	temp_acc = dynamic_cast<Accuracy*>(attribute);
	temp_str = dynamic_cast<Strength*>(attribute);
	temp_agi = dynamic_cast<Agility*>(attribute);

	if (temp_hp)
		m_hp = temp_hp;
	if (temp_armor)
		m_armor = temp_armor;
	if (temp_acc)
		m_acc = temp_acc;
	if (temp_str)
		m_str = temp_str;
	if (temp_agi)
		m_agi = temp_agi;
}

int AttributeHandler::ComputeDamage(int initialDmg, AttributeHandler *otherAttHandler)
{
	int damage = initialDmg;

	if (otherAttHandler->m_acc)
	{
		otherAttHandler->m_acc->ModifyInputValue(&damage);

		//If this character has accuracy damage modifier then enemy's agility (if it holds the agi modifier)
		//will affect resulting damage as well
		if (m_agi)
		{
			m_agi->ModifyInputValue(&damage);
		}
	}

	//Strength simply gets added to the damage by a factor
	if (otherAttHandler->m_str)
	{
		otherAttHandler->m_str->ModifyInputValue(&damage);
	}

	//Armor simple gets subtracted from the damage by a factor
	if (otherAttHandler->m_armor)
	{
		otherAttHandler->m_armor->ModifyInputValue(&damage);
	}

	return damage;
}
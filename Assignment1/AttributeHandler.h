#ifndef ATTRIBUTEHANDLER_H
#define ATTRIBUTEHANDLER_H

#include "IAttribute.h"
#include <typeinfo>
#include <vector>

class AttributeHandler
{
public:
	AttributeHandler();
	~AttributeHandler();

	void AddAttribute(IAttribute *attribute);

	template <class Type>
	Type GetAttribute()
	{
		Type temp_hp = NULL;
		Type temp_armor = NULL;
		Type temp_acc = NULL;
		Type temp_str = NULL;
		Type temp_agi = NULL;

		temp_hp = dynamic_cast<Type>(m_hp);
		temp_armor = dynamic_cast<Type>(m_armor);
		temp_acc = dynamic_cast<Type>(m_acc);
		temp_str = dynamic_cast<Type>(m_str);
		temp_agi = dynamic_cast<Type>(m_agi);

		if (temp_hp)
			return temp_hp;
		if (temp_armor)
			return temp_armor;
		if (temp_acc)
			return temp_acc;
		if (temp_str)
			return temp_str;
		if (temp_agi)
			return temp_agi;
	}

	int ComputeDamage(int initialDmg, AttributeHandler *otherAttHandler);

private:
	Health *m_hp;
	Armor *m_armor;
	Accuracy *m_acc;
	Strength *m_str;
	Agility *m_agi;
};

#endif
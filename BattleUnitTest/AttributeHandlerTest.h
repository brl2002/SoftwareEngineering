#pragma once

#include <typeinfo>
#include <vector>

class IAttributeTest
{
public:
	~IAttributeTest() {}
	virtual int GetValue() = 0;
	virtual void SetValue(int value) = 0;
	virtual void ModifyInputValue(int *inputValue) = 0;

protected:
	int m_value;
};

class HealthTest : public IAttributeTest
{
public:
	~HealthTest() {}
	int GetValue() { return m_value; }
	void SetValue(int value) { m_value = value; }
	void ModifyInputValue(int *inputValue)
	{

	}
};

class ArmorTest : public IAttributeTest
{
public:
	~ArmorTest() {}
	int GetValue() { return m_value; }
	void SetValue(int value) { m_value = value; }
	void ModifyInputValue(int *inputValue)
	{
		*inputValue -= m_value * 0.3f;
	}
};

class AccuracyTest : public IAttributeTest
{
public:
	~AccuracyTest() {}
	int GetValue() { return m_value; }
	void SetValue(int value) { m_value = value; }
	void ModifyInputValue(int *inputValue)
	{
		*inputValue += m_value * 0.25f;
	}
};

class StrengthTest : public IAttributeTest
{
public:
	~StrengthTest() {}
	int GetValue() { return m_value; }
	void SetValue(int value) { m_value = value; }
	void ModifyInputValue(int *inputValue)
	{
		*inputValue += m_value * 0.5f;
	}
};

class AgilityTest : public IAttributeTest
{
public:
	~AgilityTest() {}
	int GetValue() { return m_value; }
	void SetValue(int value) { m_value = value; }
	void ModifyInputValue(int *inputValue)
	{
		*inputValue -= m_value * 0.15f;
	}
};

class AttributeHandlerTest
{
public:
	AttributeHandlerTest() : m_hp(0), m_armor(0), m_acc(0), m_str(0), m_agi(0) { }

	~AttributeHandlerTest()
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

	void AddAttribute(IAttributeTest *attribute)
	{
		HealthTest *temp_hp = NULL;
		ArmorTest *temp_armor = NULL;
		AccuracyTest *temp_acc = NULL;
		StrengthTest *temp_str = NULL;
		AgilityTest *temp_agi = NULL;

		temp_hp = dynamic_cast<HealthTest*>(attribute);
		temp_armor = dynamic_cast<ArmorTest*>(attribute);
		temp_acc = dynamic_cast<AccuracyTest*>(attribute);
		temp_str = dynamic_cast<StrengthTest*>(attribute);
		temp_agi = dynamic_cast<AgilityTest*>(attribute);

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

	int ComputeDamage(int initialDmg, AttributeHandlerTest *otherAttHandler)
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

private:
	HealthTest *m_hp;
	ArmorTest *m_armor;
	AccuracyTest *m_acc;
	StrengthTest *m_str;
	AgilityTest *m_agi;
};
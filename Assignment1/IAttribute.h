#ifndef IATTRIBUTE_H
#define IATTRIBUTE_H

class IAttribute
{
public:
	~IAttribute() {}
	virtual int GetValue() = 0;
	virtual void SetValue(int value) = 0;
	virtual void ModifyInputValue(int *inputValue) = 0;

protected:
	int m_value;
};

class Health : public IAttribute
{
public:
	~Health() {}
	int GetValue() { return m_value; }
	void SetValue(int value) { m_value = value; }
	void ModifyInputValue(int *inputValue);
};

class Armor : public IAttribute
{
public:
	~Armor() {}
	int GetValue() { return m_value; }
	void SetValue(int value) { m_value = value; }
	void ModifyInputValue(int *inputValue);
};

class Accuracy : public IAttribute
{
public:
	~Accuracy() {}
	int GetValue() { return m_value; }
	void SetValue(int value) { m_value = value; }
	void ModifyInputValue(int *inputValue);
};

class Strength : public IAttribute
{
public:
	~Strength() {}
	int GetValue() { return m_value; }
	void SetValue(int value) { m_value = value; }
	void ModifyInputValue(int *inputValue);
};

class Agility : public IAttribute
{
public:
	~Agility() {}
	int GetValue() { return m_value; }
	void SetValue(int value) { m_value = value; }
	void ModifyInputValue(int *inputValue);
};

#endif
#include "IAttribute.h"

void Health::ModifyInputValue(int *inputValue)
{

}

void Armor::ModifyInputValue(int *inputValue)
{
	*inputValue -= m_value * 0.3f;
}

void Accuracy::ModifyInputValue(int *inputValue)
{
	*inputValue += m_value * 0.25f;
}

void Strength::ModifyInputValue(int *inputValue)
{
	*inputValue += m_value * 0.5f;
}

void Agility::ModifyInputValue(int *inputValue)
{
	*inputValue -= m_value * 0.15f;
}
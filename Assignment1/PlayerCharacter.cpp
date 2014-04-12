#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter()
{

}

PlayerCharacter::~PlayerCharacter()
{

}

void PlayerCharacter::Respond(int damage, IBehaviour *attackerBehaviour, Part *attackedPart)
{
	AttributeHandler *handler = attackedPart->GetBehaviour()->GetAttributeHandler();
	int newDmg = handler->ComputeDamage(damage, attackerBehaviour->GetAttributeHandler());
	Health* health = attackedPart->GetBehaviour()->GetAttributeHandler()->GetAttribute<Health*>();
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

void PlayerCharacter::TakeAction(Character *enemy)
{
	int damage = 0;

	Strength *str = m_behaviours[m_behaviourIndex]->GetAttributeHandler()->GetAttribute<Strength*>();

	if (str)
	{
		damage = str->GetValue() * 2;
	}

	this->m_behaviours[m_behaviourIndex]->TakeAction(this, enemy);
	enemy->Respond(damage, this->m_behaviours[m_behaviourIndex], enemy->GetCurrentPart(m_enemyPartIndex));
}
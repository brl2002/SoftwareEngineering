#include "LightAttackCommand.h"

LightAttackCommand::LightAttackCommand(Character *player, Character *enemy)
{
	m_player = player;
	m_enemy = enemy;
}

LightAttackCommand::~LightAttackCommand()
{

}

void LightAttackCommand::Execute()
{
	m_player->SwitchBehaviour(m_behaviourIndex);
	m_player->TakeAction(m_enemy);

	std::cout << "Light Attack" << std::endl;
}
#include "HeavyAttackCommand.h"

HeavyAttackCommand::HeavyAttackCommand(Character *player, Character *enemy)
{
	m_player = player;
	m_enemy = enemy;
}

HeavyAttackCommand::~HeavyAttackCommand()
{

}

void HeavyAttackCommand::Execute()
{
	m_player->TakeAction(m_enemy);

	std::cout << "Attack" << std::endl;
}
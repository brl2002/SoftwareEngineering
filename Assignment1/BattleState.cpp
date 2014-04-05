#include "BattleState.h"

BattleState BattleState::m_BattleState;

void BattleState::Init()
{

}

void BattleState::Pause()
{
	std::cout << "BattleState Paused" << std::endl;
}

void BattleState::Resume()
{
	std::cout << "BattleState Resumed" << std::endl;
}

void BattleState::HandleEvents(const SDL_Event &e)
{

}

void BattleState::HandleKeyInput(const Uint8 *keyState)
{

}

void BattleState::Update(float deltaTime)
{

}

void BattleState::Draw()
{

}

void BattleState::PostUpdate()
{

}

void BattleState::Clean()
{


	std::cout << "BattleState Clean Successful" << std::endl;
}
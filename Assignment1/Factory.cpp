#include "Factory.h"

Factory::Factory()
{

}

Factory::~Factory()
{

}

void Factory::CreateNavPlayer()
{
	int textureIndex;
	GameInst::Instance()->GetTextureResource()->LoadTextureWithAlphaKey("../res/timspritesheet.png", &textureIndex, 255, 255, 255);

	m_pNavPlayer = new NavPlayer();
	m_pNavPlayer->BindTexture(GameInst::Instance()->GetTextureResource(), textureIndex);
	m_pNavPlayer->SetDimension(25, 25);
	Collider *col = new Collider(m_pNavPlayer->GetPosition().x, m_pNavPlayer->GetPosition().y, m_pNavPlayer->GetWidth(), m_pNavPlayer->GetHeight());
	m_pNavPlayer->addCollider(col);
	Physics2D::getInstance().addGameObject(m_pNavPlayer);
}

void Factory::DestoryNavPlayer()
{
	delete m_pNavPlayer;
}

NavPlayer* Factory::GetNavPlayer()
{
	return m_pNavPlayer;
}

void Factory::CleanUp()
{
	for (int i = 0; i < m_deleteBuffer.size(); ++i)
	{
		GameObject* gameObject = m_deleteBuffer[i];
		Physics2D::getInstance().Clean(gameObject);
		m_deleteBuffer.erase(m_deleteBuffer.begin()+i);
		delete gameObject;
		gameObject = nullptr;
	}

	m_deleteBuffer.clear();
}

void Factory::Terminate()
{
	//for (int i = 0; i < m_enemies.size(); ++i)
	//{
	//	Enemy* enemy = m_enemies[i];
	//	Physics2D::getInstance().clean(enemy);
	//	m_enemies.erase(m_enemies.begin()+i);
	//	delete enemy;
	//	enemy = nullptr;
	//}
}
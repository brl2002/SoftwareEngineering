#include "GameObject.h"

void GameObject::Load(const char* filename)
{
	m_sprite = new Sprite();

	int textureIndex;
	GameInst::Instance()->GetTextureResource()->LoadTexture(filename, &textureIndex);

	m_sprite->BindTexture(GameInst::Instance()->GetTextureResource(), textureIndex);
}

void GameObject::Update(float deltaTime)
{

}

void GameObject::Draw()
{
	m_sprite->Draw(0, 0);
}

void GameObject::Clean()
{
	delete m_sprite;
}
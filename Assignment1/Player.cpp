#include "Player.h"

void Player::Load(TextureResource *textureResource, char* filename)
{
	GameObject::Load(textureResource, filename);
}

void Player::Update(float deltaTime)
{

}

void Player::Draw()
{
	GameObject::Draw();
}

void Player::Clean()
{
	GameObject::Clean();
}
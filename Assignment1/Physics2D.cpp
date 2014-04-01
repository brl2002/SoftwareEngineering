#include "Physics2D.h"

bool Physics2D::m_debugOn = false;

void Physics2D::ToggleDebug()
{
	m_debugOn = !m_debugOn;
}

void Physics2D::addGameObject(GameObject* gameObject)
{
	for (std::vector<GameObject*>::iterator iter = m_gameObject.begin(); iter != m_gameObject.end(); ++iter)
	{
		if ((*iter) == gameObject)
			return;
	}

	m_gameObject.push_back(gameObject);
}

void Physics2D::Update(float deltaTime)
{
	for (int resetNum = 0; resetNum < m_gameObject.size(); ++resetNum)
	{
		if (m_gameObject[resetNum]->getCollider() != nullptr)
			m_gameObject[resetNum]->getCollider()->colliderReset();
	}

	for (int i = 0; i < m_gameObject.size(); ++i)
	{
		for (int j = 0; j < m_gameObject.size(); ++j)
		{
			if (m_gameObject[i]->IsEnabled() && m_gameObject[j]->IsEnabled() && m_gameObject[i] != m_gameObject[j])
			{
				Collider* collider = m_gameObject[i]->getCollider();
				Collider* otherCollider = m_gameObject[j]->getCollider();

				if (collider != NULL && otherCollider != NULL)
				{
					if (collider->GetFlag() == IS_DYNAMIC)
					{
						if (!collider->IsMoveColliding(m_gameObject[j], deltaTime))
						{
							m_gameObject[i]->Move(deltaTime);
						}
					}
					else if (collider->IsColliding(m_gameObject[j]))
					{
						m_gameObject[i]->onCollision(m_gameObject[j]);
					}
				}
			}
		}
	}
}

void Physics2D::DebugDraw()
{
	if (m_debugOn)
	{
		for (int i = 0; i < m_gameObject.size(); ++i)
		{
			if (m_gameObject[i]->IsEnabled())
			{
				Collider* collider = m_gameObject[i]->getCollider();

				if (collider != nullptr)
				{
					SDL_Color color;

					if (collider->GetCollisionFlag())
					{
						color.a = 255;
						color.b = 255;
						color.g = 0;
						color.r = 255;
					}
					else
					{
						color.a = 0;
						color.b = 0;
						color.g = 255;
						color.r = 255;
					}

					double x =  m_gameObject[i]->GetPosition().x;
					double y =  m_gameObject[i]->GetPosition().y;
					double h_w =  m_gameObject[i]->getCollider()->getWidth() / 2;
					double h_h =  m_gameObject[i]->getCollider()->getHeight() / 2;

					SDL_Rect rect;
					rect.x = x-h_w;
					rect.y = y-h_h;
					rect.w = h_w*2;
					rect.h = h_h*2;

					SDL_SetRenderDrawColor(GameInst::Instance()->GetRenderer(), color.r, color.g, color.b, color.a);
					SDL_RenderDrawRect(GameInst::Instance()->GetRenderer(), &rect);
					SDL_RenderDrawPoint(GameInst::Instance()->GetRenderer(), x, y);
				}
			}
		}
	}
}

void Physics2D::Clean(GameObject* gameObject)
{
	for (int i = 0; i < m_gameObject.size(); ++i)
	{
		if (gameObject == m_gameObject[i])
		{
			m_gameObject.erase(m_gameObject.begin()+i);
		}
	}
}

void Physics2D::Terminate()
{
	m_gameObject.clear();
}
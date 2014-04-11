#include "Sprite.h"
#include "Game.h"
#include <iostream>

Sprite::Sprite() : m_texture(NULL), m_currentAnimTime(0), m_transcoder(NULL), m_animate(false)
{

}

Sprite::~Sprite()
{
	SDL_DestroyTexture(m_texture);
}

void Sprite::BindTexture(TextureResource *textureResource, int bindIndex)
{
	m_texture = textureResource->GetTexture(bindIndex);
}

bool Sprite::Draw(int x, int y)
{
	if (m_texture == NULL)
	{
		return false;
	} 
	
	SDL_Rect src;
	src.x = GetCurrentFrame().x;
	src.y = GetCurrentFrame().y;
	src.w = GetCurrentFrame().w;
	src.h = GetCurrentFrame().h;

	SDL_Rect dst;

	dst.x = x;
	dst.y = y;
	dst.w = GetCurrentFrame().w;
	dst.h = GetCurrentFrame().h;

	SDL_RenderCopy(GameInst::Instance()->GetRenderer(), m_texture, &src, &dst);

	return true;
}

bool Sprite::Draw(int x, int y, int width, int height) 
{
	if (m_texture == NULL)
	{
		return false;
	}

	SDL_Rect src;
	src.x = GetCurrentFrame().x;
	src.y = GetCurrentFrame().y;
	src.w = GetCurrentFrame().w;
	src.h = GetCurrentFrame().h;

	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = width;
	dst.h = height;

	SDL_RenderCopy(GameInst::Instance()->GetRenderer(), m_texture, &src, &dst);

	return true;
}

bool Sprite::Draw(int x, int y, SDL_Rect rect) 
{
	if (m_texture == NULL)
	{
		return false;
	}

	SDL_Rect destR;

	destR.x = x;
	destR.y = y;
	destR.w = rect.w;
	destR.h = rect.h;

	SDL_RenderCopy(GameInst::Instance()->GetRenderer(), m_texture, &rect, &destR);

	return true;
}

void Sprite::BindTranscoder(XMLTranscoder *transcoder)
{
	m_transcoder = transcoder;
}

FrameRect Sprite::GetCurrentFrame() const
{
	if (m_transcoder)
	{
		return *m_transcoder->GetAnimation(m_animNum)->GetFrame(m_frameNum);
	}

	int w, h;
	SDL_QueryTexture(m_texture,NULL, NULL, &w, &h);
	return FrameRect(0, 0, w, h);
}

void Sprite::Play(int animIndex)
{
	assert(animIndex >= 0 && animIndex < m_transcoder->TotalAnimations());

	m_animNum = animIndex;
	m_frameNum = 0;

	if (m_transcoder->GetAnimation(animIndex)->TotalFrames() > 0)
		m_animate = true;
}

void Sprite::Animate(float dt)
{
	if (m_animate)
	{
		if (m_currentAnimTime >= m_animSpeed)
		{
			m_frameNum++;

			if (m_frameNum >= m_transcoder->GetAnimation(m_animNum)->TotalFrames())
			{
				m_frameNum = 0;
			}
			/*else if (m_frameNum < 0)
			{
				m_frameNum = m_transcoder->GetAnimation(m_animNum)->TotalFrames() - 1;
			}*/

			m_currentAnimTime = 0;
		}

		m_currentAnimTime += dt;
	}
}

bool Sprite::IsAnimating()
{
	return m_animate;
}

void Sprite::SetAnimSpeed(float speed)
{
	m_animSpeed = speed;
}

void Sprite::Stop()
{
	m_animate = false;
}
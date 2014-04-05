#ifndef SPRITE_H
#define SPRITE_H

#include "SDL.h"
#include "SDL_image.h"
#include "Error.h"
#include "TextureResource.h"
#include "XMLTranscoder.h"

class TextureResource;

class Sprite
{
public:
	Sprite();
	~Sprite();

	bool Draw(int x, int y);
	bool Draw(int x, int y, int width, int height);
	bool Draw(int x, int y, SDL_Rect rect);

	void BindTexture(TextureResource *textureResource, int bindIndex);

	void BindTranscoder(XMLTranscoder *transcoder);

	FrameRect GetCurrentFrame() const;

	void Play(int animIndex);

	void Animate(float dt);

	bool IsAnimating();

	void SetAnimSpeed(float speed);

private:
	SDL_Texture *m_texture;
	SDL_Renderer *m_renderer;
	TextureResource *m_textureResource;
	int m_bindIndex;

	XMLTranscoder *m_transcoder;
	int m_totalFrames;
	int m_animNum;
	int m_frameNum;
	float m_animSpeed;
	float m_currentAnimTime;
	bool m_animate;
};

#endif
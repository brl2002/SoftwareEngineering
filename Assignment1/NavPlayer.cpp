#include "NavPlayer.h"

NavPlayer::NavPlayer() : GameObject()
{
	m_sprite = new Sprite();

	transcoder = new XMLTranscoder();
	transcoder->Transcode("../res/braid.xml");

	m_sprite->BindTranscoder(transcoder);

	m_sprite->SetAnimSpeed(0.025);
	m_sprite->Play(0);
}

NavPlayer::~NavPlayer()
{
	delete m_sprite;
	delete transcoder;
}

void NavPlayer::Update(float deltaTime)
{
	m_sprite->Animate(deltaTime);
}

void NavPlayer::Draw()
{
	m_sprite->Draw(m_position.x-m_halfWidth, m_position.y-m_halfHeight, m_halfWidth*2, m_halfHeight*2);
}
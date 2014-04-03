#include "NavPlayer.h"

NavPlayer::NavPlayer() : GameObject(), m_x(0), m_y(0)
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
	std::cout << m_x << std::endl;
	m_sprite->Animate(deltaTime);
}

void NavPlayer::Draw()
{
	m_sprite->Draw(m_position.x, m_position.y, m_halfWidth*2, m_halfHeight*2);
}

void NavPlayer::SetTile(int x, int y)
{
	m_x = x;
	m_y = y;

	m_position.x = m_x * Map::GetTileWidth();
	m_position.y = m_y * Map::GetTileHeight();
}
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
	m_sprite->Animate(deltaTime);
}

void NavPlayer::Draw()
{
	m_sprite->Draw(m_position.x, m_position.y, m_halfWidth*2, m_halfHeight*2);
}

void NavPlayer::Move(int x, int y, Map* map)
{
	
	if (m_x + x >= 0 && m_x + x < map->GetWidth())
	{
		m_x += x;

		if (!map->GetXMoving())
			m_position.x += x * Map::GetTileWidth();
	}
	if (m_y + y >= 0 && m_y + y < map->GetHeight())
	{
		m_y += y;

		if (!map->GetYMoving())
			m_position.y += y * Map::GetTileHeight();
	}

	std::cout << "PLAYERX: " << m_x << std::endl;
	std::cout << "MAPWIDTH: " << map->GetWidth() << std::endl;
	std::cout << std::endl;

}
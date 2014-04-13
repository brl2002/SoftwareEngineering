#include "NavPlayer.h"

NavPlayer::NavPlayer() : GameObject(), m_x(0), m_y(0)
{
	m_sprite = new Sprite();

	transcoder = new XMLTranscoder();
	transcoder->Transcode("../res/braid.xml");

	m_sprite->BindTranscoder(transcoder);

	m_sprite->SetAnimSpeed(0.025);
	m_sprite->Play(0);

	m_destination = m_position;
	m_previous = m_position;

	m_time = 0;
	m_moveSpeed = 10;
}

NavPlayer::~NavPlayer()
{
	delete m_sprite;
	delete transcoder;
}

void NavPlayer::Update(float deltaTime)
{
	m_sprite->Animate(deltaTime);

	if (m_position != m_destination)
	{
		m_position = Vector3::lerp(m_previous, m_destination, m_time);
		m_time += deltaTime * m_moveSpeed;

		if (m_time >= 1)
		{
			m_position = m_destination;
			m_time = 0;
		}
	}
}

void NavPlayer::Draw()
{
	m_sprite->Draw(m_position.x, m_position.y, m_halfWidth*2, m_halfHeight*2);
}

void NavPlayer::Move(int x, int y, Map* map)
{
	if (map->CanMoveHere(m_x + x, m_y + y) && m_position == m_destination
		&& !map->IsLerping())
	{
		map->Move(x, y);

		if (m_x + x >= 0 && m_x + x < map->GetWidth())
		{
			m_x += x;

			if (!map->GetXMoving())
			{
				m_previous.x = m_destination.x;
				m_destination.x += x * Map::GetTileWidth();
			}
			else
			{
				m_previous.x = m_destination.x;
			}
		}
		if (m_y + y >= 0 && m_y + y < map->GetHeight())
		{
			m_y += y;

			if (!map->GetYMoving())
			{
				m_previous.y = m_destination.y;
				m_destination.y += y * Map::GetTileHeight();
			}
			else
			{
				m_previous.y = m_destination.y;
			}
		}
	}
}
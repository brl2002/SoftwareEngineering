#include "Animation.h"

Animation::Animation(void)
{
	m_Frames = std::vector<FrameRect*>();
}

Animation::~Animation(void)
{
	for (int i = 0; i < m_Frames.size(); ++i)
	{
		delete m_Frames[i];
	}

	m_Frames.clear();
}

Animation::Animation(const Animation& copy)
{
	this->m_Frames = copy.m_Frames;
}

Animation& Animation::operator=(const Animation& other)
{
	this->m_Frames = other.m_Frames;

	return *this;
}

void Animation::AddFrame(FrameRect *rect)
{
	m_Frames.push_back(rect);
}

FrameRect* Animation::GetFrame(int index) const
{
	assert(index >= 0 && index < m_Frames.size());

	return m_Frames[index];
}

const int Animation::TotalFrames()
{
	return m_Frames.size();
}
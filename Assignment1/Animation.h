#include <assert.h>
#include <vector>

#ifndef ANIMATION_H
#define ANIMATION_H

struct FrameRect
{
	int x;
	int y;
	int w;
	int h;

	FrameRect(int X, int Y, int W, int H) : x(X), y(Y), w(W), h(H) {}

	FrameRect(const FrameRect& copy)
	{
		this->x = copy.x;
		this->y = copy.y;
		this->w = copy.w;
		this->h = copy.h;
	}

	FrameRect& operator=(const FrameRect& other)
	{
		this->x = other.x;
		this->y = other.y;
		this->w = other.w;
		this->h = other.h;

		return *this;
	}
};

class Animation
{
public:
	Animation();
	~Animation();

	Animation(const Animation& copy);

	Animation& operator=(const Animation& other);

	void AddFrame(FrameRect *rect);

	FrameRect* GetFrame(int index) const;

	const int TotalFrames();

private:
	std::vector<FrameRect*> m_Frames;
};

#endif
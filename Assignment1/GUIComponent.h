#ifndef GUICOMPONENT_H
#define GUICOMPONENT_H

#include "SDL.h"

enum GUIType
{
	GUI_BOX,
	GUI_FONT,
	GUI_BUTTON
};

class GUIComponent
{
public:
	virtual ~GUIComponent() {}

	virtual void Init() = 0;

	void SetType(GUIType type) { m_type = type; }
	GUIType GetType() { return m_type; }

	virtual void SetRect(int x, int y, int w, int h);
	SDL_Rect GetRect() { return m_rect; }

	void SetColor(Uint8 r, Uint8 g, Uint8 b);
	void SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	virtual SDL_Color GetColor() { return m_color; }

protected:
	GUIType m_type;

	SDL_Rect m_rect;
	SDL_Color m_color;
};

#endif
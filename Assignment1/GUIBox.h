#ifndef GUIBOX_H
#define GUIBOX_H

#include "GUIComponent.h"
#include <Windows.h>

class GUIBox : public GUIComponent
{
public:
	GUIBox();
	~GUIBox();

	void Init();

	void SetLineColor(Uint8 r, Uint8 g, Uint8 b);
	SDL_Color GetLineColor() { return m_lineColor; }

private:
	SDL_Color m_lineColor;
};

#endif
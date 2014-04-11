#include "GUIBox.h"

GUIBox::GUIBox()
{
	ZeroMemory(&m_lineColor, sizeof(SDL_Color));

	SetType(GUI_BOX);
}

GUIBox::~GUIBox()
{

}

void GUIBox::Init()
{

}

void GUIBox::SetLineColor(Uint8 r, Uint8 g, Uint8 b)
{
	m_lineColor.r = r;
	m_lineColor.g = g;
	m_lineColor.b = b;
}
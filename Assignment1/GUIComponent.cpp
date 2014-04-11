#include "GUIComponent.h"

void GUIComponent::SetRect(int x, int y, int w, int h)
{
	m_rect.x = x;
	m_rect.y = y;
	m_rect.w = w;
	m_rect.h = h;
}

void GUIComponent::SetColor(Uint8 r, Uint8 g, Uint8 b)
{
	m_color.r = r;
	m_color.g = g;
	m_color.b = b;
	m_color.a = 255;
}

void GUIComponent::SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	m_color.r = r;
	m_color.g = g;
	m_color.b = b;
	m_color.a = a;
}
#include "GUIFont.h"

GUIFont::GUIFont()
{
	ZeroMemory(&m_rect, sizeof(SDL_Rect));
	ZeroMemory(&m_color, sizeof(SDL_Color));

	SetType(GUI_FONT);
}

GUIFont::~GUIFont()
{

}

void GUIFont::Init()
{

}

std::string GUIFont::GetText()
{
	return m_text;
}
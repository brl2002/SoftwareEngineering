#include "GUIButton.h"

GUIButton::GUIButton() : m_GUIBox(0), m_GUIFont(0), m_prev(0), m_next(0), m_command(0)
{
	m_rect.x = 1;
	m_rect.y = 1;
	m_rect.w = 1;
	m_rect.h = 1;

	m_highlightedColor.r = 255;
	m_highlightedColor.g = 0;
	m_highlightedColor.b = 0;
	m_highlightedColor.a = 255;

	m_highlighted = false;

	SetType(GUI_BUTTON);
}

GUIButton::~GUIButton()
{
	delete m_GUIBox;
	delete m_GUIFont;
}

void GUIButton::Init()
{

}

void GUIButton::InitBox()
{
	if (!m_GUIBox)
	{
		m_GUIBox = new GUIBox();
	}
}

void GUIButton::InitFont()
{
	if (!m_GUIFont)
	{
		m_GUIFont = new GUIFont();
	}
}

void GUIButton::SetRect(int x, int y, int w, int h)
{
	if (m_GUIBox)
	{
		m_GUIBox->SetRect(x, y, w, h);
	}

	if (m_GUIFont)
	{
		m_GUIFont->SetRect(x+m_rect.x, y+m_rect.y, w-m_rect.w, h-m_rect.h);
	}
}

void GUIButton::SetPadding(int x, int y, int w, int h)
{
	m_rect.x = x;
	m_rect.y = y;
	m_rect.w = w;
	m_rect.h = h;
}

void GUIButton::SetButtonText(std::string text, Uint8 r, Uint8 g, Uint8 b)
{
	m_GUIFont->SetText(text);
	m_GUIFont->SetColor(r, g, b);
}

void GUIButton::SetBackgroundColor(Uint8 r, Uint8 g, Uint8 b)
{
	m_GUIBox->SetColor(r, g, b);
}

void GUIButton::SetButtonLineColor(Uint8 r, Uint8 g, Uint8 b)
{
	m_GUIBox->SetLineColor(r, g, b);
}

SDL_Color GUIButton::GetColor()
{
	return m_highlighted ? m_highlightedColor : m_GUIBox->GetColor();
}

void GUIButton::RegisterNextButton(GUIButton *nextButton)
{
	m_next = nextButton;
	nextButton->m_prev = this;
}

GUIButton* GUIButton::Highlight(GUIButton *startButton)
{
	GUIButton *current = startButton;

	if (current == this)
	{
		current->m_highlighted = true;
	}
	else
	{
		current->m_highlighted = false;
	}

	while (current->GetNext() != NULL)
	{
		current = current->GetNext();

		if (current == this)
		{
			current->m_highlighted = true;
		}
		else
		{
			current->m_highlighted = false;
		}
	}

	return this;
}

GUIButton *GUIButton::GetPrev()
{
	return m_prev;
}

GUIButton *GUIButton::GetNext()
{
	return m_next;
}

void GUIButton::SetCommand(Command *cmd)
{
	m_command = cmd;
}

void GUIButton::ExecuteCommand()
{
	if (m_command)
		m_command->Execute();
}
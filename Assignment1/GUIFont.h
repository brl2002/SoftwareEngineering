#ifndef GUIFONT_H
#define GUIFONT_H

#include "GUIComponent.h"
#include <Windows.h>
#include <string>

class GUIFont : public GUIComponent
{
public:
	GUIFont();

	~GUIFont();

	void Init();

	void SetText(std::string text) { m_text = text; }

	std::string GetText();

private:
	std::string m_text;
};

#endif
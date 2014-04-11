#ifndef GUIBUTTON_H
#define GUIBUTTON_H

#include "GUIComponent.h"
#include "GUIBox.h"
#include "GUIFont.h"
#include "Command.h"

class GUIButton : public GUIComponent
{
public:
	GUIButton();
	~GUIButton();

	void Init();

	void InitBox();
	void InitFont();

	virtual void SetRect(int x, int y, int w, int h) override;

	void SetPadding(int x, int y, int w, int h);

	void SetBackgroundColor(Uint8 r, Uint8 g, Uint8 b);

	void SetButtonLineColor(Uint8 r, Uint8 g, Uint8 b);

	void SetButtonText(std::string text, Uint8 r = 255, Uint8 g = 255, Uint8 b = 255);

	GUIBox *GetBox() { return m_GUIBox; }

	GUIFont *GetFont() { return m_GUIFont; }

	virtual SDL_Color GetColor() override;

	void RegisterNextButton(GUIButton *nextButton);

	GUIButton* Highlight(GUIButton *startButton);

	GUIButton* GetPrev();
	GUIButton* GetNext();

	void SetCommand(Command *cmd);
	void ExecuteCommand();

private:
	bool m_highlighted;

	SDL_Color m_highlightedColor;

	GUIButton *m_prev;
	GUIButton *m_next;

	GUIBox *m_GUIBox;
	GUIFont *m_GUIFont;

	Command *m_command;
};

#endif
#ifndef BATTLESTATE_H
#define BATTLESTATE_H

#include "SDL.h"
#include "Sprite.h"
#include "GameState.h"
#include "GUIFont.h"
#include "GUIBox.h"
#include "GUIButton.h"
#include "HeavyAttackCommand.h"
#include "LightAttackCommand.h"
#include "BlockCommand.h"
#include <vector>
#include "PlayerCharacter.h"

class BattleState : public GameState
{
public:
	void Init();
	void Clean();

	void Pause();
	void Resume();

	void HandleEvents(const SDL_Event &e);
	void HandleKeyInput(const Uint8 *keyState);
	void Update(float deltaTime);
	void Draw();
	void DrawGUI();
	void PostUpdate();

	// Implement Singleton Pattern
	static BattleState* Instance()
	{
		return &m_BattleState;
	}

protected:
	BattleState() {}

	std::vector<GUIComponent*> m_GUIComponents;

private:
	static BattleState m_BattleState;

	GUIButton *m_startButton;
	GUIButton *m_highlightedButton;

	Sprite *m_playerSprite;
	Sprite *m_enemySprite;

	XMLTranscoder *m_playerTranscoder;
	XMLTranscoder *m_enemyTranscoder;

	HeavyAttackCommand *m_playerHeavyAttackCommand;
	LightAttackCommand *m_playerLightAttackCommand;
	BlockCommand *m_playerBlockCommand;

	GUIButton *enemyTargetButton;
	GUIFont *enemyHealthFont;

	PlayerCharacter *playerCharacter;
	PlayerCharacter *enemyCharacter;

private:
	void Attack();
};

#endif
#include "BattleState.h"

BattleState BattleState::m_BattleState;

void BattleState::Init()
{
	int playerStr = 10;
	int playerAcc = 6;
	int playerArmor = 5;
	int playerAgi = 5;
	playerCharacter = new PlayerCharacter();
	playerCharacter->AddPart(new Part(100, "player"));
	playerCharacter->AddBehaviour(new HeavyAttack(playerStr));
	playerCharacter->AddBehaviour(new LightAttack(playerStr, playerAcc));
	playerCharacter->AddBehaviour(new Block(playerArmor, playerAgi));

	enemyCharacter = new PlayerCharacter();
	enemyCharacter->AddPart(new Part(20, "head"));
	enemyCharacter->AddPart(new Part(100, "body"));
	enemyCharacter->AddBehaviour(new HeavyAttack(10));

	playerCharacter->SelectCurrentEnemyPart(enemyCharacter);

	m_GUIComponents = std::vector<GUIComponent*>();

	GUIBox *box1 = new GUIBox();
	box1->SetRect(10, 400, 780, 190);
	box1->SetColor(0, 0, 0);
	box1->SetLineColor(255, 255, 255);

	GUIFont *font1 = new GUIFont();
	font1->SetText("player");
	font1->SetRect(30, 410, 100, 30);
	font1->SetColor(255, 255, 255);

	GUIButton *button1 = new GUIButton();
	button1->InitBox();
	button1->InitFont();
	button1->SetPadding(5, 5, 5, 5);
	button1->SetRect(30, 450, 150, 30);
	button1->SetButtonText("heavy attack", 255, 255, 255);
	button1->SetBackgroundColor(0, 0, 255);
	button1->SetButtonLineColor(255, 255, 255);

	GUIButton *button2 = new GUIButton();
	button2->InitBox();
	button2->InitFont();
	button2->SetPadding(5, 5, 5, 5);
	button2->SetRect(30, 490, 150, 30);
	button2->SetButtonText("light attack", 255, 255, 255);
	button2->SetBackgroundColor(0, 0, 255);
	button2->SetButtonLineColor(255, 255, 255);

	GUIButton *button3 = new GUIButton();
	button3->InitBox();
	button3->InitFont();
	button3->SetPadding(5, 5, 5, 5);
	button3->SetRect(30, 530, 150, 30);
	button3->SetButtonText("block", 255, 255, 255);
	button3->SetBackgroundColor(0, 0, 255);
	button3->SetButtonLineColor(255, 255, 255);

	GUIBox *box2 = new GUIBox();
	box2->SetRect(10, 10, 200, 190);
	box2->SetColor(0, 0, 0);
	box2->SetLineColor(255, 255, 255);

	enemyTargetButton = new GUIButton();
	enemyTargetButton->InitBox();
	enemyTargetButton->InitFont();
	enemyTargetButton->SetPadding(5, 5, 5, 5);
	enemyTargetButton->SetRect(15, 15, 150, 30);
	enemyTargetButton->SetButtonText("enemy", 255, 255, 255);
	enemyTargetButton->SetBackgroundColor(0, 0, 255);
	enemyTargetButton->SetButtonLineColor(255, 255, 255);

	enemyHealthFont = new GUIFont();
	enemyHealthFont->SetText("health");
	enemyHealthFont->SetRect(15, 50, 100, 30);
	enemyHealthFont->SetColor(255, 255, 255);

	m_startButton = button1;
	button1->RegisterNextButton(button2);
	button2->RegisterNextButton(button3);
	m_highlightedButton = button1->Highlight(m_startButton);

	m_GUIComponents.push_back(box1);
	m_GUIComponents.push_back(box2);
	m_GUIComponents.push_back(font1);
	m_GUIComponents.push_back(button1);
	m_GUIComponents.push_back(button2);
	m_GUIComponents.push_back(button3);
	m_GUIComponents.push_back(enemyTargetButton);
	m_GUIComponents.push_back(enemyHealthFont);

	m_playerHeavyAttackCommand = new HeavyAttackCommand(playerCharacter, enemyCharacter);
	m_playerHeavyAttackCommand->SetBehaviourIndex(0);
	button1->SetCommand(m_playerHeavyAttackCommand);
	m_playerLightAttackCommand = new LightAttackCommand(playerCharacter, enemyCharacter);
	m_playerLightAttackCommand->SetBehaviourIndex(1);
	button2->SetCommand(m_playerLightAttackCommand);
	m_playerBlockCommand = new BlockCommand();
	m_playerBlockCommand->SetBehaviourIndex(2);
	button3->SetCommand(m_playerBlockCommand);

	//Player sprite initialization
	m_playerSprite = new Sprite();
	
	int ptextureIndex;
	GameInst::Instance()->GetTextureResource()->LoadTexture("../res/sprites/boy.png", &ptextureIndex);

	m_playerSprite->BindTexture(GameInst::Instance()->GetTextureResource(), ptextureIndex);
	m_playerTranscoder = new XMLTranscoder();
	m_playerTranscoder->Transcode("../res/sprites/boy.sprites");
	m_playerSprite->BindTranscoder(m_playerTranscoder);
	m_playerSprite->Play(0);

	//Enemy sprite initialization
	m_enemySprite = new Sprite();

	int etextureIndex;
	GameInst::Instance()->GetTextureResource()->LoadTexture("../res/sprites/Pokemon.png", &etextureIndex);

	m_enemySprite->BindTexture(GameInst::Instance()->GetTextureResource(), etextureIndex);
	m_enemyTranscoder = new XMLTranscoder();
	m_enemyTranscoder->Transcode("../res/sprites/pokemon.sprites");
	m_enemySprite->BindTranscoder(m_enemyTranscoder);
	m_enemySprite->Play(5);

	//GUI components initialization
	for (int i = 0; i < m_GUIComponents.size(); ++i)
	{
		m_GUIComponents[i]->Init();
	}
}

void BattleState::Pause()
{
	std::cout << "BattleState Paused" << std::endl;
}

void BattleState::Resume()
{
	std::cout << "BattleState Resumed" << std::endl;
}

void BattleState::HandleEvents(const SDL_Event &e)
{
	switch (e.type)
	{
		case SDL_QUIT:
			GameInst::Instance()->Quit();
			break;

		case SDL_KEYDOWN:
			switch(e.key.keysym.sym)
			{
				case SDLK_SPACE:

					break;
				case SDLK_w:
					{
						GUIButton *prev = m_highlightedButton->GetPrev();
						if (prev)
						{
							m_highlightedButton = prev->Highlight(m_startButton);
						}
					}
					break;
				case SDLK_s:
					{
						GUIButton *next = m_highlightedButton->GetNext();
						if (next)
						{
							m_highlightedButton = next->Highlight(m_startButton);
						}
					}
					break;
				case SDLK_q:
					{
						playerCharacter->SelectPreviousEnemyPart(enemyCharacter);
					}
					break;
				case SDLK_e:
					{
						playerCharacter->SelectNextEnemyPart(enemyCharacter);
					}
					break;
				case SDLK_RETURN:
					{
						m_highlightedButton->ExecuteCommand();
					}
					break;
			}
	}
}

void BattleState::HandleKeyInput(const Uint8 *keyState)
{

}

void BattleState::Update(float deltaTime)
{
	enemyTargetButton->SetButtonText(playerCharacter->GetEnemyPart()->GetName(), 255, 255, 255);

	Health *health = playerCharacter->GetEnemyPart()->GetBehaviour()->GetAttributeHandler()->GetAttribute<Health*>();
	enemyHealthFont->SetText(std::to_string(health->GetValue()));
}

void BattleState::Draw()
{
	m_enemySprite->Draw(800/2 - 200, 600/2 - 200, 200, 200);
	m_playerSprite->Draw(800/2 + 100, 600/2 - 100, 250, 250);
}

void BattleState::DrawGUI()
{
	SDL_Renderer *renderer = GameInst::Instance()->GetRenderer();
	TTF_Font *font = GameInst::Instance()->GetFont();

	for (int i = 0; i < m_GUIComponents.size(); ++i)
	{
		GUIType type = m_GUIComponents[i]->GetType();

		switch (type)
		{
		case GUI_BOX:
			{
				GUIBox *boxComp = dynamic_cast<GUIBox*>(m_GUIComponents[i]);
				SDL_Color color = boxComp->GetColor();
				SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
				SDL_RenderFillRect(renderer, &boxComp->GetRect());
				SDL_Color lineColor = boxComp->GetLineColor();
				SDL_SetRenderDrawColor(renderer, lineColor.r, lineColor.g, lineColor.b, lineColor.a);
				SDL_RenderDrawRect(renderer, &boxComp->GetRect());
			}
			break;
		case GUI_FONT:
			{
				GUIFont *fontComp = dynamic_cast<GUIFont*>(m_GUIComponents[i]);
				SDL_Surface *textSurface = TTF_RenderText_Solid(font, fontComp->GetText().c_str(), fontComp->GetColor());
				SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
				SDL_RenderCopy(renderer, textTexture, NULL, &fontComp->GetRect());
				SDL_FreeSurface(textSurface);
				SDL_DestroyTexture(textTexture);
			}
			break;
		case GUI_BUTTON:
			{
				GUIButton *buttonComp = dynamic_cast<GUIButton*>(m_GUIComponents[i]);
				GUIBox *boxComp = dynamic_cast<GUIBox*>(buttonComp->GetBox());
				GUIFont *fontComp = dynamic_cast<GUIFont*>(buttonComp->GetFont());

				if (boxComp)
				{
					SDL_Color color = buttonComp->GetColor();
					SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
					SDL_RenderFillRect(renderer, &boxComp->GetRect());
					SDL_Color lineColor = boxComp->GetLineColor();
					SDL_SetRenderDrawColor(renderer, lineColor.r, lineColor.g, lineColor.b, lineColor.a);
					SDL_RenderDrawRect(renderer, &boxComp->GetRect());
				}

				if (fontComp)
				{
					SDL_Surface *textSurface = TTF_RenderText_Solid(font, fontComp->GetText().c_str(), fontComp->GetColor());
					SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
					SDL_RenderCopy(renderer, textTexture, NULL, &fontComp->GetRect());
					SDL_FreeSurface(textSurface);
					SDL_DestroyTexture(textTexture);
				}
			}
			break;
		}
	}
}

void BattleState::PostUpdate()
{

}

void BattleState::Clean()
{
	for (int i = 0; i < m_GUIComponents.size(); ++i)
	{
		delete m_GUIComponents[i];
	}

	m_GUIComponents.clear();

	delete m_playerHeavyAttackCommand;
	delete m_playerLightAttackCommand;
	delete m_playerBlockCommand;

	std::cout << "BattleState Clean Successful" << std::endl;
}
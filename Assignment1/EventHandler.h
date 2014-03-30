#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "IObserver.h"
#include "IEvent.h"
#include <vector>

class EventHandler : public IObserver
{
public:
	EventHandler();

	~EventHandler();

	//Put any event related game logic here
	void Update(float dt);

	void Draw();

	void NextEvent();

	//Clearing up at the end of a frame
	void Clear();

	//Clear-up memory at the end of game
	void Terminate();

private:
	std::vector<IEvent*> m_events;
	int m_currentEventIndex;
	int m_numEnemies;

private:
	void OnNotify();

};

#endif
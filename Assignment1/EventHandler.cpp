#include "EventHandler.h"

EventHandler::EventHandler()
{
	m_currentEventIndex = 0;

	m_events = std::vector<IEvent*>();
}

EventHandler::~EventHandler()
{

}

void EventHandler::Update(float dt)
{
	if (!m_events.empty())
	{
		m_events[m_currentEventIndex]->Update(dt);
	}
}

void EventHandler::Draw()
{
	if (!m_events.empty())
	{
		m_events[m_currentEventIndex]->Draw();
	}
}

void EventHandler::NextEvent()
{
	
}

void EventHandler::Clear()
{
	if (!m_events.empty())
	{
		for (int i = 0; i < m_events.size(); ++i)
		{
			m_events[i]->Clear();
		}
	}
}

void EventHandler::Terminate()
{
	if (!m_events.empty())
	{
		for (int i = 0; i < m_events.size(); ++i)
		{
			m_events[i]->Terminate();
			delete m_events[i];
		}

		m_events.clear();
	}
}

void EventHandler::OnNotify()
{

}
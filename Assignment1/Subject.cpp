#include "Subject.h"

Subject::~Subject()
{
	for (int i = 0; i < m_observers.size(); ++i)
	{
		delete m_observers[i];
	}

	m_observers.clear();
}

void Subject::AddObserver(IObserver *observer)
{
	m_observers.push_back(observer);
}

void Subject::RemoveObserver(IObserver *observer)
{
	for (std::vector<IObserver*>::iterator iter = m_observers.begin();
		iter != m_observers.end(); ++iter)
	{
		if ((*iter) == observer)
			m_observers.erase(iter);
	}
}
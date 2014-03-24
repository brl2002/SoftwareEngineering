#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

#include "IObserver.h"

class Subject
{
public:
	virtual ~Subject();

	void AddObserver(IObserver *observer);

	void RemoveObserver(IObserver *observer);

private:
	std::vector<IObserver*> m_observers;

protected:
	virtual void Notify() = 0;
};

#endif
#ifndef IOBSERVER_H
#define IOBSERVER_H

class IObserver
{
public:
	virtual ~IObserver() {}
	virtual void OnNotify() = 0;
};

#endif
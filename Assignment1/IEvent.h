#ifndef IEVENT_H
#define IEVENT_H

class IEvent
{
public:
	virtual ~IEvent() {}

	virtual void Init() = 0;

	virtual void Start() = 0;

	virtual void Update(float dt) = 0;

	virtual void Draw() = 0;

	virtual void Stop() = 0;

	virtual void Clear() = 0;

	virtual void Terminate() = 0;
};

#endif
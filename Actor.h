#pragma once



class AActor
{
public:

	AActor();
	~AActor();

	virtual void BeginePlay();
	virtual void Tick();
	virtual void Render();
};


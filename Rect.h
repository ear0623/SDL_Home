#pragma once

#include"Actor.h"

class b2Draw;

class ARect:public AActor
{
public:
	ARect();
	~ARect();

	virtual void BeginePlay()override;
	virtual void Tick()override;
	virtual void Render()override;

	

protected:
	b2Draw* DrawRect;
};


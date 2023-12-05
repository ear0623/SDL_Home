#pragma once

#include"Actor.h"

class b2Draw;
class b2World;

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
	b2BodyDef RectBodyDef;
	b2World* M_World;
	b2Body* DynamicBody;
};


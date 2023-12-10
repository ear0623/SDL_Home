#pragma once

#include "Box2D.h"



class AActor
{
public:

	AActor();
	~AActor();

	virtual void BeginePlay();
	virtual void Tick();
	virtual void Render();
	//

protected:
	b2BodyDef BodyDef;
	b2Body* Body;
	b2PolygonShape Shape;
	b2Vec2 ActorGravity;
	
	
};


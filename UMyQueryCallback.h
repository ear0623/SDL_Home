#pragma once

#include "Box2D.h"

class b2QueryCallback;

class UMyQueryCallback : public b2QueryCallback
{
public:
	b2Vec2 Point;

	UMyQueryCallback();
	virtual ~UMyQueryCallback();
	virtual bool ReportFixture(b2Fixture* fixture)override;

	
};


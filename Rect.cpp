#include "Rect.h"
#include "Box2D.h"
#include <iostream>


ARect::ARect()
{
	
}

ARect::~ARect()
{
}

void ARect::BeginePlay()
{
}

void ARect::Tick()
{
}

void ARect::Render()
{
	__super::Render();

	b2BodyDef RectBodyDef;
	RectBodyDef.type = b2_dynamicBody;
	RectBodyDef.position.Set(0, 20);
	RectBodyDef.angle = 0;
	b2Body* DynamicBody = M_World->CreateBody(&RectBodyDef);

	std::cout << "ARectRender";

}

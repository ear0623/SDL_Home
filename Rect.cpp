#include "Rect.h"
#include "Box2D.h"
#include <iostream>

ARect::ARect()
{
	DynamicBody = M_World->CreateBody(&RectBodyDef);
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

	
	RectBodyDef.type = b2_dynamicBody;
	RectBodyDef.position.Set(0, 20);
	RectBodyDef.angle = 0;
	

	std::cout << "ARectRender";

}

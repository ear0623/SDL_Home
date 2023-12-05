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
	struct b2Vec2 Vector2D = { 50.0f,50.0f };//float32
	float32 Radius = 50.0f;
	const b2Color& Color = {0,255,255,0};//float32
	DrawRect->DrawCircle(Vector2D,Radius,Color);
	std::cout << "ARectRender";
}

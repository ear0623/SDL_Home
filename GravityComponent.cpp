#include "GravityComponent.h"
#include "Box2D.h"

AGravityComponent::AGravityComponent()
{
	Gravity2d = { 0.0f,600.0f };
	BodyDef.position.Set(0.0f, 550.0f);
	Shape = nullptr;
	Body = nullptr;
	GravityWorld = new b2World(Gravity2d);
}

AGravityComponent::~AGravityComponent()
{
	if (Shape != nullptr)
	{
		delete Shape;
	}
	if (GravityWorld != nullptr)
	{
		delete GravityWorld;
	}

}

void AGravityComponent::SetGravity(const b2Vec2& NewGravity)
{
	Gravity2d = NewGravity;

	if (Body)
	{
		Body->SetGravityScale(Gravity2d.Length());
	}
	else
	{
	 
	}
}

void AGravityComponent::SetShpae(const b2PolygonShape& setshape)
{
	Shape = new b2PolygonShape(setshape);
}

void AGravityComponent::CreateBox(float32 SetX, float32 SetY, float32 Size_Wide, float32 Size_Height, float32 Friction_Force,b2BodyType BodyType)
{
	BodyDef.position.Set(SetX, SetY);
	BodyDef.type = BodyType;
	Body = GravityWorld->CreateBody(&BodyDef);
	if (Shape == nullptr)
	{
		Shape = new b2PolygonShape();
	}
	
	Shape->SetAsBox(Size_Wide,Size_Height);
	Body->CreateFixture(Shape, Friction_Force);
}

void AGravityComponent::CreateShape(float32 SetX, float32 SetY, float32 Size_Wide, float32 Size_Height, float32 Friction_Force)
{
	BodyDef.position.Set(SetX, SetY);

	Body = GravityWorld->CreateBody(&BodyDef);
	if (Shape == nullptr)
	{
		Shape = new b2PolygonShape();
	}

	Shape->SetAsBox(Size_Wide, Size_Height);
	Body->CreateFixture(Shape, Friction_Force);
}


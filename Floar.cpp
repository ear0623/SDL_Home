#include "Floar.h"
#include "SimpleEngine.h"

AFloar::AFloar()
{
	ActorGravity = { 0.0f,600.0f };
	BodyDef.position.Set(0.0f, 0.0f);
	b2World GravityWorld(ActorGravity);

	BodyDef.position.Set(0.0f, 550.0f);
	Shape.SetAsBox(50.0f, 10.0f);
	Body.CreateFixture(&Body, 0.0f);
}

AFloar::~AFloar()
{
}

void AFloar::Render()
{
	AActor::Render();
	Body = ActorGravity.create CreateBody(&BodyDef);
}

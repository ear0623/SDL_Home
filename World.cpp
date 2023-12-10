#include "World.h"
#include <algorithm>
#include "Actor.h"
#include "Box2D.h"

UWorld::UWorld()
{
	Gravity = { 0.0f,600.0f };
}

UWorld::~UWorld()
{
	for (auto Actor : Actors)
	{
		delete Actor;
	}
	Actors.clear();
}

void UWorld::SpawnActor(AActor* actor)
{
	if (actor)
	{
		Actors.push_back(actor);
	}
}

void UWorld::Tick()
{
	for ( auto Actor : Actors)
	{	
		Actor->Tick();
	}
}

void UWorld::Render()
{
	for (auto Actor : Actors)
	{
		Actor->Render();
	}
}

void UWorld::SortRenderOrder()
{
}

void UWorld::SetGravity()
{
	b2World GravityWorld(Gravity);
}


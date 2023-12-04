#include "World.h"
#include <algorithm>
#include "Actor.h"

UWorld::UWorld()
{
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
	for (const auto& Actor : Actors)
	{
		if (Actor)
		{
			Actor->Tick();
		}
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

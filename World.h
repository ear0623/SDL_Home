#pragma once

#include <vector>
#include "Box2D.h"

class AActor;
//class b2World;

class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	void SpawnActor(AActor* actor);
	void Tick();
	void Render();

	void SortRenderOrder();
	void SetGravity();
	//get
	const std::vector<AActor*>& GetAllactors() { return Actors; }
	//
	b2Vec2 Gravity;

protected:
	std::vector<AActor*> Actors;
	
};


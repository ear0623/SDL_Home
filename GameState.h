#pragma once
#include "Actor.h"
class AGameState : public AActor
{
public:
	AGameState();
	virtual ~AGameState();

	virtual void Tick() override;
	virtual void Render() override;

};


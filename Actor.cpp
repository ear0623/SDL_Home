#include "Actor.h"
#include <iostream>
#include "SDL.h"
#include "SimpleEngine.h"


AActor::AActor()
{
	ActorGravity = { 0.0f,600.0f };
	BodyDef.position.Set(0.0f, 0.0f);
	b2World GravityWorld(ActorGravity);
}

AActor::~AActor()
{

}

void AActor::BeginePlay()
{

}

void AActor::Tick()
{

}

void AActor::Render()
{
	
	//
	std::cout << "AActorRender";
	const SDL_Rect Rect = { 0,0,50,50 };
	SDL_RenderDrawRect(GEngine->GetMyRenderer(), &Rect);
}

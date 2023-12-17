#include "Actor.h"
#include <iostream>
#include "SDL.h"
#include "SimpleEngine.h"


AActor::AActor()
{
	
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

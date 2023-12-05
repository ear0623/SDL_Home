#include "SimpleEngine.h"
#include "World.h"
#include "SDL.h"
#include "Box2D.h"
#include "Actor.h"

#pragma comment(lib,"SDL2")
#pragma comment(lib, "SDL2main")


FSimpleEngine* FSimpleEngine::Instance = nullptr;

void FSimpleEngine::Input()
{
	SDL_PollEvent(&MyEvent);
}

void FSimpleEngine::Tick()
{
	GetWorld()->Tick();
}

void FSimpleEngine::Render()
{
	GetWorld()->Render();
}

void FSimpleEngine::LoadActor(int NewX, int NewY, char Actor)
{

}

FSimpleEngine::FSimpleEngine()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	MyWindow = SDL_CreateWindow("GaGaGam", 200, 200, 800, 600, SDL_WINDOW_OPENGL);
	MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
	Init();
}

FSimpleEngine::~FSimpleEngine()
{
	Term();
	SDL_Quit();
}

void FSimpleEngine::Init()
{
	bIsRunning = true;
	World = new UWorld();
}

void FSimpleEngine::Run()
{
	

	while (bIsRunning)
	{
		Input();
		switch (MyEvent.type)
		{
		case SDL_QUIT:
			bIsRunning = false;
			break;

		case SDL_KEYDOWN:
			if (MyEvent.key.keysym.sym == SDLK_ESCAPE)
			{
				bIsRunning = false;
			}
			break;
		}

		SDL_SetRenderDrawColor(GEngine->MyRenderer, 255, 255, 255, 0);
		SDL_RenderClear(GEngine->MyRenderer);
		Tick();
		GetWorld()->SpawnActor(MakeActor);
		Render();
		SDL_RenderPresent(GEngine->MyRenderer);

		
		
	}
}

void FSimpleEngine::Stop()
{
	bIsRunning = false;
}

void FSimpleEngine::Term()
{
	delete World;
	//SDL_RenderClear;
}

void FSimpleEngine::LoadLevel(std::string FileName)
{
	
}

FSimpleEngine* FSimpleEngine::GetInstance()
{
	return Instance ? Instance : (Instance = new FSimpleEngine());
}

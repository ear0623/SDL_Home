#include "SimpleEngine.h"
#include "World.h"
#include "SDL.h"

FSimpleEngine* FSimpleEngine::Instance = nullptr;

void FSimpleEngine::Input()
{
}

void FSimpleEngine::Tick()
{
}

void FSimpleEngine::Render()
{
	
}

void FSimpleEngine::LoadActor(int NewX, int NewY, char Actor)
{
}

FSimpleEngine::FSimpleEngine()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	Window = SDL_CreateWindow("GaGaGam", 200, 200, 800, 600, SDL_WINDOW_OPENGL);
	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
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

	}
}

void FSimpleEngine::Stop()
{
	bIsRunning = false;
}

void FSimpleEngine::Term()
{
	delete World;
}

void FSimpleEngine::LoadLevel(std::string FileName)
{
}

FSimpleEngine* FSimpleEngine::GetInstance()
{
	return Instance ? Instance : (Instance = new FSimpleEngine());
}

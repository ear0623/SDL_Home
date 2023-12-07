#include "SimpleEngine.h"
#include "World.h"
#include "SDL.h"
#include "Box2D.h"
#include "Actor.h"
#include <iostream>
#include <fstream>

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
	
	b2Vec2 Gravity = { 0.0f,-9.8f };
	b2World GravityWorld(Gravity);
	

	b2BodyDef GroundBodyDef;
	GroundBodyDef.position.Set(400.0f, 500.0f);
	b2Body* Groundbody = GravityWorld.CreateBody(&GroundBodyDef);

	b2PolygonShape GroundBox;
	GroundBox.SetAsBox(400.0f, 10.0f);
	Groundbody->CreateFixture(&GroundBox, 0.0f);

	b2Vec2 RectPosition = Groundbody->GetPosition();
	SDL_Rect Rect = { static_cast<int>(RectPosition.x),(int)RectPosition.y,100,100};

	while (bIsRunning)
	{
		Tick();
		Input();
		Render();
		SDL_SetRenderDrawColor(GEngine->MyRenderer, 255, 255, 255, 255);
		SDL_RenderClear(GEngine->MyRenderer);
	
		SDL_SetRenderDrawColor(GEngine->MyRenderer, 255, 0, 0, 255);
		SDL_RenderFillRect(GEngine->MyRenderer,&Rect);
		SDL_RenderPresent(GEngine->MyRenderer);
		GravityWorld.Step(1.0f / 60.0f, 6, 2);
		switch (MyEvent.type)
		{

		case SDL_QUIT:
			bIsRunning = false;
			break;

		case SDL_KEYDOWN:
			if (MyEvent.key.keysym.sym == SDLK_ESCAPE) { bIsRunning = false; }
			
			if (MyEvent.key.keysym.sym == SDLK_f)
			{
				
				std::cout << "SDLK_F";
			}
			break;
		}
		
		

	}
}

void FSimpleEngine::Stop()
{
	bIsRunning = false;
}

void FSimpleEngine::Term()
{
	delete World;
	SDL_RenderClear(MyRenderer);
}

void FSimpleEngine::LoadLevel(std::string FileName)
{
	Term();
	Init();

	int Y = 0;
	std::string line;
	std::ifstream file(FileName);
	if (file.is_open())
	{
		while (std::getline(file,line))
		{
			for (int X = 0; X < line.length(); ++X)
			{
				LoadActor(X, Y, line[X]);
			}
			Y++;
		}
		file.close();
	}
	else
	{
		Stop();
	}
}

FSimpleEngine* FSimpleEngine::GetInstance()
{
	return Instance ? Instance : (Instance = new FSimpleEngine());
}

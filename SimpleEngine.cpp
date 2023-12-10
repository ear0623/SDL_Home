#include "SimpleEngine.h"
#include "World.h"
#include "SDL.h"
#include "Box2D.h"
#include "Actor.h"
#include <iostream>
#include <fstream>
#include "UMyQueryCallback.h"

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
	World->SetGravity();
	
	//官蹿积己
	b2BodyDef GroundBodyDef;
	GroundBodyDef.position.Set(0.0f, 550.0f);
	b2Body* Groundbody = GravityWorld.CreateBody(&GroundBodyDef);

	b2PolygonShape GroundBox;
	GroundBox.SetAsBox(50.0f, 10.0f);
	Groundbody->CreateFixture(&GroundBox, 0.0f);

	SDL_Rect GroundRect{ (int)Groundbody->GetPosition().x,(int)Groundbody->GetPosition().y,50,10 };

	SDL_SetRenderDrawColor(GEngine->MyRenderer, 255, 0, 0, 255); 
	SDL_RenderFillRect(GEngine->MyRenderer, &GroundRect); 
	
	//惑磊积己
	b2BodyDef BoxBodyDef;
	BoxBodyDef.type = b2_dynamicBody;
	BoxBodyDef.position.Set(0.0f, 4.0f);
	b2Body* BoxBody = GravityWorld.CreateBody(&BoxBodyDef);

	b2PolygonShape BoxBodyShape;
	BoxBodyShape.SetAsBox(10.0f, 10.0f);
	BoxBody->CreateFixture(&BoxBodyShape, 1.0f);
	

	while (bIsRunning)

	{
		GravityWorld.Step(1.0f / 60.0f, 6, 2);
		Tick();
		Input();
		Render();
		
		switch (MyEvent.type)
		{
		case SDL_KEYDOWN:
			if (MyEvent.key.keysym.sym == SDLK_ESCAPE) { bIsRunning = false; }
			else if (MyEvent.key.keysym.sym == SDLK_d) { std::cout << "D";}
			break;
		case SDL_MOUSEBUTTONDOWN:
			if(MyEvent.button.button == SDL_BUTTON_LEFT)
			{
				int MouseX;
				int MouseY;
				SDL_GetMouseState(&MouseX, &MouseY);

				b2Vec2 WorldPos(static_cast<float>(MouseX), static_cast<float>(MouseY));
				b2AABB aabb;
				b2Vec2 ADD(0.001f, 0.001f);
				aabb.lowerBound = WorldPos - ADD;
				aabb.upperBound = WorldPos + ADD;

				UMyQueryCallback callback;
				callback.Point = WorldPos;
				std::cout << "Click";

				GravityWorld.QueryAABB(&callback, aabb);

				b2BodyDef SpawnBoxBodyDef;
				SpawnBoxBodyDef.type = b2_dynamicBody;
				SpawnBoxBodyDef.position = WorldPos;

				b2PolygonShape SpawnBoxBodyShape;
				SpawnBoxBodyShape.SetAsBox(10.0f, 10.0f);
				
				b2FixtureDef RedBoxFixtureDef;
				RedBoxFixtureDef.shape = &SpawnBoxBodyShape;
				RedBoxFixtureDef.density = 1.0f;
				RedBoxFixtureDef.friction = 0.3f;

				b2Body* SpawnBoxBody = GravityWorld.CreateBody(&SpawnBoxBodyDef);
				SpawnBoxBody->CreateFixture(&RedBoxFixtureDef);
				SDL_SetRenderDrawColor(GEngine->MyRenderer, 255, 0, 0, 255);
				SDL_Rect SpawnRect = { static_cast<int>(WorldPos.x), (int)(WorldPos.y), 10, 10 };
				std::cout << WorldPos.x << " , " << WorldPos.y << std::endl;
				SDL_RenderFillRect(GEngine->MyRenderer, &SpawnRect);
				SDL_RenderPresent(GEngine->MyRenderer);
				break;
			}

		case SDL_QUIT:
			bIsRunning = false;
			break;
		}
		b2Vec2 RectPosition = BoxBody->GetPosition();
		SDL_SetRenderDrawColor(GEngine->MyRenderer, 255, 255, 255, 255);
		SDL_RenderClear(GEngine->MyRenderer);
		SDL_SetRenderDrawColor(GEngine->MyRenderer, 255, 0, 0, 255);
		SDL_Rect Rect = { static_cast<int>(RectPosition.x),(int)(RectPosition.y),10,10 };
		SDL_RenderFillRect(GEngine->MyRenderer, &Rect);
		SDL_RenderFillRect(GEngine->MyRenderer, &GroundRect);
		
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

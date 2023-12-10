#pragma once

#include <vector>
#include <string>
#include "SDL.h"
#include "Box2D.h"

#pragma comment(lib,"SDL2")
#pragma comment(lib,"SDL2main")

#define GEngine FSimpleEngine::GetInstance()

class UWorld;
class AGameMode;
class AGameState;
class AActor;
struct b2Vec2;
class b2World;

class FSimpleEngine
{
	virtual ~FSimpleEngine();

public:
	void Init();
	void Run();
	void Stop();
	void Term();

	void LoadLevel(std::string FileName);
	//
	static FSimpleEngine* GetInstance();
	static AGameMode* GetGameMode() { return GetInstance()->GameMode;}
	static AGameState* GetGameState() { return GetInstance()->GameState;}
	//
	//
	inline UWorld* GetWorld() const { return World; }
	inline SDL_Renderer* GetMyRenderer() const { return MyRenderer; }
	inline SDL_Window* GetMyWindow() const { return MyWindow; }
	//
	AActor* MakeActor;

protected:
	bool bIsRunning;
	SDL_Window* MyWindow;
	SDL_Renderer* MyRenderer;
	SDL_Event MyEvent;
	UWorld* World;
	Uint64 DeltaSeconds;
	Uint64 LastTime;
	
	

	static FSimpleEngine* Instance;
	static AGameMode* GameMode;
	static AGameState* GameState;

	void Input();
	void Tick();
	void Render();
	void LoadActor(int NewX, int NewY, char Actor);

private:
	FSimpleEngine();
};


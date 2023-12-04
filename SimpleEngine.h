#pragma once

#include <vector>
#include <string>
#include "SDL.h"

#pragma comment(lib,"SDL2")
#pragma comment(lib,"SDL2main")

class UWorld;
class AGameMode;
class AGameState;

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

protected:
	bool bIsRunning;
	UWorld* World;
	SDL_Window* Window;
	SDL_Renderer* Renderer;
	SDL_Event MyEvent;

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


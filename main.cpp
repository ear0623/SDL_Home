#include "SDL.h"
#include "Box2D.h"
#include "SimpleEngine.h"
#include <memory>

#pragma comment(lib,"SDL2main.lib")
#pragma comment(lib,"SDL2.lib")

int main(int argc,char* argv[])
{

	FSimpleEngine* SimpleEngine = FSimpleEngine::GetInstance();
	SimpleEngine->Run();

	

	return 0;
}
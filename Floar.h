#pragma once
#include "Actor.h"


class b2World;

class AFloar : public AActor
{
public:
	AFloar();
	virtual ~AFloar();
	//
	virtual void Render()override;
	
protected:

	


private:



	SDL_Rect GroundRect{ (int)Groundbody->GetPosition().x,(int)Groundbody->GetPosition().y,50,10 };

	SDL_SetRenderDrawColor(GEngine->MyRenderer, 255, 0, 0, 255);
	SDL_RenderFillRect(GEngine->MyRenderer, &GroundRect);

};


#pragma once
#include "Actor.h"
#include "SDL_mixer.h"

class ASoundActor : public AActor
{
public:
	ASoundActor();
	virtual ~ASoundActor();

	int Volume;

protected:
	Mix_Music* Music;
};


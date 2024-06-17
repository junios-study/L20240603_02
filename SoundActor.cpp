#include "SoundActor.h"

ASoundActor::ASoundActor()
{
	Music = Mix_LoadMUS("data/bgm.mp3");
	//Mix_LoadWAV()

	if (Mix_PlayMusic(Music, -1) == -1)
	{
		int a = 0;
	}
}

ASoundActor::~ASoundActor()
{
	Mix_FreeMusic(Music);
}

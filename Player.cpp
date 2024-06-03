#include "Player.h"

APlayer::APlayer()
{
	//AActor::AActor();
	X = 1;
	Y = 1;
	Shape = ' ';
}

APlayer::APlayer(int NewX, int NewY, char NewShape)
{
//	AActor::AActor(NewX, NewY, NewShape);
	X = NewX;
	Y = NewY;
	Shape = NewShape;
}

APlayer::~APlayer()
{
}

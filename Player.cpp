#include "Player.h"
#include "Engine.h"

APlayer::APlayer()
{
	//AActor::AActor();
	X = 1;
	Y = 1;
	Shape = ' ';
	Layer = 4;
	IsCollision = true;
	R = 0;
	G = 255;
	B = 0;

	ColorKeyR = 255;
	ColorKeyG = 0;
	ColorKeyB = 255;
}

APlayer::APlayer(int NewX, int NewY, char NewShape)
{
	//	AActor::AActor(NewX, NewY, NewShape);
	X = NewX;
	Y = NewY;
	Shape = NewShape;
	Layer = 4;
	IsCollision = true;

	R = 0;
	G = 255;
	B = 0;

	ColorKeyR = 255;
	ColorKeyG = 0;
	ColorKeyB = 255;

	Filename = "data/player.bmp";
	LoadTexture(Filename);


}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	switch (UEngine::KeyCode)
	{
	case 'W':
	case 'w':
		if (Predict(X, Y - 1))
		{
			Y--;
		}
		break;
	case 'S':
	case 's':
		if (Predict(X, Y + 1))
		{
			Y++;
		}
		break;
	case 'A':
	case 'a':
		if (Predict(X - 1, Y))
		{
			X--;
		}
		break;
	case 'D':
	case 'd':
		if (Predict(X + 1, Y))
		{
			X++;
		}
		break;
	}
}

void APlayer::Render()
{
	SDL_Rect MyRect;
	MyRect.x = X * SpriteSize;
	MyRect.y = Y * SpriteSize;
	MyRect.w = SpriteSize;
	MyRect.h = SpriteSize;

	int SpriteSizeX = MySurface->w / 5;
	int SpriteSizeY = MySurface->h / 5;
	SDL_Rect SrcRect;

	SrcRect.x = SpriteSizeX * SpirteIndexX;
	SrcRect.y = SpriteSizeY * SpirteIndexY;
	SrcRect.w = SpriteSizeX;
	SrcRect.h = SpriteSizeY;
	ElapsedTime += GEngine->GetWorldDeltaSeconds();
	if (ElapsedTime >= 200)
	{
		SpirteIndexX++;
		SpirteIndexX = SpirteIndexX % 5;
		ElapsedTime = 0;
	}

	if (MyTexture)
	{
		SDL_RenderCopy(GEngine->MyRenderer,
			MyTexture,
			&SrcRect,
			&MyRect);
	}
	else
	{
		SDL_RenderFillRect(GEngine->MyRenderer, &MyRect);
	}
}

bool APlayer::Predict(int PredictX, int PredictY)
{
	for (auto OtherActor : GEngine->Actors)
	{
		if (this == OtherActor)
		{
			continue;
		}

		if (OtherActor->IsCollision == false)
		{
			continue;
		}

		if (PredictX == OtherActor->X && PredictY == OtherActor->Y)
		{
			return false;
		}
	}


	return true;
}

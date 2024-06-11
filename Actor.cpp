#include "Actor.h"
#include "SDL.h"
#include "Engine.h"

#include <iostream>
#include <windows.h>

AActor::AActor()
{
	X = 0;
	Y = 0;
	Shape = ' ';
	Layer = 0;
	IsCollision = false;
	R = 0;
	G = 0;
	B = 0;
	SpriteSize = 60;
}

AActor::AActor(int NewX, int NewY, char NewShape, int NewLayer)
{
	X = NewX;
	Y = NewY;
	Shape = NewShape;
	Layer = NewLayer;
	IsCollision = false;
	R = 0;
	G = 0;
	B = 0;
	SpriteSize = 60;
}

AActor::~AActor()
{
}

void AActor::Tick()
{
}

void AActor::Render()
{
	//text 
	COORD Cur;
	Cur.X = X;
	Cur.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

	std::cout << Shape;

	//2D
	SDL_SetRenderDrawColor(GEngine->MyRenderer, R, G, B, 1);
	//SDL_RenderDrawPoint(GEngine->MyRenderer, X, Y);
	SDL_Rect MyRect;
	MyRect.x = X * SpriteSize;
	MyRect.y = Y * SpriteSize;
	MyRect.w = SpriteSize;
	MyRect.h = SpriteSize;

	SDL_RenderFillRect(GEngine->MyRenderer, &MyRect);
}

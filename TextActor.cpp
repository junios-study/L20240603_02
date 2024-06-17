#include "TextActor.h"
#include "Engine.h"

ATextActor::ATextActor()
{
	X = 100;
	Y = 100;

	FontSize = 60;

	Font = TTF_OpenFont("data/NanumGothicCoding.ttf", FontSize);

	Text = "Hell0 World!";
	R = 0;
	G = 0;
	B = 0;

	SDL_Color Color;
	Color.r = R;
	Color.g = G;
	Color.b = B;
	MySurface = TTF_RenderText_Solid(Font, Text.c_str(), Color);
	MyTexture = SDL_CreateTextureFromSurface(
		GEngine->MyRenderer, MySurface);

	Layer = 100;
}

ATextActor::~ATextActor()
{
	SDL_FreeSurface(MySurface);
	SDL_DestroyTexture(MyTexture);
	TTF_CloseFont(Font);
}

void ATextActor::Render()
{
	int Width = 0;
	int Height = 0;
	SDL_QueryTexture(MyTexture, nullptr, nullptr,
		&Width, &Height);

	SDL_Rect DestinationRect;
	DestinationRect.x = X;
	DestinationRect.y = Y;
	DestinationRect.w = Width;
	DestinationRect.h = Height;

	SDL_RenderCopy(GEngine->MyRenderer, MyTexture,
		nullptr, &DestinationRect);
}

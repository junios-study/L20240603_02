#include "Engine.h"
#include <conio.h>
#include "Actor.h"

UEngine::UEngine()
{
	IsRunning = true;
}

UEngine::~UEngine()
{
}

void UEngine::SpawnActor(AActor* NewActor)
{
	Actors.push_back(NewActor);
}

void UEngine::Run()
{
	while (IsRunning)
	{
		Input();
		Tick();
		Render();
	}
}

void UEngine::Input()
{
	_getch();
}

void UEngine::Tick()
{
	for (auto Actor : Actors)
	{
		Actor->Tick();
	}
}

void UEngine::Render()
{
	for (auto Actor : Actors)
	{
		Actor->Render();
	}
}

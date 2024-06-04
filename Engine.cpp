#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <conio.h>

#include "Engine.h"
#include "Actor.h"
#include "Player.h"
#include "Wall.h"

using namespace std;

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

void UEngine::LoadLevel(std::string MapFilename)
{
	char Map[256];

	ifstream InputFile;

	InputFile.open(MapFilename);

	int Y = 0;
	while (InputFile.getline(Map, 80))
	{
		for (int X = 0; X < strlen(Map); ++X)
		{
			if (Map[X] == 'P')
			{
				SpawnActor(new APlayer(X, Y));
			}
			else if (Map[X] == '*')
			{
				SpawnActor(new AWall(X, Y));
			}
		}
		Y++;
	}

	InputFile.close();
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

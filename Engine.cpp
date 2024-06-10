#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <conio.h>

#include "Engine.h"
#include "Actor.h"
#include "Player.h"
#include "Wall.h"
#include "Floor.h"
#include "Goal.h"
#include "Monster.h"

using namespace std;

int UEngine::KeyCode = 0;
UEngine* UEngine::Instance = nullptr;

UEngine::UEngine()
{
	Init();
}

UEngine::~UEngine()
{
	Term();
}

void UEngine::Init()
{
	IsRunning = true;
}

void UEngine::Term()
{
	for (auto Actor : Actors)
	{
		delete Actor;
	}

	Actors.clear();
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
	Term();

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
				SpawnActor(new AFloor(X, Y));
			}
			else if (Map[X] == '*')
			{
				SpawnActor(new AWall(X, Y));
				SpawnActor(new AFloor(X, Y));
			}
			else if (Map[X] == ' ')
			{
				SpawnActor(new AFloor(X, Y));
			}
			else if (Map[X] == 'M')
			{
				SpawnActor(new AMonster(X, Y));
				SpawnActor(new AFloor(X, Y));
			}
			else if (Map[X] == 'G')
			{
				SpawnActor(new AGoal(X, Y));
				SpawnActor(new AFloor(X, Y));
			}

		}
		Y++;
	}

	//Sort
	Sort();

	InputFile.close();
}

void UEngine::Sort()
{
	AActor* Temp;
	for (int i = 0; i < Actors.size(); ++i)
	{
		for (int j = i + 1; j < Actors.size(); ++j)
		{
			if (Actors[i]->Layer > Actors[j]->Layer)
			{
				Temp = Actors[i];
				Actors[i] = Actors[j];
				Actors[j] = Temp;
			}
		}
	}
}

void UEngine::Input()
{
	KeyCode = _getch();
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

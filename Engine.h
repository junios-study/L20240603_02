#pragma once
#include <vector>

using namespace std;

class AActor;

class UEngine
{
public:
	UEngine();
	virtual ~UEngine();

	void SpawnActor(AActor* NewActor);

	void Run();

	bool IsRunning;


	vector<AActor*> Actors;
protected:
	void Input();
	void Tick();
	void Render();

};


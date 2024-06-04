#pragma once
#include <vector>
#include <string>

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

	void LoadLevel(std::string MapFilename);

	void Sort();

	vector<AActor*> Actors;

	static int KeyCode;

protected:
	void Input();
	void Tick();
	void Render();

};



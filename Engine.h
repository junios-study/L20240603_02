#pragma once
#include <vector>
#include <string>

using namespace std;

class AActor;

//sigleton patern
class UEngine
{
protected:
	UEngine();

public:
	virtual ~UEngine();

	static UEngine* GetInstance()
	{
		if (!Instance)
		{
			Instance = new UEngine();

			return Instance;
		}

		return Instance;
	}


	void Init();

	void Term();

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

	static UEngine* Instance;

};

#define GEngine UEngine::GetInstance()



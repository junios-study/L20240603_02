#include "Engine.h"
#include "iostream"

using namespace std;

class Singleton
{
public:

private:
	Singleton();
	int Number;
	static Singleton* Instanace;

public:
	static void Add(Singleton B)
	{
		
	}

	static Singleton* GetInstance()
	{
		if (!Instanace)
		{
			Instanace = new Singleton();
		}

		return Instanace;
	}
};

Singleton* Singleton::Instanace = nullptr;

#define GSinglton Singleton::GetInstance()


int main()
{
	GSinglton;
	GSinglton;
	GSinglton;
	GSinglton;
	GSinglton;

	return 0;
}


int main2()
{
	GEngine->LoadLevel("data.map");

	GEngine->Run();

	delete GEngine;

	return 0;
}
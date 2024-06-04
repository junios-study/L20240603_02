#include "Engine.h"

int main()
{
	UEngine* MyEngine = new UEngine();

	MyEngine->LoadLevel("data.map");

	MyEngine->Run();

	delete MyEngine;

	return 0;
}
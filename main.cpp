#include "Engine.h"
#include "iostream"

using namespace std;

int main()
{
	UEngine* MyEngine = UEngine::GetInstance();
//	UEngine* MyEngine2 = new UEngine();

	MyEngine->LoadLevel("data.map");

	MyEngine->Run();

	delete MyEngine;


	return 0;
}
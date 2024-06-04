#include "Engine.h"

#include <iostream>

using namespace std;

int main2()
{
	int Numbers[5] = { 5, 4, 2, 1, 3 };
	
	for (auto N : Numbers)
	{
		cout << N << ", ";
	}


	return 0;
}


int main()
{
	UEngine* MyEngine = new UEngine();

	MyEngine->LoadLevel("data.map");

	MyEngine->Run();

	delete MyEngine;

	return 0;
}
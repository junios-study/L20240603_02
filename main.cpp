#include "Engine.h"
#include "iostream"

using namespace std;

int main()
{
	GEngine->LoadLevel("data.map");

	GEngine->Run();

	delete GEngine;

	return 0;
}
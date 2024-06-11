#include "Engine.h"
//#include "iostream"

//using namespace std;

int SDL_main(int argc, char* argv[])
{
	GEngine->LoadLevel("data.map");

	GEngine->Run();

	delete GEngine;

	return 0;
}
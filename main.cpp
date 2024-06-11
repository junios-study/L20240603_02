//#define _CRT_SECURE_NO_WARNINGS

#include "Engine.h"
#include <string>

//#include <string.h>

int SDL_main(int argc, char* argv[])
{
	std::string name = "junios";
	std::string name2;

	name2 = name;

	char Data[100];
	char Data2[100];

	strcpy(Data, "Junios");
	for (int i = 0; i < 100; ++i)
	{
		if (Data[i] == '\0')
		{
			Data2[i] = '\0';
			break;
		}
		Data2[i] = Data[i];
	}
	

	GEngine->LoadLevel("data.map");
	GEngine->Run();

	delete GEngine;

	return 0;
}
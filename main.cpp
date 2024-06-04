#include "Engine.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void T()
{
	cout << "T" << endl;
}

void Y()
{
	cout << "Y" << endl;
}

void Test(void (*FunctionPointer)())
{
	for (int i = 0; i < 100; ++i)
	{
		if (i > 50)
		{
			FunctionPointer();
		}
	}
}

void EnterPointer(void* P,int Count, int ElementOfSize)
{

}

class UObject
{

};

class AActor : public UObject
{

};

class APawn : public AActor
{

};

int main()
{
	UObject* Object = new UObject();
	UObject* Object = new AActor();
	UObject* Object = new APawn();

	int* PA = nullptr;
	float* PF = nullptr;

	EnterPointer(PA);
	EnterPointer(PF);


	
	return 0;
}



int main2()
{
	UEngine* MyEngine = new UEngine();

	MyEngine->LoadLevel("data.map");

	MyEngine->Run();

	delete MyEngine;

	return 0;
}
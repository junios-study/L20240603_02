#include "Engine.h"
#include <iostream>
#include <algorithm>

using namespace std;

int Compare(int A, int B)
{
	return A - B;
}

void Sort(void* PA, int Size, int (*CompareFunction)(int A, int B))
{
	int* IntPA = (int*)PA;

	for (int i = 0; i < Size; ++i)
	{
		for (int j = 0; j < Size; ++j)
		{
			if (CompareFunction(IntPA[i], IntPA[j]) > 0 )
			{
				int Temp = IntPA[i];
				IntPA[i] = IntPA[j];
				IntPA[j] = Temp;
			}
		}
	}

	for (int i = 0; i < Size; ++i)
	{
		cout << IntPA[i] << ", ";
	}
}


void (*fp)(void* PA, int Size, int ElementOfSize);

void (*fp2)();

void Test()
{
	cout << "Test" << endl;
}

void Test2()
{
	cout << "Test2" << endl;
}

void (*FunctionPointer)(int A, int B);

void Add(int A, int B)
{
	cout << A + B << endl;
}

void Sub(int A, int B)
{
	cout << A - B << endl;
}

void Operator(int A, int B, void (*FunctionPointer)(int A, int B))
{
	cout << FunctionPointer << endl;
}

int Compare2(int A, int B)
{
	return B - A;
}

int main()
{
	int Numbers2[4] = { 5, 4, 2, 1 };
	//Sort(Numbers2, 4, Compare2);


	//int* PA = Numbers;
	//float Numbers[4] = { 5.3f, 4.1f, 2.0f, 1.67f };
	//int* PA2 = Numbers2;
	//float* PA = Numbers;


	Operator(1, 2, Add);
	//Operator(1, 2, Sub);

	//fp2 = Test2;

	//cout << fp2 << endl;
	//cout << Test << endl;

	//Test();
	//fp2();

	//cout << *(PA2+0) << endl;
	//cout << NPA2[0] << endl;


	//Sort(PA2, sizeof(Numbers) / sizeof(float), sizeof(float));


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
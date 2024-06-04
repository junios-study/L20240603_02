#include "Engine.h"
#include <iostream>
#include <algorithm>

using namespace std;

int compare(const void* PA, const void* PB)
{
	int A = *(int*)PA;
	int B = *(int*)PB;

	return A - B;

	//if (A > B)
	//{
	//	return 1;
	//}
	//else if (A < B)
	//{
	//	return -1;
	//}
	//else
	//{
	//	return 0;
	//}


}

int main()
{
	int Numbers[5] = { 5, 4, 2, 1, 3 };

	qsort(Numbers, 5, sizeof(int), compare);

	for (auto N : Numbers)
	{
		cout << N << ", ";
	}


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
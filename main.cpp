#include "Engine.h"
#include <iostream>
#include <vector>
#include <list>


using namespace std;


int main()
{
	//Container
	//iterator, i
	vector<int> Datas;
	list<int> Datas2;
	Datas.push_back(1);
	Datas.push_back(2);
	Datas.push_back(3);

	Datas2.push_back(4);
	Datas2.push_back(5);
	Datas2.push_back(6);

	for (int i = 0; i < Datas.size(); ++i)
	{
		cout << Datas[i] << endl;;
	}
	for (vector<int>::reverse_iterator iter = Datas.rbegin(); iter != Datas.rend(); ++iter)
	{
		cout << *iter << endl;;
	}
	for (auto iter = Datas2.rbegin(); iter != Datas2.rend(); ++iter )
	{
		cout << *iter << endl;;
	}
	for (auto Data : Datas)
	{
		cout << Data << endl;;
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
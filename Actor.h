#pragma once
class AActor
{
public:
	AActor();
	virtual ~AActor();

	int X;
	int Y;

	char Shape;

	virtual void Tick();
	virtual void Render();


};


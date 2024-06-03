#pragma once
class AActor
{
public:
	AActor();
	AActor(int NewX, int NewY, char NewShape);
	virtual ~AActor();

	int X;
	int Y;

	char Shape;

	virtual void Tick();
	virtual void Render();


};


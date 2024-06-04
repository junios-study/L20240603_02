#pragma once
class AActor
{
public:
	AActor();
	AActor(int NewX, int NewY, char NewShape = ' ', int NewLayer = 0);
	virtual ~AActor();

	int Layer;

	int X;
	int Y;

	char Shape;

	virtual void Tick();
	virtual void Render();


};


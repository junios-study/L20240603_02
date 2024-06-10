#include "Goal.h"

AGoal::AGoal()
{
	X = 0;
	Y = 0;
	Shape = ' ';
	Layer = 3;
	IsCollision = false;
}

AGoal::AGoal(int NewX, int NewY, char NewShape)
{
	X = NewX;
	Y = NewY;
	Shape = NewShape;
	Layer = 3;
	IsCollision = false;
}

AGoal::~AGoal()
{
}

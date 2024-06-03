#include "Wall.h"

AWall::AWall()
{
	X = 1;
	Y = 1;
	Shape = ' ';
}

AWall::AWall(int NewX, int NewY, char NewShape)
{
	X = NewX;
	Y = NewY;
	Shape = NewShape;
}

AWall::~AWall()
{
}
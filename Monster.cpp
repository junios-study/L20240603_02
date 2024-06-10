#include "Monster.h"

AMonster::AMonster()
{
	X = 0;
	Y = 0;
	Shape = ' ';
	Layer = 5;
	IsCollision = false;
}

AMonster::AMonster(int NewX, int NewY, char NewShape)
{
	X = NewX;
	Y = NewY;
	Shape = NewShape;
	Layer = 5;
	IsCollision = false;
}

AMonster::~AMonster()
{
}

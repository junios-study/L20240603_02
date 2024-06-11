#pragma once
#include "Actor.h"
class AMonster : public AActor
{
public:
	AMonster();
	AMonster(int NewX, int NewY, char NewShape = 'M');
	virtual ~AMonster();
	virtual void Tick() override;
	bool Predict(int PredictX, int PredictY);
};


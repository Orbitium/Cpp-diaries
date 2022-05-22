#pragma once
#include "../GameObject.h"

class Bread : public GameObject
{
public:
	Bread(const char* texturePath, int startX, int startY, int scale) : GameObject(texturePath, startX, startY, scale)
	{
		speed = 3;
	}

	void update() override
	{
		setX(getX() + speed);
	}

private:
	int speed;
};
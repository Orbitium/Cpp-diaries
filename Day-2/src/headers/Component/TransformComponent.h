#pragma once
#include "ECS.h"
#include "../Vectors/Vector2D.h"

class TransformComponent : public Component
{
public:

	Vector2D pos;
	Vector2D velocity;

	int height = 32;
	int width = 32;
	int scale = 1;

	int speed = 4;

	TransformComponent(int sc) {
		pos.zero();
		scale = sc;
	}

	TransformComponent(float x, float y) {
		pos.zero();
	}

	TransformComponent(float x, float y, int h, int w, int sc) {
		pos.x = x;
		pos.y = y;
		height = h;
		width = w;
		scale = sc;
	}

	TransformComponent() {
		pos.zero();
	}

	void update() override {
		pos.x += velocity.x * speed;
		pos.y += velocity.y * speed;
	}
};
 
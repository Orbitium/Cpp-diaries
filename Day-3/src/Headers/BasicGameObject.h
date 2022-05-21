#pragma once
#include "Game.h"
#include <vector>

class BasicGameObject
{
public:
	BasicGameObject(const char* texturePath, int x, int y, int scale)
	{
		texture = Game::loadTexture(texturePath);

		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 32;

		destRect.x = x;
		destRect.y = y;
		destRect.w = srcRect.w * scale;
		destRect.h = srcRect.h * scale;
	}

	BasicGameObject(const char* texturePath, int x, int y, int s_x, int s_y)
	{
		texture = Game::loadTexture(texturePath);

		srcRect.x = srcRect.y = 0;
		srcRect.w = s_x;
		srcRect.h = s_y;

		destRect.x = x;
		destRect.y = y;
		destRect.w = srcRect.w;
		destRect.h = srcRect.h;
	}

	virtual void update() {};
	virtual void draw() {
		SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect);
	};

	virtual void setTexture(const char* texturePath) {
		texture = Game::loadTexture(texturePath);
	};

	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
};
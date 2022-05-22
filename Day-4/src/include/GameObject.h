#pragma once
#include <SDL.h>

class GameObject
{
public:
	
	GameObject(const char* texturePath, int startX, int startY);

	GameObject(const char* texturePath, int startX, int startY, int scale);

	GameObject(const char* texturePath, int startX, int startY, int srcSizeX, int srcSizeY);

	void setTexture(SDL_Texture* texture) { this->texture = texture; }

	virtual void update() {}

	void setX(int x) { destRect.x = x; }
	void setY(int y) { destRect.x = y; }
	void setW(int w) { destRect.x = w; }
	void setH(int h) { destRect.x = h; }

	int getX() { return destRect.x; }
	int getY() { return destRect.y; }
	int getW() { return destRect.w; }
	int getH() { return destRect.h; }

	const char* texturePath;

	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
};
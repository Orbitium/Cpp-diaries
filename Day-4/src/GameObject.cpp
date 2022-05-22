#include "include/GameObject.h"

GameObject::GameObject(const char* texturePath, int startX, int startY)
{
	this->texturePath = texturePath;

	srcRect.x = srcRect.y = 0;
	destRect.h = destRect.w = srcRect.w = srcRect.h = 32;

	destRect.x = startX;
	destRect.y = startY;
}

GameObject::GameObject(const char* texturePath, int startX, int startY, int scale)
{
	this->texturePath = texturePath;

	srcRect.x = srcRect.y = 0;
	srcRect.w = srcRect.h = 32;

	destRect.x = startX;
	destRect.y = startY;
	destRect.w = srcRect.w * scale;
	destRect.h = srcRect.h * scale;
}

GameObject::GameObject(const char* texturePath, int x, int y, int srcSizeX, int srcSizeY)
{
	this->texturePath = texturePath;

	srcRect.x = srcRect.y = 0;
	srcRect.w = destRect.w = srcSizeX;
	srcRect.h = destRect.h = srcSizeY;

	destRect.x = x;
	destRect.y = y;
}

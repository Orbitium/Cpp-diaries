#include "headers/GameObject.h"
#include "headers/TextureManager.h"

GameObject::GameObject(const char* textureLocation, int x, int y) {

	texture = TextureManager::loadTexture(textureLocation);
	
	xPos = x;
	yPos = y;
	time = 1200;
	startAt = 20;

}

void GameObject::update() {

	time++;
	
	if (time >= 170)
	{
		srcRect.w = 32;
		srcRect.h = 32;
		srcRect.x = 0;
		srcRect.y = 0;

		destRect.x = xPos;
		destRect.y = yPos;
		destRect.w = srcRect.w * 2;
		destRect.h = srcRect.h * 2;

		int randomX = 1 + (rand() % 600);
		int randomY = 1 + (rand() % 600);

		xPos = randomX;
		yPos = randomY;

		time = startAt;
	}
}

void GameObject::render() {
	SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect);
}
#include "include/GameWindow.h"
#include <SDL_image.h>
#include <iostream>

#include "include/GameObject.h"
#include "include/GameObjects/Bread.h"

bool GameWindow::init(const char* title)
{
	bool success = false;
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	if (window)
	{
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer)
		{
			success = true;
		}
	}
	//Init objects here
	
	addObject(new GameObject("<location>", 0, 0, 1));
	addObject(new Bread("<location>", 0, 0, 1));

	for (GameObject* gameObject : gameObjects)
	{
		loadTexture(gameObject);
	}

	return success;
}

void GameWindow::update()
{
	for (GameObject* gameObject : gameObjects)
	{
		gameObject->update();
	}
}

void GameWindow::render()
{
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 225, 225, 225, 255);
	for (GameObject* gameObject : gameObjects)
	{
		SDL_RenderCopy(renderer, gameObject->texture, &gameObject->srcRect, &gameObject->destRect);
	}
	SDL_RenderPresent(renderer);
}

void GameWindow::handleEvents()
{
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void GameWindow::loadTexture(GameObject* obj)
{
	SDL_Surface* surface = IMG_Load(obj->texturePath);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (!texture)
	{
		std::cout << obj->texturePath << " texture is not found!" << std::endl;
	}
	obj->setTexture(texture);
}
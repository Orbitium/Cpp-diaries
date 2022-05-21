#include "Headers/Game.h"
#include "SDL_image.h"
#include "Headers/BasicGameObject.h"

#include <iostream>

Game::Game(){}

SDL_Renderer* Game::renderer = nullptr;

std::vector<BasicGameObject> breads;

void Game::init(const char* title, int sizeX,int sizeY) {

	SDL_Init(SDL_INIT_EVERYTHING);


	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, sizeX, sizeY, false);

	if (window == NULL)
	{
		std::cout << "Window failed to init!" << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1 , SDL_RENDERER_ACCELERATED);
	if (renderer)
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	}
	running = true;
	breads.push_back(BasicGameObject("resources/bread.bmp", 30, -10, 2));

}

void Game::handleEvents()
{
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		running = false;
		break;
	}
}

void Game::update() {
	for (BasicGameObject& obj : breads)
	{
		obj.destRect.y += 15;
		if (obj.destRect.y > 810)
		{
			obj.destRect.y = -40;
		}
	}
}


void Game::render() {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	
	for (BasicGameObject& obj : breads) {
		obj.draw();
	}

	SDL_RenderPresent(renderer);
}


void Game::close() {
	std::cout << "closed";
}


SDL_Texture* Game::loadTexture(const char* texturePath) {
	SDL_Surface* surface = IMG_Load(texturePath);
	if (surface)
	{
		SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
		SDL_FreeSurface(surface);
		std::cout << "Texture loaded!" << std::endl;
		return texture;
	}
	std::cout << "Texture is not found!" << std::endl;
	throw "Texture is not found";
}
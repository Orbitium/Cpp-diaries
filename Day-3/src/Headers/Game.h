#pragma once
#include "SDL.h"

class Game
{
public:
	void init(const char* title, int sizeX, int sizeY);
	void render();
	void update();
	void handleEvents();
	void close();
	
	static SDL_Texture* loadTexture(const char* texturePath);

	Game();
	bool running = false;
	static SDL_Renderer* renderer;
private:
	SDL_Event event;
	SDL_Window* window;
};
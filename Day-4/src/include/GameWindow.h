#pragma once
#include "SDL.h"
#include <vector>

class GameObject;

class GameWindow
{
public:
	bool init(const char* title);
	void handleEvents();
	void update();
	void render();

	void addObject(GameObject* object) { gameObjects.push_back(object); }

	void loadTexture(GameObject* obj);

	bool isRunning = true;

private:
	SDL_Event event;
	SDL_Renderer* renderer;
	SDL_Window* window;
	std::vector<GameObject*> gameObjects;
};

#define SDL_MAIN_HANDLED

#include "SDL.h"
#include <stdio.h>
#include <iostream>
#include "Headers/Game.h"

using namespace std;

Game* g = nullptr;

int main(int argc, char* argv[])
{
	g = new Game();
	g->init("Bread Clicker", 800, 600);

	while (g->running)
	{
		g->handleEvents();
		g->update();
		g->render();
		SDL_Delay(16);
	}

	g->close();

	return 0;
}
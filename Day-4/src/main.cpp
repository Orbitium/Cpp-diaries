#define SDL_MAIN_HANDLED

#include <SDL.h>
#include "include/GameWindow.h"
#include <iostream>

GameWindow gameWindow;

int main(int argc, char* args[])
{
	if (gameWindow.init("Bread Clicker"))
	{
		while (gameWindow.isRunning)
		{
			gameWindow.handleEvents();
			gameWindow.update();
			gameWindow.render();
			SDL_Delay(16);
		}
	}
	else
		std::cout << "An error raised!" << std::endl;
	return 0;
}
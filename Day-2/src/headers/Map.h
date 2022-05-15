#include "Game.h"

class Map {
public:
	Map();
	~Map();
	
	void loadMap(int arr[20][25]);
	void drawMap();

private:
	SDL_Rect src, dest;

	SDL_Texture* grassTexture;
	SDL_Texture* dirtTexture;

	int map[20][25];
};
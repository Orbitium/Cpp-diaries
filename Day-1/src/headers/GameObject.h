#include "Game.h"

class GameObject {
public:
	GameObject(const char* textureLocation, int x, int y);
	~GameObject();

	void update();
	void render();

	int xPos;
	int yPos;
	SDL_Rect srcRect, destRect;
	int time;
	int startAt;


private:

	SDL_Texture* texture;
};
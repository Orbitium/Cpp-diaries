#include "headers/TextureManager.h"


SDL_Texture* TextureManager::loadTexture(const char* fileName) {
	SDL_Surface* tempSurface = IMG_Load(fileName);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);

	return texture;
}

void TextureManager::draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest) {
	SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}

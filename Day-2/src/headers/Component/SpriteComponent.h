#pragma once
#include "Components.h"
#include "SDL.h"

class SpriteComponent: public Component
{
private:
	TransformComponent *transform;
	SDL_Texture *texture;
	SDL_Rect srcRect, destRect;

public:
	SpriteComponent() = default;

	SpriteComponent(const char* texturePath) {
		texture = TextureManager::loadTexture(texturePath);
	}

	void setTexture(const char* texturePath) {
		texture = TextureManager::loadTexture(texturePath);
	}

	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = transform->width;
		srcRect.h = transform->height;
	}

	void update() override
	{
		destRect.x = static_cast<int>(transform->pos.x);
		destRect.y = static_cast<int>(transform->pos.y);
		destRect.w = transform->width * transform->scale;
		destRect.h = transform->height * transform->scale;

	}

	void draw() override
	{
		TextureManager::draw(texture, srcRect, destRect);
	}
};
#include "headers/Game.h"
#include "headers/TextureManager.h"
#include "headers/Map.h"

#include "headers/Component/ECS.h"
#include "headers/Component/Components.h"
#include "headers/Vectors/Vector2D.h"

#include "headers/Component/Collider/Collision.h"

Game::Game() {}

Game::~Game() {}

//GameObject* box;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

Map* map;
Manager manager;

auto& newBox(manager.addEntity());
auto& wall(manager.addEntity());
auto& wall2(manager.addEntity());

void Game::init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen) {

    int flags = 0;
    if (fullscreen) { flags = SDL_WINDOW_FULLSCREEN; }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsystems Initialised!" << std::endl;

        window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
        if (window) {
            std::cout << "Window created!" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std::endl;
        }

        isRunning = true;
    }
    map = new Map();

    newBox.addComponent<TransformComponent>();
    newBox.addComponent<SpriteComponent>("resources/box.bmp");
    newBox.addComponent<KeyboardController>();
    newBox.addComponent<ColliderComponent>("player");

    wall.addComponent<TransformComponent>(130.0f, 400.0f, 100.0f, 100.0f, 1);
    wall.addComponent<SpriteComponent>("resources/dirt.bmp");
    wall.addComponent<ColliderComponent>("wall");

    wall2.addComponent<TransformComponent>(250.0f, 400.0f, 100.0f, 100.0f, 1);
    wall2.addComponent<SpriteComponent>("resources/dirt.bmp");
    wall2.addComponent<ColliderComponent>("wall");
}

void Game::handleEvents() {
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    }

}

void Game::update() {
    manager.reflesh();
    manager.update();

    if (Collision::AABB(newBox.getComponent<ColliderComponent>().collider ,
        wall.getComponent<ColliderComponent>().collider) ||
        Collision::AABB(newBox.getComponent<ColliderComponent>().collider,
        wall2.getComponent<ColliderComponent>().collider))
    {
        newBox.getComponent<TransformComponent>().velocity * -1;
    }
}

void Game::render() {
    SDL_RenderClear(renderer);
    map->drawMap();
    manager.draw();
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}
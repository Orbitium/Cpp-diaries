#include "headers/Game.h"
#include "headers/TextureManager.h"
#include "headers/GameObject.h"
#include <string>

Game::Game() {}

Game::~Game() {}

GameObject* box;
static int point = 0;

SDL_Renderer* Game::renderer = nullptr;

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

    box = new GameObject("resources/box.bmp", 350,300);
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    case SDL_MOUSEBUTTONDOWN:
        int pressedX = event.button.x;
        int pressedY = event.button.y;

        int x = box->destRect.x;
        int y = box->destRect.y;


        if (x <= pressedX && pressedX <= x + 64)
        {
            if (y <= pressedY && pressedY <= y + 64)
            {
                point++;

                std::string title = "Point: " + std::to_string(point);

                SDL_SetWindowTitle(window, const_cast<char*>(title.c_str()));

                box->time = 2000;
                box->startAt = point * 10;
            }
        }

        break;
    }

}

void Game::update() {
    box->update();
}

void Game::render() {
    SDL_RenderClear(renderer);
    //map->drawMap();
    box->render();
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}
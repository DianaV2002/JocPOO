#include "Game.h"
#include <iostream>
#include "Map.h"
#include "Player.h"
#include "EnemyManager.h"
#include "Health.h"

Map* map;

Player *player;

EnemyManager* enemyManager;

BulletManager* bulletManager;

Health* health;

Game::Game(): isRunning(false), window(nullptr), renderer(nullptr)
{
}

Game::~Game()
{
   delete player;
}


void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems initialized" << std::endl;
		auto window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window!=nullptr)
		{
			std::cout << "Window created" << std::endl;
		}
 
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer != nullptr)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255,255);
			std::cout << "Renderer created" << std::endl;
		}
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
	int lvl = 1;
	map = new Map(renderer);
	player = new Player ("assets/plantPlayer.png", renderer);
	player->init(32,32);
	health = new Health("assets/health.png", renderer);
	health->setPlayer(player);
	health->init(0,0);
	enemyManager = new EnemyManager("assets/zombie.png", renderer);
	enemyManager->init(lvl, player);
	bulletManager = new BulletManager("assets/bullet.png", renderer);
	player->setBulletManager(bulletManager);
	enemyManager->setBulletManager(bulletManager);

}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT: {
		isRunning = false;
		break;
	}
	default:
		player->handleEvent(event);
		break;
	}
}
//obiecte care se actualizeaza(bullet, life)
void Game::update() const
{
	if (player->isAlive())
		player->update();
	else
		player->setTex("assets/deadPlayer.png");
	health->update();
	enemyManager->update();
	bulletManager->update();
}

//obiecte de afisat
void Game::render() const
{
	SDL_RenderClear(renderer);
	// this is where we would add stuff to render
	map->DrawMap();
	player->draw();
	health->draw();
	enemyManager->draw();
	bulletManager->draw();

	SDL_RenderPresent(renderer);
}

void Game::clean() const
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_QUIT;
	std::cout << "Game cleaned" << std::endl;
}

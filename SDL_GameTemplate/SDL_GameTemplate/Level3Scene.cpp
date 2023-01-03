class Enemy;
#include "Level3Scene.h"
#include "Map.h"
#include "Player.h"
#include "EnemyManager.h"
#include "Health.h"
#include "MainMenuScene.h"
#include <iostream>

Map* map3;

Player* player3;

EnemyManager* enemyManager3;

BulletManager* bulletManager3;

Health* health3;

Level3Scene::Level3Scene(SDL_Renderer* renderer, Game* game)
{
	this->renderer = renderer;
	this->game = game;
}

void Level3Scene::init()
{
	int lvl = 3;
	map3 = new Map(renderer);

	player3 = new Player("assets/plantPlayer.png", renderer);
	player3->setMap(map3);
	player3->init(32, 32);

	std::cout << "Player initializat\n";
	health3 = new Health("assets/health.png", renderer);
	health3->setPlayer(player3);
	health3->init(0, 0);

	bulletManager3 = new BulletManager("assets/bullet.png", renderer);
	bulletManager3->setMap(map3);
	std::cout << "Bullet manager initializat\n";
	player3->setBulletManager(bulletManager3);

	enemyManager3 = new EnemyManager("assets/finalZombie.png", renderer);
	enemyManager3->setMap(map3);
	enemyManager3->setBulletManager(bulletManager3);
	enemyManager3->init(lvl, player3);

	std::cout << "Enemy manager initializat\n";
}

void Level3Scene::update()
{
	if (player3->isAlive())
		player3->update();
	else
		player3->setTex("assets/deadPlayer.png");
	std::cout << "Player update\n";
	health3->update();
	enemyManager3->update();
	std::cout << "Enemy manager update\n";
	bulletManager3->update();
	std::cout << "Bullet manager update\n";
}

void Level3Scene::draw()
{
	SDL_RenderClear(renderer);
	// this is where we would add stuff to render
	map3->DrawMap();
	player3->draw();
	health3->draw();
	enemyManager3->draw();
	bulletManager3->draw();

	SDL_RenderPresent(renderer);
}

void Level3Scene::handleEvents(SDL_Event& event)
{

	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			Scene* scene = new MainMenuScene(renderer, game);
			scene->init();
			game->setScene(scene);
			break;

		}
	}
}
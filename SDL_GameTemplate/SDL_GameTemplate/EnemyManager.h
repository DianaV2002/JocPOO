#pragma once
class Enemy;
class Player;
#include "Enemy.h"
#include "SDL.h"

class EnemyManager  {
	const char* path;
	SDL_Renderer* renderer{};
	Enemy** allEnemies;
	BulletManager* bulletManager;
	Player* target;
	int n;
public:
	EnemyManager() = default;
	EnemyManager(const char* path, SDL_Renderer* renderer);
	void init(int lvl, Player* player);
	void clear();
	void update();
	void draw();
	int getNumberEnemies();
	Enemy** getAllEnemies();
	void deleteEnemy(int index);
	void setBulletManager(BulletManager*);
	bool bulletCollision(Bullet* bullet, Enemy* enemy);
	~EnemyManager();
};
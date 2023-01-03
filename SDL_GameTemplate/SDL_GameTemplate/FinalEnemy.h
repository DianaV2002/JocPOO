#pragma once
#include "Enemy.h"

class FinalEnemy :public Enemy {
	
	int health = 3;
public:
	FinalEnemy() = default;
	FinalEnemy(const char* path, SDL_Renderer * renderer, int health=3);

	void setTex(const char* path);

	void init(int x, int y) ;

	void update() ;

	void draw();

	bool checkCollision(const SDL_Rect & obj);

	void setTarget(Player * target);

	void followTarget();

	bool isWallBetween(int playerRow, int playerCol, int enemyRow, int enemyCol);

	bool playerCollision();

	void loseHealth();

	SDL_Rect getEnemyPos();

	~FinalEnemy();

	void setMap(Map * map);

};
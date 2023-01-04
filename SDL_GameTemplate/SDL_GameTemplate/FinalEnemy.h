#pragma once
class BulletManager;
class Map;
#include "Enemy.h"
#include "BulletManager.h"

class FinalEnemy :public Enemy {
	BulletManager* bulletManager;
	Player* target;
	Map* map;
	int health = 3;
public:
	FinalEnemy() = default;
	FinalEnemy(const char* path, SDL_Renderer * renderer, int health=3);

	void setTex(const char* path);

	void init(int x, int y, Player* player, Map* map, BulletManager* bulletManager) ;

	void update() ;

	void draw();

	bool checkCollision(const SDL_Rect & obj);

	void followTarget();

	bool isWallBetween(int playerRow, int playerCol, int enemyRow, int enemyCol);

	bool playerCollision();

	void loseHealth();

	bool bulletCollision(Bullet*);

	void deleteFinalEnemy();
    
	~FinalEnemy() = default;

};
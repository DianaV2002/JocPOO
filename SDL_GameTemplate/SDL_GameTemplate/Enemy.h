#pragma once
#include "Component.h"
#include "SDL.h"
#include "Player.h"

class Enemy : public Component
{
	SDL_Texture* texture{};
	SDL_Renderer* renderer{};
	SDL_Rect srcRect{}, destRect{};
	KEY_p direction;
	int xspeed, yspeed;
	Player* target;

public:
	Enemy() = default;
	Enemy(const char* path, SDL_Renderer* renderer);

	void setTex(const char* path);

	void init(int x, int y) override;

	void update() override;

	void draw() override;

	bool checkCollision(const SDL_Rect& obj);

	void setTarget(Player* target);

	void followTarget();

	bool isWallBetween(int playerRow, int playerCol, int enemyRow, int enemyCol);
	
	bool playerCollision();

	SDL_Rect getEnemyPos();

	~Enemy();
};

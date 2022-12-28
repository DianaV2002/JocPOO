#pragma once
class Bullet;
#include "Bullet.h"
#include "TextureManager.h"

class BulletManager
{
	const char* path;
	SDL_Renderer* renderer{};
	Bullet** allBullets;
	int n;
public:
	BulletManager() = default;
	BulletManager(const char* path, SDL_Renderer * renderer);
	void addBullet(int x, int y, KEY_p direction);
	void update();
	void draw();
	int getNumberBullets();
	Bullet** getAllBullets();
	void deleteBullet(int index);
	~BulletManager();
};
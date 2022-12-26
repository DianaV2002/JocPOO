#include "Enemy.h"
#include "Map.h"
#include "TextureManager.h"
#include <iostream>

using namespace std;

Enemy::Enemy(const char* path, SDL_Renderer* renderer) : renderer(renderer)
{
	setTex(path);
}

void Enemy::setTex(const char* path)
{
	texture = TextureManager::LoadTexture(path, renderer);
}

void Enemy::init()
{
	srcRect.x = srcRect.y = 0;
	srcRect.w = srcRect.h = 32;
	destRect.w = destRect.h = 32;
	destRect.x = destRect.y = 160;
	xspeed = yspeed = 4;
	direction = E_RIGHT;
}

void Enemy::update()
{
	// y creste in jos
	int** map = Map::GetMap();
	int lin = Map::GetLin();
	int col = Map::GetCol();

	int oldX = destRect.x;
	int oldY = destRect.y;

	switch (direction)
	{
	case E_UP:
		destRect.y -= yspeed;
		break;
	case E_DOWN:
		destRect.y += yspeed;
		break;
	case E_RIGHT:
		destRect.x += xspeed;
		break;
	case E_LEFT:
		destRect.x -= xspeed;
		break;
	case E_DEFAULT:
		break;
	}

	/*cout << destRect.x << " " << destRect.y << " " << destRect.x + destRect.w << " " << destRect.y + destRect.h << "\n\n";*/
	bool isCollision = false;
	for (int row = 0; row < lin && isCollision == false; row++)
		for (int column = 0; column < col && isCollision == false; column++)
			if (map[row][column] == 1)
			{
				SDL_Rect r = convertTileToRect(column * 32, row * 32, 32, 32);
				//cout << r.x << " " << r.y << " " << r.w << " " << r.h << '\n';
				isCollision = checkCollision(r);
			}

	if (isCollision == true)
	{
		destRect.x = oldX;
		destRect.y = oldY;
		int num = rand() % 4;
		switch (num) 
		{
		case 0:
			direction = E_UP;
			break;
		case 1:
			direction = E_RIGHT;
			break;
		case 2:
			direction = E_LEFT;
			break;
		case 3:
			direction = E_DOWN;
			break;
		}
	}
}


void Enemy::draw()
{
	TextureManager::Draw(texture, srcRect, destRect, renderer);
}
bool Enemy::checkCollision(const SDL_Rect& obj)
{
	SDL_Rect enemy = destRect;
	int a = 6; // indice de permisivitate ca sa trecem mai usor prin locuri stramte
	SDL_Rect permissiveObject{ obj.x + a, obj.y + a, obj.w - 2 * a, obj.h - 2 * a };

	if ((permissiveObject.x >= enemy.x + enemy.w) || (permissiveObject.x + permissiveObject.w <= enemy.x) || (permissiveObject.y >= enemy.y + enemy.h) || (permissiveObject.y + permissiveObject.h <= enemy.y))
		return false;
	return true;
}
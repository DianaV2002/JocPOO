#include "Enemy.h"
#include "Map.h"
#include "TextureManager.h"
#include <iostream>


using namespace std;
//Vector de inamici-enemy manager cu init, update, draw, 
Enemy::Enemy(const char* path, SDL_Renderer* renderer) : renderer(renderer)
{
	setTex(path);
}

void Enemy::setTex(const char* path)
{
	texture = TextureManager::LoadTexture(path, renderer);
}

// parametrii x si y de inceput
void Enemy::setTarget(Player* target)
{
	this->target = target;
}

// TODO: speed ca parametru pt lvl
void Enemy::init(int x, int y)
{
	srcRect.x = srcRect.y = 0;
	srcRect.w = srcRect.h = 32;
	destRect.w = destRect.h = 32;
	destRect.x = x;
	destRect.y = y;
	xspeed = yspeed = 2;
	direction = RIGHT;

}

void Enemy::update()
{

	followTarget();

	// y creste in jos
	int** map = Map::GetMap();
	int lin = Map::GetLin();
	int col = Map::GetCol();

	int oldX = destRect.x;
	int oldY = destRect.y;

	switch (direction)
	{
	case UP:
		destRect.y -= yspeed;
		break;
	case DOWN:
		destRect.y += yspeed;
		break;
	case RIGHT:
		destRect.x += xspeed;
		break;
	case LEFT:
		destRect.x -= xspeed;
		break;
	case DEFAULT:
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

	// de adaugat coliziune cu monstrii din vectorul de inamici ce se afla in clasa EnemyManager

	if (isCollision == true)
	{
		destRect.x = oldX;
		destRect.y = oldY;
		int num = rand() % 4;
		switch (num) 
		{
		case 0:
			direction = UP;
			break;
		case 1:
			direction = RIGHT;
			break;
		case 2:
			direction = LEFT;
			break;
		case 3:
			direction = DOWN;
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
bool Enemy::isWallBetween(int playerRow, int playerCol, int enemyRow, int enemyCol)
{
	int** map = Map::GetMap();
	if (playerRow == enemyRow)
	{
		int minim = min(playerCol, enemyCol);
		int maxim = max(playerCol, enemyCol);
		for (int column = minim + 1; column < maxim; column++)
			if (map[playerRow][column] == 1)
				return 1;
	}
	if (playerCol == enemyCol)
	{
		int minim = min(playerRow, enemyRow);
		int maxim = max(playerRow, enemyRow);
		for (int row = minim + 1; row < maxim; row++)
			if (map[row][playerCol] == 1)
				return 1;
	}
	return 0;
}
void Enemy::followTarget()
{
	//player-stanga, enemy dreapta pe aceeasi linie
	int playerRow = target->getPlayerPos().y / 32;
    int playerCol= target->getPlayerPos().x / 32;
	int enemyRow = this->destRect.y / 32;
	int enemyCol= this->destRect.x / 32;
	if (playerRow == enemyRow)
	{
		if (playerCol < enemyCol && !isWallBetween(playerRow, playerCol, enemyRow, enemyCol))//player in stanga
			direction = LEFT;
		else if (playerCol > enemyCol && !isWallBetween(playerRow, playerCol, enemyRow, enemyCol))
			direction = RIGHT;
	}
	if (playerCol == enemyCol)
	{
		if (playerRow < enemyRow && !isWallBetween(playerRow, playerCol, enemyRow, enemyCol))//player sus
			direction = UP;
		else if (playerRow > enemyRow && !isWallBetween(playerRow, playerCol, enemyRow, enemyCol))
			direction = DOWN;
	}

}
bool Enemy::playerCollision()
{
	return checkCollision(target->getPlayerPos());
}
Enemy::~Enemy()
{

}
SDL_Rect Enemy::getEnemyPos()
{
	return destRect;
}
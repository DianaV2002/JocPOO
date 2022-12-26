#include "Enemy.h"
#include "TextureManager.h"

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
	destRect.w = destRect.h = 64;
}

void Enemy::update()
{
	destRect.x++;
	destRect.y++;;
}


void Enemy::draw()
{
	texture=TextureManager::LoadTexture("assets/fox.png", renderer);
	TextureManager::Draw(texture, srcRect, destRect, renderer);
}
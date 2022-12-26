#pragma once
#include "Component.h"
#include "SDL.h"

enum Direction { E_UP, E_RIGHT, E_DOWN, E_LEFT, E_DEFAULT };

class Enemy : public Component
{
	SDL_Texture* texture{};
	SDL_Renderer* renderer{};
	SDL_Rect srcRect{}, destRect{};
	Direction direction;
	int xspeed, yspeed;
public:
	Enemy() = default;
	Enemy(const char* path, SDL_Renderer* renderer);

	void setTex(const char* path);

	void init() override;

	void update() override;

	void draw() override;

	bool checkCollision(const SDL_Rect& obj);
};

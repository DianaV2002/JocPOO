#pragma once
#include "Component.h"
#include "SDL.h"

class Enemy : public Component
{
	SDL_Texture* texture{};
	SDL_Renderer* renderer{};
	SDL_Rect srcRect{}, destRect{};

public:
	Enemy() = default;
	Enemy(const char* path, SDL_Renderer* renderer);

	void setTex(const char* path);

	void init() override;

	void update() override;

	void draw() override;
};

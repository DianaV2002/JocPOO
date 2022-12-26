#pragma once
#include "Component.h"
#include "SDL.h"

enum KEY_p{ UP, RIGHT, DOWN, LEFT, DEFAULT};

class Player : public Component
{
	SDL_Texture* texture{};
	SDL_Renderer* renderer{};
	SDL_Rect srcRect{}, destRect{};
	KEY_p direction;
	int xspeed, yspeed;
	//void setDirection(const KEY_p&);

public:
   Player() = default;
   Player(const char* path, SDL_Renderer* renderer);

	void setTex(const char* path);

	void init() override;

	void update() override;//aici se face miscarea

	void draw() override;//deseneaza noua pozitie

	void handleEvent(SDL_Event& event);//seteaza directia

};

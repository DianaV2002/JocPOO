#pragma once
#include "Scene.h"
#include "SDL.h"
#include "TextureManager.h"
#include"Level1Scene.h"
#include"Level2Scene.h"
#include "Level3Scene.h"
class Button;
#include "Button.h"

class MainMenuScene :public Scene
{
	SDL_Texture* background;
	SDL_Texture* exitButton;
	SDL_Texture* levelEasy;
	SDL_Texture* levelMedium;
	SDL_Texture* levelHard;
	SDL_Rect background_rect;
	SDL_Rect srcRect{};
	Button* easy;
	Button* medium;
	Button* hard;
	Button* exit;
	Game* game;
	bool play1,play2,play3,playExit;
	int Mx = 0;//coord mouse
	int My = 0;

public:
	MainMenuScene(SDL_Renderer* renderer,Game* game);
	void init();
	void update();
	void draw();
	void setTex();
	void handleEvents(SDL_Event& event);
	~MainMenuScene();

};
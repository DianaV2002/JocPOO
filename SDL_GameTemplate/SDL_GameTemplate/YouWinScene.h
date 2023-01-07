#pragma once
#include "SDL.h"
#include "Scene.h"
#include "TextureManager.h"
#include "Game.h"
#include"MainMenuScene.h"
class Game;
class Button;
#include "Button.h"

class YouWinScene:public Scene
{
	Button* backMain;
	SDL_Texture* backMainTex;
	SDL_Renderer* renderer;
	Game* game;
	int Mx = 0;//coord mouse
	int My = 0;
public:
	YouWinScene(SDL_Renderer* renderer,  Game* game);
	void init();
	void update();
	void draw();
	void handleEvents(SDL_Event& event);
	~YouWinScene() = default;

};
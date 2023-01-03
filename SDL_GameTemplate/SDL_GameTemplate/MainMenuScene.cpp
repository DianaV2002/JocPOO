#include "MainMenuScene.h"
#include <iostream>

MainMenuScene::MainMenuScene(SDL_Renderer* renderer, Game* game)
{
	this->renderer = renderer;
	this->game = game;
}
void MainMenuScene::init()
{

	SDL_Rect src, dest;
	src.h = 32;
	src.w = 32;
	src.x = 0;
	src.y = 0;
	dest.w = 32;
	dest.h = 32;
	dest.x = width / 2 - dest.w / 2;
	dest.y = height / 4 - dest.h / 2;
	
	Button* easy = new Button("assets/easy.png", renderer, src, dest);
	dest.y = height / 2 + dest.h / 2;
	Button * quit = new Button("assets/exit.png", renderer, src, dest);
	src.h = src.w = 32;

	dest.w = dest.h;
	dest.x = width / 2 - dest.w / 2;
	dest.y = height / 4 - dest.h / 2;
	Button* medium = new Button("assets/medium.png", renderer, src, dest);
	dest.y = height / 2 - dest.h / 2;
	Button* hard = new Button("assets/hard.png", renderer, src, dest);
	
	background = TextureManager::LoadTexture("assets/background.jpg", renderer);
	srcRect.x = srcRect.y = 0;
	srcRect.w = srcRect.h = 32;
	background_rect.x = 0;   //X COORDINATE
	background_rect.y = 0;   //Y COORDINATE
	background_rect.w = 640; 
	background_rect.h = 800;
}
void MainMenuScene::update()
{
	std::cout << "Update main menu\n";
}
void MainMenuScene::draw()
{

	TextureManager::Draw(background, srcRect, background_rect, renderer);
	easy->Render();
	medium->Render();
	hard->Render();
	exit->Render();
	std::cout << "Main menu\n";
	
}
void MainMenuScene::handleEvents(SDL_Event& event)
{
	play1 = false;
	play2 = false;
	play3 = false;
	playExit = false;

	SDL_GetMouseState(&Mx, &My);
	if (easy->InsideButton(Mx,My))
	{
		SDL_SetTextureColorMod(levelEasy, 250, 0, 0);

		if (event.type == SDL_MOUSEBUTTONDOWN)  
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{    //if it is pressed then play1 becomes true which you could use to initiate the newgame
				play1 = true;
			}
			
		}
		
	}
	if (medium->InsideButton(Mx,My))
	{
		SDL_SetTextureColorMod(levelMedium, 250, 0, 0);

		if (event.type == SDL_MOUSEBUTTONDOWN)  
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{    //if it is pressed then play1 becomes true which you could use to initiate the newgame
				play2 = true;
			}
		}
	}
	if (hard->InsideButton(Mx,My))
	{
		SDL_SetTextureColorMod(levelHard, 250, 0, 0);

		if (event.type == SDL_MOUSEBUTTONDOWN)  //this calls an event, I assume that you already know how to make an event right? 
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{    //if it is pressed then play1 becomes true which you could use to initiate the newgame
				play3 = true;
			}
		}
	}
	if (exit->InsideButton(Mx,My))
	{
		SDL_SetTextureColorMod(exitButton, 250, 0, 0);

		if (event.type == SDL_MOUSEBUTTONDOWN)  //this calls an event, I assume that you already know how to make an event right? 
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{    //if it is pressed then play1 becomes true which you could use to initiate the newgame
				playExit = true;
			}
		}
	}
	if (play1)
	{ 
		Level1Scene* scene = new Level1Scene(renderer,game);
		scene->init();
		game->setScene(scene);
		
	}
	if (play2)
	{
		Level2Scene* scene = new Level2Scene(renderer, game);
		scene->init();
		game->setScene(scene);
		
	}
	if (play3)
	{
		Level3Scene* scene = new Level3Scene(renderer, game);
		scene->init();
		game->setScene(scene);
		
	}
	if (playExit)
	{
		game->clean();
	}

}

MainMenuScene::~MainMenuScene()
{

}

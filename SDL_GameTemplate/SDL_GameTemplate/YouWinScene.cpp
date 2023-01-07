#include "YouWinScene.h"
YouWinScene::YouWinScene(SDL_Renderer* renderer, Game* game)
{
	this->renderer = renderer;
	this->game = game;

}
void YouWinScene::init()
{
	SDL_Rect src, dest;
	src.h = 96;
	src.w = 96;
	src.x = 0;
	src.y = 0;
	dest.w = 96;
	dest.h = 96;
	dest.x = width / 2 - dest.w / 2;
	dest.y = height / 4 - dest.h / 2;
	backMain = new Button("assets/backToMainMeniu.png", renderer, src, dest);


}
void YouWinScene::update()
{

}
void YouWinScene::draw()
{
	SDL_RenderClear(renderer);
	backMain->Render();
	SDL_RenderPresent(renderer);
}
void YouWinScene::handleEvents(SDL_Event& event)
{
	bool playBack = false;
	SDL_GetMouseState(&Mx, &My);
	if (backMain->InsideButton(Mx, My))
	{
		SDL_SetTextureColorMod(backMainTex, 250, 0, 0);

		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{    //if it is pressed then play1 becomes true which you could use to initiate the newgame
				playBack = true;
			}

		}

	}
	if (playBack)
	{
		MainMenuScene* scene = new MainMenuScene(renderer, game);
		scene->init();
		game->setScene(scene);
	}
}

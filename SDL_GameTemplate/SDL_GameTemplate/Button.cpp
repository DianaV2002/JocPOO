#include"Button.h"

Button::Button(const char* textureImage, SDL_Renderer* renderer, SDL_Rect srcrec, SDL_Rect destrec)
{
	this->texture = texture;
	this->renderer = renderer;
	this->srcrec = srcrec;
	this->destrec = destrec;
};

void Button::Render()
{
	TextureManager::Draw(texture, srcrec, destrec, renderer);
}

bool Button::InsideButton(int x, int y)
{
	if (x > destrec.x && x < destrec.x + destrec.w && y > destrec.y && y < destrec.y + destrec.h)
		return 1;
	return 0;
}
#include "Player.h"
#include "TextureManager.h"

Player::Player(const char* path, SDL_Renderer* renderer): renderer(renderer)
{
   setTex(path);
}

void Player::setTex(const char* path)
{
   texture = TextureManager::LoadTexture(path, renderer);
}


void Player::init()
{
   srcRect.x = srcRect.y = 0;
   srcRect.w = srcRect.h = 32;
   destRect.w = destRect.h = 64;
   xspeed = yspeed = 1;
   
}

void Player::update()
{
	//y creste in jos

   // TODO verificare iesire harta
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
}


void Player::draw()
{
   TextureManager::Draw(texture, srcRect, destRect, renderer);
}

void Player::handleEvent(SDL_Event& event)
{
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		default:
			direction = DEFAULT;
			break;

		case SDLK_UP:
			direction = UP;
			break;

		case  SDLK_DOWN:
			direction = DOWN;
			break;

		case SDLK_RIGHT:
			direction = RIGHT;
			break;
			
		case SDLK_LEFT:
			direction = LEFT;
			break;
		
		}
	}

	if (event.type == SDL_KEYUP)
	{
		direction = DEFAULT;
	}
}
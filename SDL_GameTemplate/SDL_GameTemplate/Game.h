#pragma once
class Scene;
#include <SDL.h>
#include "Scene.h"

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update() const;
	void render() const;
	void clean() const;
	bool running() const { return isRunning;  }
	void setScene(Scene* scene);
	Scene* getScene();
private:
	Scene* scene;
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
	
};

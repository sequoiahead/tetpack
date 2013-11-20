#include <SDL2/SDL_events.h>
#include <functional>
#include <iostream>

#include <libgame/util/sdl_compat.h>
#include <libgame/view/ViewScreen.h>
#include <libgame/action/ActionLogging.h>
#include <libgame/core/TheGame.h>

#include "view/ViewGameBoard.h"

int _main(int argc, char** argv) {
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* win;
	SDL_Renderer* ren;

	SDL_CreateWindowAndRenderer(640,480,SDL_WINDOW_SHOWN, &win, &ren);

	SDL_RendererInfo info;
	SDL_GetRendererInfo(ren,&info);

	SDL_RenderClear(ren);

	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
	SDL_Texture* tx = SDL_CreateTextureFromSurface(ren, IMG_Load("res/Z.png"));
	SDL_RenderCopy(ren, tx, NULL, NULL);
	SDL_RenderPresent(ren);

	SDL_Delay(3000);

	SDL_Quit();
	return 0;
}

int main(int argc, char** argv) {
	TheGame game;
	ResourceManager<ResourceImage> resMan("res/");
	GameBoard board;
	Well well = board.getWell();
	ViewGameBoard screen(&resMan, &well);

	game.getEventDispatcher().bind(SDL_KEYDOWN, SDL_SCANCODE_ESCAPE, std::bind(&TheGame::stop, &game, std::placeholders::_1));
	game.getEventDispatcher().bind(SDL_KEYDOWN, SDL_SCANCODE_LEFT, std::bind(&Well::left, &well, std::placeholders::_1));
	game.getEventDispatcher().bind(SDL_KEYDOWN, SDL_SCANCODE_RIGHT, std::bind(&Well::right, &well, std::placeholders::_1));
	game.getEventDispatcher().bind(SDL_KEYDOWN, SDL_SCANCODE_UP, std::bind(&Well::rotate, &well, std::placeholders::_1));
	game.getEventDispatcher().bind(SDL_KEYDOWN, SDL_SCANCODE_DOWN, std::bind(&Well::drop, &well, std::placeholders::_1));

	game.onTick().connect<ViewScreen, &ViewScreen::render>(&screen);

	game.start();

	return 0;
}

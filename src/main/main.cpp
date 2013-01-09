#include <SDL/SDL.h>

#include <libgame/util/sdl_compat.h>
#include <libgame/view/ViewScreen.h>
#include <libgame/event/EventHandlerKeyboard.h>
#include <libgame/action/ActionLogging.h>
#include <libgame/core/TheGame.h>

#include "view/ViewGameBoard.h"

#include <iostream>

int main (int argc, char** argv) {
	TheGame game;
	ResourceManager<ResourceImage> resMan("res/");
	GameBoard board;
	ViewGameBoard screen(&resMan, &board);

	ActionMethod<TheGame> actionQuit(&game, &TheGame::stop);
	ActionMethod<GameBoard> actionRotate(&board, &GameBoard::rotate);
	ActionMethod<GameBoard> actionDrop(&board, &GameBoard::drop);
	ActionMethod<GameBoard> actionLeft(&board, &GameBoard::left);
	ActionMethod<GameBoard> actionRight(&board, &GameBoard::right);

	EventHandlerKeyboard handlerKeyboard;
	handlerKeyboard.bind(SDLK_ESCAPE, &actionQuit);
	handlerKeyboard.bind(SDLK_LEFT, &actionLeft);
	handlerKeyboard.bind(SDLK_RIGHT, &actionRight);
	handlerKeyboard.bind(SDLK_UP, &actionRotate);
	handlerKeyboard.bind(SDLK_DOWN, &actionDrop);

	ActionMethod<View> actionViewRender(&screen, &View::render);

	EventHandlerAction<SDL_ExposeEvent> handlerRedrawEvent(SDL_VIDEOEXPOSE);
	handlerRedrawEvent.bind(TheGame::getTickEvent(), &actionViewRender);

	EventHandlerAction<SDL_QuitEvent> handlerQuitEvent(SDL_QUIT);
	handlerQuitEvent.bind(TheGame::getQuitEvent(), &actionQuit);

	game.addEventHandler(&handlerKeyboard);
	game.addEventHandler(&handlerRedrawEvent);
	game.addEventHandler(&handlerQuitEvent);
	game.start();

	return 0;
}

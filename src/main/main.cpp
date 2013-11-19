#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <functional>
#include <iostream>

#include <libgame/util/sdl_compat.h>
#include <libgame/view/ViewScreen.h>
#include <libgame/action/ActionLogging.h>
#include <libgame/core/TheGame.h>

#include "view/ViewGameBoard.h"

int main(int argc, char** argv) {
	TheGame game;
	ResourceManager<ResourceImage> resMan("res/");
	GameBoard board;
	Well well = board.getWell();
	ViewGameBoard screen(&resMan, &well);

	game.getEventDispatcher().bind(SDL_KEYDOWN, SDL_SCANCODE_ESCAPE, std::bind(&TheGame::stop, &game, std::placeholders::_1));

	game.onTick().connect<ViewGameBoard, &ViewGameBoard::render>(&screen);

//	EventHandlerKeyboard handlerKeyboard;
//	handlerKeyboard.bind(SDL_SCANCODE_ESCAPE, &actionQuit);
//	handlerKeyboard.bind(SDL_SCANCODE_LEFT, &actionLeft);
//	handlerKeyboard.bind(SDL_SCANCODE_RIGHT, &actionRight);
//	handlerKeyboard.bind(SDL_SCANCODE_UP, &actionRotate);
//	handlerKeyboard.bind(SDL_SCANCODE_DOWN, &actionDrop);
//
//	ActionMethod<ViewGameBoard> actionViewRender(&screen, &ViewGameBoard::render);
//
//	EventHandlerWindow handlerRedrawEvent;
//	handlerRedrawEvent.bind(SDL_WINDOWEVENT_EXPOSED, &actionViewRender);
//
//	EventHandlerAction<SDL_QuitEvent> handlerQuitEvent(SDL_QUIT);
//	handlerQuitEvent.bind(TheGame::getQuitEvent(), &actionQuit);

	game.start();

	return 0;
}

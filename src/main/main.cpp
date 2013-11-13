#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>

#include <libgame/util/sdl_compat.h>
#include <libgame/view/ViewScreen.h>
#include <libgame/event/EventHandlerKeyboard.h>
#include <libgame/event/EventHandlerWindow.h>
#include <libgame/action/ActionLogging.h>
#include <libgame/core/TheGame.h>

#include "view/ViewGameBoard.h"

#include <iostream>

int main (int argc, char** argv) {
	TheGame game;
	ResourceManager<ResourceImage> resMan("res/");
	GameBoard board;
	Well well = board.getWell();
	ViewGameBoard screen(&resMan, &well);

	ActionMethod<TheGame> actionQuit(&game, &TheGame::stop);
	ActionMethod<Well> actionRotate(&well, &Well::rotate);
	ActionMethod<Well> actionDrop(&well, &Well::drop);
	ActionMethod<Well> actionLeft(&well, &Well::left);
	ActionMethod<Well> actionRight(&well, &Well::right);

	EventHandlerKeyboard handlerKeyboard;
	handlerKeyboard.bind(SDL_SCANCODE_ESCAPE, &actionQuit);
	handlerKeyboard.bind(SDL_SCANCODE_LEFT, &actionLeft);
	handlerKeyboard.bind(SDL_SCANCODE_RIGHT, &actionRight);
	handlerKeyboard.bind(SDL_SCANCODE_UP, &actionRotate);
	handlerKeyboard.bind(SDL_SCANCODE_DOWN, &actionDrop);

	ActionMethod<ViewGameBoard> actionViewRender(&screen, &ViewGameBoard::render);

	EventHandlerWindow handlerRedrawEvent;
	handlerRedrawEvent.bind(SDL_WINDOWEVENT_EXPOSED, &actionViewRender);

	EventHandlerAction<SDL_QuitEvent> handlerQuitEvent(SDL_QUIT);
	handlerQuitEvent.bind(TheGame::getQuitEvent(), &actionQuit);

	game.addEventHandler(&handlerKeyboard);
	game.addEventHandler(&handlerRedrawEvent);
	game.addEventHandler(&handlerQuitEvent);
	game.start();

	return 0;
}

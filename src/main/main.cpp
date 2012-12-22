#include <SDL/SDL.h>

#include <libgame/util/sdl_compat.h>
#include <libgame/view/ViewScreen.h>
#include <libgame/event/EventHandlerKeyboard.h>
#include <libgame/action/ActionLogging.h>
#include <libgame/TheGame.h>

int main (int argc, char** argv) {
	TheGame game;
	ViewScreen screen;

	ActionMethod<TheGame> actionQuit(&game, &TheGame::stop);

	ActionLogging actionLoggingEsc("Escape");
	ActionLogging actionLoggingLeft("Left");
	ActionLogging actionLoggingRight("Right");
	ActionLogging actionLoggingUp("Up");
	ActionLogging actionLoggingDown("Down");

	EventHandlerKeyboard handlerKeyboard;
	handlerKeyboard.bind(SDLK_ESCAPE, &actionLoggingEsc);
	handlerKeyboard.bind(SDLK_LEFT, &actionLoggingLeft);
	handlerKeyboard.bind(SDLK_RIGHT, &actionLoggingRight);
	handlerKeyboard.bind(SDLK_UP, &actionLoggingUp);
	handlerKeyboard.bind(SDLK_DOWN, &actionLoggingDown);

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

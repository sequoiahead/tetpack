#include <SDL/SDL.h>

#include "libgame/TheGame.h"
#include "libgame/event/EventHandlerKeyboard.h"
#include "libgame/action/ActionGame.h"
#include "libgame/action/ActionLogging.h"

int main (int argc, char** argv) {
	TheGame game;

	ActionGameQuit actionQuit(&game);

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

	game.addEventHandler(&handlerKeyboard);
	game.start();

	return 0;
}

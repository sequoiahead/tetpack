#include "TheGame.h"
#include "view/TetPackView.h"
#include "world/TetPackWorld.h"
#include "input/InputConfiguration.h"
#include "input/InputController.h"
#include <SDL/SDL.h>

int main (int argc, char** argv) {
	TheGame game;

	InputConfiguration config;
	CommandMoveRight mvrCmd;
	CommandMoveLeft mvlCmd;
	CommandRotate rotCmd;
	CommandDrop dropCmd;
	CommandExit exitCmd;
	config.set(SDLK_LEFT, mvlCmd);
	config.set(SDLK_RIGHT, mvrCmd);
	config.set(SDLK_UP, rotCmd);
	config.set(SDLK_DOWN, dropCmd);
	config.set(SDLK_ESCAPE, exitCmd);

	InputController* c = new InputController(config);
	View* v = new TetPackView;
	World* w = new TetPackWorld;

	game.setWorld(w);
	game.setView(v);
	game.setController(c);

	game.start();

	return 0;
}

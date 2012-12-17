#include "libgame/action/ActionGame.h"

ActionGame::ActionGame(TheGame* aGame)
		: game(aGame) {
}

ActionGame::~ActionGame() {
}

ActionGameQuit::ActionGameQuit(TheGame* game)
		: ActionGame(game) {
}

ActionGameQuit::~ActionGameQuit() {
}

void ActionGameQuit::invoke() {
	game->stop();
}

#ifndef ACTIONGAME_H_
#define ACTIONGAME_H_

#include "libgame/action/Action.h"
#include "libgame/TheGame.h"

class ActionGame : public Action {
public:
	explicit ActionGame(TheGame*);
	virtual ~ActionGame();

protected:
	TheGame* game;
};

class ActionGameQuit : public ActionGame {
public:
	ActionGameQuit(TheGame*);
	virtual ~ActionGameQuit();

	virtual void invoke();
};

#endif /* ACTIONGAME_H_ */

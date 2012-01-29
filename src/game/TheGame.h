#ifndef THEGAME_H_
#define THEGAME_H_

#include "view/View.h"
#include "world/World.h"
#include "input/InputController.h"
#include <SDL/SDL.h>

class TheGame {
public:
	TheGame();
	~TheGame();

	inline void setWorld(World* w) {
		world = w;
	}

	inline void setView(View* v) {
		view = v;
	}

	inline void setController(InputController* c) {
		controller = c;
	}

	void start();

private:
	World* world;
	View* view;
	InputController* controller;
	bool isRunning;

private:
	TheGame(const TheGame&);
    void operator=(const TheGame&);
};

#endif /* THEGAME_H_ */

#ifndef THEGAME_H_
#define THEGAME_H_

#include <map>
#include <vector>
#include <SDL2/SDL.h>

#include "libgame/event/EventDispatcherInput.h"

class TheGame {
public:
	TheGame(const TheGame&) = delete;
	const TheGame& operator=(const TheGame&) = delete;

	TheGame();
	~TheGame();

	EventDispatcherInput& getEventDispatcher();

	void start();
	void stop(SDL_Event&);

private:
	bool isRunning;

	EventDispatcherInput evtDispatcherInput;
};

#endif /* THEGAME_H_ */

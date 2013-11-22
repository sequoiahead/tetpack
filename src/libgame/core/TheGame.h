#ifndef THEGAME_H_
#define THEGAME_H_

#include <cstdint>
#include <map>
#include <vector>
#include <SDL2/SDL.h>

#include "libgame/event/EventDispatcherInput.h"
#include "libgame/event/Signal.h"

class TheGame {
public:
	TheGame(const TheGame&) = delete;
	const TheGame& operator=(const TheGame&) = delete;

	TheGame();
	~TheGame();

	EventDispatcherInput& getEventDispatcher();
	Signal<void()>& onTick();

	void start();
	void stop(SDL_Event&);

private:
	bool isRunning;

	Signal<void()> signalTick;
	EventDispatcherInput evtDispatcherInput;
};

#endif /* THEGAME_H_ */

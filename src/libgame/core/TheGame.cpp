#include <SDL2/SDL_timer.h>
#include <iostream>
#include <bitset>

#include "libgame/core/TheGame.h"

TheGame::TheGame()
		: isRunning(false) {
	SDL_Init(SDL_INIT_EVERYTHING);
}

TheGame::~TheGame() {
	SDL_Quit();
}

void TheGame::start() {
	SDL_Event event;
	Uint32 delay = (1000/60);
	SDL_TimerID timerTick = SDL_AddTimer(delay,
			[](Uint32 interval, void* param) -> Uint32 {
				static_cast<TheGame*>(param)->signalTick.emit();
				return interval;
			},
	this);
	isRunning = true;
	while (isRunning) {
		if (!SDL_PollEvent(&event)) {
			continue;
		}
		evtDispatcherInput.dispatch(event);
	}
	SDL_RemoveTimer(timerTick);
}

Signal<void()>& TheGame::onTick() {
	return signalTick;
}

void TheGame::stop(SDL_Event& evt) {
	isRunning = false;
}

EventDispatcherInput& TheGame::getEventDispatcher() {
	return evtDispatcherInput;
}

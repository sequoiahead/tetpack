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
	isRunning = true;
	uint32_t lastTick = SDL_GetTicks();
	uint32_t ticks;
	while (isRunning) {
		ticks = SDL_GetTicks();
		if (SDL_PollEvent(&event)) {
			evtDispatcherInput.dispatch(event);
		}
		if (lastTick - ticks > delay) {
			signalTick.emit();
		}
		lastTick = ticks;
	}
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

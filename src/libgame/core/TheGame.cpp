#include <SDL2/SDL_timer.h>
#include <iostream>

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
	RegistryHandlersIt hndl;
	Uint32 delay = (1000/60);
	SDL_TimerID timerTick = SDL_AddTimer(delay, TheGame::sendTick, NULL);
	isRunning = true;
	while (isRunning) {
		if (!SDL_PollEvent(&event)) {
			continue;
		}
		if (event.type == SDL_WINDOWEVENT) {
			std::cout << event.window.event << std::endl;
		}
		hndl = handlers.find(static_cast<SDL_EventType>(event.type));
		if (hndl != handlers.end()) {
			hndl->second->handle(event);
		}
	}
	SDL_RemoveTimer(timerTick);
}

void TheGame::stop() {
	isRunning = false;
}

void TheGame::addEventHandler(EventHandler* handler) {
	handlers[handler->getType()] = handler;
}

void TheGame::removeEventHandler(EventHandler* handler) {
	handlers.erase(handler->getType());
}

Uint32 TheGame::sendTick(Uint32 interval, void *param) {
	SDL_Event evt;
	SDL_WindowEvent wEvt;
	evt.type = SDL_WINDOWEVENT;
	wEvt.type = SDL_WINDOWEVENT;
	wEvt.event = SDL_WINDOWEVENT_EXPOSED;
	evt.window = wEvt;
	SDL_PushEvent(&evt);
	return interval;
}

SDL_QuitEvent TheGame::getQuitEvent() {
	SDL_QuitEvent quitEvent;
	quitEvent.type = SDL_QUIT;
	return quitEvent;
}

#include <SDL/SDL_timer.h>

#include "libgame/TheGame.h"

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
	evt.type = SDL_USEREVENT;
	evt.user = TheGame::getTickEvent();
	SDL_PushEvent(&evt);
	return interval;
}

SDL_UserEvent TheGame::getTickEvent() {
	SDL_UserEvent userevent;

	userevent.type = SDL_USEREVENT;
	userevent.code = SDL_EVENT_TICK;
	userevent.data1 = NULL;
	userevent.data2 = NULL;

	return userevent;
}

SDL_QuitEvent TheGame::getQuitEvent() {
	SDL_QuitEvent quitEvent;
	quitEvent.type = SDL_QUIT;
	return quitEvent;
}

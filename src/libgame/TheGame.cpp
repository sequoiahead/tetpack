#include <iostream>
#include <SDL/SDL_video.h>

#include "TheGame.h"

TheGame::TheGame()
		: isRunning(false) {
	SDL_Init(SDL_INIT_EVERYTHING);

	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	const int SCREEN_BPP = 32;
//	const int OFFSET_IN_PIXELS = 6;
//	const int KEY_REPEAT_DELAY = SDL_DEFAULT_REPEAT_DELAY;
//	const int KEY_REPEAT_INTERVAL = SDL_DEFAULT_REPEAT_INTERVAL;

	SDL_Surface* screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE | SDL_DOUBLEBUF);
	SDL_Flip(screen);
}

TheGame::~TheGame() {
	SDL_Quit();
}

void TheGame::addEventHandler(EventHandler* handler) {
	handlers[handler->getType()] = handler;
}

void TheGame::removeEventHandler(EventHandler* handler) {
	handlers.erase(handler->getType());
}

void TheGame::start() {
	SDL_Event event;
	SDL_EventType type;
	isRunning = true;
	while (isRunning) {
		if(!SDL_PollEvent(&event)) {
			continue;
		}
		type = static_cast<SDL_EventType>(event.type);
		if (handlers.count(type) > 0) {
			handlers[type]->handle(event);
		}
	}
}

void TheGame::stop() {
	isRunning = false;
}

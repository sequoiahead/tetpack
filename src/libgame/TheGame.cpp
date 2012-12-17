#include <iostream>
#include <algorithm>

#include <SDL/SDL_video.h>

#include "TheGame.h"

TheGame::TheGame()
		: isRunning(false) {
	SDL_Init(SDL_INIT_EVERYTHING);
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
		if (!SDL_PollEvent(&event)) {
			continue;
		}
		type = static_cast<SDL_EventType>(event.type);
		if (handlers.count(type) > 0) {
			handlers[type]->handle(event);
		}
	}
}

void TheGame::addView(View* aView) {
	views.push_back(aView);
}

void TheGame::removeView(View* aView) {
	views.erase(std::remove(views.begin(), views.end(), aView));
}

void TheGame::stop() {
	isRunning = false;
}

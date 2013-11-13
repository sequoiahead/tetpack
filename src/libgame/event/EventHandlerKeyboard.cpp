#include <iostream>

#include "libgame/event/EventHandlerKeyboard.h"

EventHandlerKeyboard::EventHandlerKeyboard()
		: EventHandlerAction<SDL_KeyboardEvent>(SDL_KEYDOWN) {
}

EventHandlerKeyboard::~EventHandlerKeyboard() {
}

void EventHandlerKeyboard::bind(const SDL_Scancode& aScancode, Action* aAction) {
	SDL_KeyboardEvent evt;
	SDL_Keysym ksm;
	ksm.scancode = aScancode;
	evt.keysym = ksm;
	this->bind(evt, aAction);
}

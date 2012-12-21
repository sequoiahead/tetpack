#include <iostream>
#include <SDL/SDL_keysym.h>

#include "libgame/event/EventHandlerKeyboard.h"
#include "libgame/action/Action.h"

EventHandlerKeyboard::EventHandlerKeyboard()
		: EventHandlerAction<SDL_KeyboardEvent>(SDL_KEYDOWN) {
}

EventHandlerKeyboard::~EventHandlerKeyboard() {
}

void EventHandlerKeyboard::bind(const SDLKey& aKeysym, Action* aAction) {
	SDL_KeyboardEvent evt;
	SDL_keysym ksm;
	ksm.sym = aKeysym;
	evt.keysym = ksm;
	this->bind(evt, aAction);
}

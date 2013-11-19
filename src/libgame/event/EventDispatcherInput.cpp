#include "libgame/event/EventDispatcherInput.h"
#include "libgame/event/EventHash.h"

EventDispatcherInput::EventDispatcherInput()
		: eventHandlers() {
}

EventDispatcherInput::~EventDispatcherInput() {
}

void EventDispatcherInput::bind(SDL_EventType atype, SDL_Scancode ascn, std::function<void(SDL_Event&)> ahndl) {
	bind(atype,ascn,KMOD_NONE,ahndl);
}

void EventDispatcherInput::bind(SDL_EventType atype, SDL_Scancode ascn, SDL_Keymod akmd, std::function<void(SDL_Event&)> ahndl) {
	eventHandlers[EventHash::get(atype,ascn,akmd)] = ahndl;
}

void EventDispatcherInput::dispatch(SDL_Event& aevt) const {
	HandlersRegistryItConst it = eventHandlers.find(EventHash::get(aevt));
	if (it != eventHandlers.end()) {
		it->second(aevt);
	}
}

#ifndef EVENTHANDLER_H_
#define EVENTHANDLER_H_

#include <SDL/SDL_events.h>

#include "libgame/action/Action.h"

class EventHandler {
public:
	explicit EventHandler(SDL_EventType);
	virtual ~EventHandler();

	bool isSupported(const SDL_EventType&) const;
	const SDL_EventType& getType() const;

	virtual void handle(const SDL_Event&) = 0;

private:
	SDL_EventType type;
};

inline EventHandler::EventHandler(SDL_EventType aType)
	: type(aType) {
}

inline EventHandler::~EventHandler() {
}

inline const SDL_EventType& EventHandler::getType() const {
	return type;
}

inline bool EventHandler::isSupported(const SDL_EventType& aType) const {
	return type == aType;
}

#endif /* EVENTHANDLER_H_ */

#ifndef EVENTHANDLERKEYBOARD_H_
#define EVENTHANDLERKEYBOARD_H_

#include "libgame/event/EventHandlerAction.h"

class EventHandlerKeyboard : public EventHandlerAction<SDL_KeyboardEvent> {
public:
	using EventHandlerAction<SDL_KeyboardEvent>::bind; //required to use overloaded bind()

	explicit EventHandlerKeyboard();
	virtual ~EventHandlerKeyboard();

	void bind(const SDLKey&, Action*);
};

//operator< implementation is mandatory, it's used for ordering
//element inside actions map
bool operator<(const SDL_KeyboardEvent&, const SDL_KeyboardEvent&);

#endif /* EVENTHANDLERKEYBOARD_H_ */

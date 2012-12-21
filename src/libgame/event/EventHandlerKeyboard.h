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

#endif /* EVENTHANDLERKEYBOARD_H_ */

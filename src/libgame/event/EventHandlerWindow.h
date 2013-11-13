/*
 * EventHandlerWindow.h
 *
 *  Created on: Nov 8, 2013
 *      Author: sequoiahead
 */

#ifndef EVENTHANDLERWINDOW_H_
#define EVENTHANDLERWINDOW_H_

#include <libgame/event/EventHandlerAction.h>

class EventHandlerWindow: public EventHandlerAction<SDL_WindowEvent> {
public:
	using EventHandlerAction<SDL_WindowEvent>::bind; //required to use overloaded bind()

	EventHandlerWindow();
	virtual ~EventHandlerWindow();

	void bind(const SDL_WindowEventID&, Action*);
};

#endif /* EVENTHANDLERWINDOW_H_ */

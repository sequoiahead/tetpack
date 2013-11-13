/*
 * EventHandlerWindow.cpp
 *
 *  Created on: Nov 8, 2013
 *      Author: sequoiahead
 */

#include "libgame/event/EventHandlerWindow.h"

EventHandlerWindow::EventHandlerWindow()
		: EventHandlerAction<SDL_WindowEvent>(SDL_WINDOWEVENT) {

}

EventHandlerWindow::~EventHandlerWindow() {
}

void EventHandlerWindow::bind(const SDL_WindowEventID& aId, Action* aAction) {
	SDL_WindowEvent evt;
	evt.event = aId;
	this->bind(evt, aAction);
}



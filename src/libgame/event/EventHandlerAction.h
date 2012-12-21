#ifndef EVENTHANDLERABSTRACT_H_
#define EVENTHANDLERABSTRACT_H_

#include <map>

#include "libgame/util/sdl_compat.h"
#include "libgame/event/EventHandler.h"
#include "libgame/event/Exceptions.h"

template<typename Event>
class EventHandlerAction : public EventHandler {
public:
	explicit EventHandlerAction(SDL_EventType);
	virtual ~EventHandlerAction();

	virtual void bind(const Event&, Action* const);
	virtual void unbind(const Event&);
	virtual Action* const resolve(const Event&);

	virtual void handle(const SDL_Event&);

private:
	typedef std::map<Event, Action*> ActionsMap;
	typedef typename ActionsMap::iterator ActionMapIt;

	ActionsMap mapActions;
};

template<typename Event>
EventHandlerAction<Event>::EventHandlerAction(SDL_EventType aType)
		: EventHandler(aType) {
}

template<typename Event>
EventHandlerAction<Event>::~EventHandlerAction() {
}

template<typename Event>
void EventHandlerAction<Event>::bind(const Event& aEvent, Action* const aAction) {
	mapActions[aEvent] = aAction;
}

template<typename Event>
void EventHandlerAction<Event>::unbind(const Event& aEvent) {
	mapActions.erase(aEvent);
}

template<typename Event>
Action* const EventHandlerAction<Event>::resolve(const Event& aEvent) {
	ActionMapIt it = mapActions.find(aEvent);
	if (it == mapActions.end()) {
		NoActionException e;
		throw e;
	}
	return it->second;
}

template<typename Event>
void EventHandlerAction<Event>::handle(const SDL_Event& aEvent) {
	try {
		resolve(getExactEvent<Event>(aEvent))->invoke();
	} catch (NoActionException& e) {
		//do nothing for now
	}
}

#endif /* EVENTHANDLERABSTRACT_H_ */

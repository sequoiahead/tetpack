#ifndef EVENTHANDLERABSTRACT_H_
#define EVENTHANDLERABSTRACT_H_

#include <map>

#include "libgame/event/EventHandler.h"
#include "libgame/event/Exceptions.h"

template<typename Event>
class EventHandlerAction : public EventHandler {
public:
	explicit EventHandlerAction(SDL_EventType);
	virtual ~EventHandlerAction();

	virtual void bind(const Event&, Action*);
	virtual void unbind(const Event&);
	virtual Action* resolve(const Event&);

	virtual void handle(const SDL_Event&);

private:
	std::map<Event, Action*> actionsMap;
};

template<typename Event>
EventHandlerAction<Event>::EventHandlerAction(SDL_EventType aType)
		: EventHandler(aType) {
}

template<typename Event>
EventHandlerAction<Event>::~EventHandlerAction() {
}

template<typename Event>
void EventHandlerAction<Event>::bind(const Event& aEvent, Action* aAction) {
	actionsMap[aEvent] = aAction;
}

template<typename Event>
void EventHandlerAction<Event>::unbind(const Event& aEvent) {
	actionsMap.erase(aEvent);
}

template<typename Event>
Action* EventHandlerAction<Event>::resolve(const Event& aEvent) {
	if (actionsMap.count(aEvent) <= 0) {
		NoActionException e;
		throw e;
	}
	return actionsMap[aEvent];
}

template<typename Event>
void EventHandlerAction<Event>::handle(const SDL_Event& aEvent) {
	resolve(aEvent.key)->invoke();
}

#endif /* EVENTHANDLERABSTRACT_H_ */

#ifndef EVENTDISPATCHERINPUT_H_
#define EVENTDISPATCHERINPUT_H_

#include <unordered_map>
#include <functional>
#include <SDL2/SDL_events.h>

class EventDispatcherInput {
public:
	EventDispatcherInput();
	virtual ~EventDispatcherInput();

	void bind(SDL_EventType, std::function<void(SDL_Event&)>&);
	void bind(SDL_EventType, SDL_Scancode, std::function<void(SDL_Event&)>&);
	void bind(SDL_EventType, SDL_Scancode, SDL_Keymod, std::function<void(SDL_Event&)>&);

	void dispatch(SDL_Event&) const;

private:
	typedef std::unordered_map<uint32_t, std::function<void(SDL_Event&)>> HandlersRegistry;
	typedef HandlersRegistry::const_iterator HandlersRegistryItConst;

	HandlersRegistry eventHandlers;
};


#endif /* EVENTDISPATCHERINPUT_H_ */

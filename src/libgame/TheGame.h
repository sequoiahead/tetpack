#ifndef THEGAME_H_
#define THEGAME_H_

#include <map>
#include <vector>
#include <SDL/SDL.h>

#include "libgame/event/EventHandler.h"

const unsigned int SDL_EVENT_TICK = 1;

class TheGame {
public:
	TheGame();
	~TheGame();

	void addEventHandler(EventHandler*);
	void removeEventHandler(EventHandler*);
	void start();
	void stop();

	static SDL_ExposeEvent getTickEvent();
	static SDL_QuitEvent getQuitEvent();

private:
	typedef std::pair<SDL_EventType, EventHandler*> RecordHandlers;
	typedef std::map<SDL_EventType, EventHandler*> RegistryHandlers;
	typedef RegistryHandlers::iterator RegistryHandlersIt;

	RegistryHandlers handlers;
	bool isRunning;

	static Uint32 sendTick(Uint32 interval, void *param);

	//noncopyable
	TheGame(const TheGame&);
	const TheGame& operator=(const TheGame&);
};

#endif /* THEGAME_H_ */

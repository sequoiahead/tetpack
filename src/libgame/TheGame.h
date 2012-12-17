#ifndef THEGAME_H_
#define THEGAME_H_

#include <map>
#include <vector>
#include <boost/noncopyable.hpp>
#include <SDL/SDL.h>

#include "libgame/view/View.h"
#include "libgame/event/EventHandler.h"

class TheGame : public boost::noncopyable {
public:
	TheGame();
	~TheGame();

	void addEventHandler(EventHandler*);
	void removeEventHandler(EventHandler*);
	void addView(View*);
	void removeView(View*);
	void start();
	void stop();

private:
	typedef std::pair<SDL_EventType, EventHandler*> RecordHandlers;
	typedef std::map<SDL_EventType, EventHandler*> RegistryHandlers;

	RegistryHandlers handlers;
	std::vector<View*> views;
	bool isRunning;
};

#endif /* THEGAME_H_ */

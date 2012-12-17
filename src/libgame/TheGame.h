#ifndef THEGAME_H_
#define THEGAME_H_

#include <map>
#include <boost/noncopyable.hpp>
#include <SDL/SDL.h>

#include "view/View.h"
#include "event/EventHandler.h"

class TheGame : public boost::noncopyable {
public:
	TheGame();
	~TheGame();

	void addEventHandler(EventHandler*);
	void removeEventHandler(EventHandler*);
	void start();
	void stop();

private:
	typedef std::pair<SDL_EventType, EventHandler*> Record;
	typedef std::map<SDL_EventType, EventHandler*> Registry;

	Registry handlers;
	bool isRunning;
};

#endif /* THEGAME_H_ */

#ifndef SIGNAL_H_
#define SIGNAL_H_

#include <list>
#include <algorithm>

#include "libgame/action/Action.h"

class Signal {
public:
	void attach(Action* const) const;
	bool detach(Action* const) const;

	void emit();

protected:
	typedef std::list<Action*> Slots;
	typedef std::list<Action*>::iterator SlotsIt;

	mutable Slots slots;
};

#endif /* SIGNAL_H_ */

#include "libgame/event/Signal.h"

void Signal::attach(Action* const action) const {
	slots.push_back(action);
}

bool Signal::detach(Action* const action) const {
	SlotsIt it = std::find(slots.begin(), slots.end(), action);
	bool somethingToDetach = (it != slots.end());
	if (somethingToDetach) {
		slots.erase(it);
	}
	return somethingToDetach;
}

void Signal::emit() {
	for(SlotsIt it = slots.begin(); it != slots.end(); it ++) {
		(*it)->invoke();
	}
}

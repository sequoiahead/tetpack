#ifndef SIGNAL_H_
#define SIGNAL_H_

#include <list>
#include <algorithm>

#include "libgame/action/Action.h"

class Signal {
public:
	void attach(Action* const) const;
	bool detach(Action* const) const;

	template<typename T>
	void attach(T* const, void (T::*)()) const;
	template<typename T>
	void detach(T* const, void (T::*)()) const;

	void attach(void (*)()) const;
	void detach(void (*)()) const;

	void emit();

protected:
	typedef std::list<Action*> Slots;
	typedef std::list<Action*>::iterator SlotsIt;

	mutable Slots slots;
};

template<typename T>
inline void Signal::attach(T* const aInstance, void (T::*aSlot)()) const {
	ActionMethod<T>* action = new ActionMethod<T>(aInstance, aSlot);
	attach(action);
}

template<typename T>
inline void Signal::detach(T* const aInstance, void (T::*aSlot)()) const {
	ActionMethod<T> action(aInstance, aSlot);
	detach(&action);
}

#endif /* SIGNAL_H_ */

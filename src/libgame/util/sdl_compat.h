#ifndef SDL_COMPAT_H_
#define SDL_COMPAT_H_

#include <SDL/SDL_events.h>

//conversion functions
template<typename Event>
Event getExactEvent(const SDL_Event& aEvt);

template<>
inline SDL_KeyboardEvent getExactEvent(const SDL_Event& aEvt) {
	return aEvt.key;
}

template<>
inline SDL_UserEvent getExactEvent(const SDL_Event& aEvt) {
	return aEvt.user;
}

template<>
inline SDL_QuitEvent getExactEvent(const SDL_Event& aEvt) {
	return aEvt.quit;
}

//stl containers compatibility
//operator< implementation is mandatory, it's used for ordering
//element inside actions map
inline bool operator<(const SDL_KeyboardEvent& aEvt1, const SDL_KeyboardEvent& aEvt2) {
	return aEvt1.keysym.sym < aEvt2.keysym.sym;
}

inline bool operator<(const SDL_UserEvent& aEvt1, const SDL_UserEvent& aEvt2) {
	return aEvt1.code < aEvt2.code;
}

inline bool operator<(const SDL_QuitEvent& aEvt1, const SDL_QuitEvent& aEvt2) {
	return aEvt1.type < aEvt2.type;
}

#endif /* SDL_COMPAT_H_ */

#ifndef EVENTHASH_H_
#define EVENTHASH_H_

#include <unordered_map>
#include <SDL2/SDL_events.h>

namespace std {
template<>
struct hash<SDL_EventType> {
	size_t operator()(const SDL_EventType& k) const {
		return static_cast<size_t>(k);
	}
};
}

class EventHash {
public:
	EventHash() = delete;
	~EventHash() = delete;

	static uint32_t get(SDL_EventType, SDL_Scancode, SDL_Keymod);
	static uint32_t get(SDL_KeyboardEvent&);
	static uint32_t get(SDL_Event&);
private:
	static const std::unordered_map<SDL_EventType,uint8_t> eventTypeIndex;
};

#endif /* EVENTHASH_H_ */

#include "libgame/event/EventHash.h"

const std::unordered_map<SDL_EventType,uint8_t> EventHash::eventTypeIndex{
	{SDL_QUIT,1},{SDL_APP_TERMINATING,2},{SDL_APP_LOWMEMORY,3},{SDL_APP_WILLENTERBACKGROUND,4},{SDL_APP_DIDENTERBACKGROUND,5},
	{SDL_APP_WILLENTERFOREGROUND,6},{SDL_APP_DIDENTERFOREGROUND,7},{SDL_WINDOWEVENT,8},{SDL_SYSWMEVENT,9},{SDL_KEYDOWN,10},
	{SDL_KEYUP,11},{SDL_TEXTEDITING,12},{SDL_TEXTINPUT,13},{SDL_MOUSEMOTION,14},{SDL_MOUSEBUTTONDOWN,15},{SDL_MOUSEBUTTONUP,16},
	{SDL_MOUSEWHEEL,17},{SDL_JOYAXISMOTION,18},{SDL_JOYBALLMOTION,19},{SDL_JOYHATMOTION,20},{SDL_JOYBUTTONDOWN,21},{SDL_JOYBUTTONUP,22},
	{SDL_JOYDEVICEADDED,23},{SDL_JOYDEVICEREMOVED,24},{SDL_CONTROLLERAXISMOTION,25},{SDL_CONTROLLERBUTTONDOWN,26},{SDL_CONTROLLERBUTTONUP,27},
	{SDL_CONTROLLERDEVICEADDED,28},{SDL_CONTROLLERDEVICEREMOVED,29},{SDL_CONTROLLERDEVICEREMAPPED,30},{SDL_FINGERDOWN,31},{SDL_FINGERUP,32},
	{SDL_FINGERMOTION,33},{SDL_DOLLARGESTURE,34},{SDL_DOLLARRECORD,35},{SDL_MULTIGESTURE,36},{SDL_CLIPBOARDUPDATE,37},{SDL_DROPFILE,38}
};

uint32_t EventHash::get(SDL_KeyboardEvent& evt) {
	return (static_cast<uint8_t>(evt.keysym.scancode) << 16) | (static_cast<uint16_t>(evt.keysym.mod));
}

uint32_t EventHash::get(SDL_EventType atype, SDL_Scancode ascn, SDL_Keymod amod) {
	return (eventTypeIndex.at(static_cast<SDL_EventType>(atype)) << 24) | (static_cast<uint8_t>(ascn) << 16) | (static_cast<uint16_t>(amod));
}

uint32_t EventHash::get(SDL_Event& evt) {
	uint32_t evtHash = 0;
	switch (evt.type) {
	case SDL_KEYUP:
	case SDL_KEYDOWN:
		evtHash = get(evt.key);
	}
	return (eventTypeIndex.at(static_cast<SDL_EventType>(evt.type)) << 24) | evtHash;
}

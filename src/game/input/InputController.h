#ifndef INPUTCONTROLLER_H_
#define INPUTCONTROLLER_H_

#include "world/Command.h"
#include "InputConfiguration.h"
#include <SDL/SDL.h>

class InputController {
public:
	explicit InputController(const InputConfiguration&);
	~InputController();

	const Command& resolve(const SDL_Event&) const;
private:
	InputConfiguration configuration;
};

#endif /* INPUTCONTROLLER_H_ */

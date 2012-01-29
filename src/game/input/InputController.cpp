#include "InputController.h"

InputController::InputController(const InputConfiguration& config)
		: configuration(config) {
}

InputController::~InputController() {
}

const Command& InputController::resolve(const SDL_Event& event) const {
	if (SDL_KEYDOWN != event.type) {
		return configuration.cmdNone;
	}
	return configuration.get(event.key.keysym.sym);
}

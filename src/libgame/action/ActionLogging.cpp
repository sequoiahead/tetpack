#include <iostream>

#include "libgame/action/ActionLogging.h"

ActionLogging::ActionLogging(const char* aMsg)
		: message(aMsg) {
}

ActionLogging::~ActionLogging() {
}

void ActionLogging::invoke() {
	std::cout << message << std::endl;
}

#include <iostream>

#include "libgame/action/ActionLogging.h"

ActionLogging::ActionLogging(const char* aMsg)
		: msg(aMsg) {
}

ActionLogging::~ActionLogging() {
}

void ActionLogging::invoke() {
	std::cout << msg << std::endl;
}

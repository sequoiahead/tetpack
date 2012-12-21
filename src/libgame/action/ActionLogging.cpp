#include <iostream>

#include "libgame/action/ActionLogging.h"

ActionLogging::ActionLogging(const char* aMsg)
		: ActionAbstract(aMsg) {
}

ActionLogging::~ActionLogging() {
}

void ActionLogging::invoke() {
	std::cout << target << std::endl;
}

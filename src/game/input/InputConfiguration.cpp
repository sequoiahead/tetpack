#include "InputConfiguration.h"

InputConfiguration::InputConfiguration() {
}

void InputConfiguration::set(const InputAction act, const Command& cmd) {
	std::pair<Registry::iterator, bool> status = map.insert(Record(act, cmd));
	if (!status.second) {
		status.first->second = cmd;
	}
}

const Command& InputConfiguration::get(const InputAction& act) const {
	Registry::const_iterator it = map.find(act);
	return (it == map.end() ? cmdNone : it->second);
}

InputConfiguration::~InputConfiguration() {
}

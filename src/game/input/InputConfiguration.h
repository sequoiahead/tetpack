#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include <map>
#include "world/Command.h"

typedef int InputAction;

class InputConfiguration {
public:
	InputConfiguration();
	~InputConfiguration();

	void set(const InputAction, const Command&);
	const Command& get(const InputAction&) const;

	CommandNone cmdNone;
private:
	typedef std::pair<InputAction, Command> Record;
	typedef std::map<InputAction, Command> Registry;

	Registry map;
};

#endif /* CONFIGURATION_H_ */

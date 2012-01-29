#ifndef THEWORLD_H_
#define THEWORLD_H_

#include "Command.h"

class World {
public:
	virtual void act(const Command&) = 0;
	virtual void recalculate() = 0;
};

#endif /* THEWORLD_H_ */

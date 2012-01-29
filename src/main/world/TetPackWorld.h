#ifndef TETPACKWORLD_H_
#define TETPACKWORLD_H_

#include "world/World.h"
#include "TetPackCommand.h"

class TetPackWorld: public World {
public:
	TetPackWorld();
	virtual ~TetPackWorld();

	virtual void act(const Command&);
	virtual void recalculate();
};

#endif /* TETPACKWORLD_H_ */

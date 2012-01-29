#include "TetPackWorld.h"
#include <iostream>

TetPackWorld::TetPackWorld() {
}

TetPackWorld::~TetPackWorld() {
}

void TetPackWorld::act(const Command& cmd) {
	std::cout << cmd.getId() << std::endl;
}

void TetPackWorld::recalculate() {
	std::cout << "Recalculating world" << std::endl;
}

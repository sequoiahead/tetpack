#include "Tetromino.h"

Tetromino::Tetromino(Tetromino::Type aType)
		: type(aType), dir(DIR_UP), x(0), y(0) {
}

Tetromino::~Tetromino() {
}

void Tetromino::rotate(Direction aDir) {
	if (aDir != _DIR_LAST) {
		dir = aDir;
	} else {
		int intDir = static_cast<int>(dir);
		dir = static_cast<Direction>(++intDir);
		if (dir == _DIR_LAST) {
			dir = static_cast<Direction>(0);
		}
	}
}

void Tetromino::move(unsigned int aX, unsigned int aY) {
	x = aX;
	y = aY;
}

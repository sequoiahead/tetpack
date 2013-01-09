#include "Tetromino.h"

Tetromino::Tetromino(Tetromino::Type aType)
		: type(aType), dir(DIR_UP) {
}

Tetromino::~Tetromino() {
}

void Tetromino::rotate() {
	int intDir = static_cast<int>(dir);
	dir = static_cast<Direction>(++intDir);
	if (dir == _DIR_LAST) {
		dir = DIR_UP;
	}
}

void Tetromino::reset() {
	dir = DIR_UP;
}

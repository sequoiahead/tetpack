#include "Tetromino.h"

constexpr std::array<std::pair<uint8_t,uint8_t>,Tetromino::MAX> Tetromino::dimensions;

Tetromino::Tetromino(Tetromino::Type aType)
		: type(aType), dir(DIR_UP), w(dimensions[aType].first), h(dimensions[aType].second) {
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

void Tetromino::move(uint8_t dx, uint8_t dy) {
	x += dx;
	y += dy;
}

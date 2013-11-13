#include "domain/Well.h"

Well::Well(TetrominoFactory* aFactory)
		: factoryNextMino(aFactory), mino(aFactory->getMino()) {
}

Well::~Well() {
}

void Well::rotate() {
	mino.rotate();
	signalRotate.emit();
}

void Well::left() {
	signalMove.emit();
}

void Well::right() {
	signalMove.emit();
}

void Well::drop() {
	signalDrop.emit();
	nextRound();
}

void Well::nextRound() {
	mino = factoryNextMino->getMino();
	signalNextRound.emit();
}

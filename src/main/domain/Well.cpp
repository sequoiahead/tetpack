#include "domain/Well.h"

Well::Well(TetrominoFactory* aFactory)
		: factoryNextMino(aFactory), mino(aFactory->getMino()) {
}

Well::~Well() {
}

void Well::rotate(SDL_Event& evt) {
	mino.rotate();
	signalRotate.emit();
}

void Well::left(SDL_Event& evt) {
	signalMove.emit();
}

void Well::right(SDL_Event& evt) {
	signalMove.emit();
}

void Well::drop(SDL_Event& evt) {
	signalDrop.emit();
	nextRound();
}

void Well::nextRound() {
	mino = factoryNextMino->getMino();
	signalNextRound.emit();
}

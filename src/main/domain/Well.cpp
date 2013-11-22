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
	mino.move(-1,0);
	signalMove.emit();
}

void Well::right(SDL_Event& evt) {
	mino.move(1,0);
	signalMove.emit();
}

void Well::drop(SDL_Event& evt) {
	mino.move(0,1);
	signalDrop.emit();
	if(mino.getY() >= h) {
		nextRound();
	}
}

void Well::nextRound() {
	mino = factoryNextMino->getMino();
	signalNextRound.emit();
}

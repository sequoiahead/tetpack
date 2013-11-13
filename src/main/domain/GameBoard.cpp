#include "domain/GameBoard.h"

GameBoard::GameBoard() {
	std::srand(std::time(0));
	for (int i = 0; i < Tetromino::_LAST; i++) {
		minos[i] = new Tetromino(static_cast<Tetromino::Type>(i));
	}
	currentMino = randomMino();
	nextMino = randomMino();
	well = new Well(this);
}

GameBoard::~GameBoard() {
	for (int i = 0; i < Tetromino::_LAST; i++) {
		delete minos[i];
	}
	delete well;
}

Tetromino::Type GameBoard::randomMino() {
	return static_cast<Tetromino::Type>(std::rand() % Tetromino::_LAST);
}

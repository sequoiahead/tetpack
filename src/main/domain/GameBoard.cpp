#include "domain/GameBoard.h"

GameBoard::GameBoard() {
	std::srand(std::time(0));
	for (int i = 0; i < Tetromino::_LAST; i++) {
		minos[i] = new Tetromino(static_cast<Tetromino::Type>(i));
	}
	currentMino = randomMino();
	nextMino = randomMino();
}

GameBoard::~GameBoard() {
	for (int i = 0; i < Tetromino::_LAST; i++) {
		delete minos[i];
	}
}

Tetromino::Type GameBoard::randomMino() {
	return static_cast<Tetromino::Type>(std::rand() % Tetromino::_LAST);
}

void GameBoard::rotate() {
	getCurrentMino().rotate();
	currentMino = randomMino();
}

void GameBoard::left() {
}

void GameBoard::right() {
}

void GameBoard::drop() {
}

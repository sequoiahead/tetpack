#include <iostream>
#include <stdexcept>
#include <string>

#include "view/ViewGameBoard.h"

ViewGameBoard::ViewGameBoard(ResourceManager<ResourceImage>* aImgMan, const GameBoard* aBoard)
		: imgMan(aImgMan), board(aBoard) {
	minosImgs[Tetromino::I] = "I.png";
	minosImgs[Tetromino::J] = "J.png";
	minosImgs[Tetromino::L] = "L.png";
	minosImgs[Tetromino::O] = "O.png";
	minosImgs[Tetromino::S] = "S.png";
	minosImgs[Tetromino::T] = "T.png";
	minosImgs[Tetromino::Z] = "Z.png";

	for (unsigned short t = 0; t < Tetromino::_LAST; t++) {
		minos[t] = imgMan->get(minosImgs[t]);
	}
}

ViewGameBoard::~ViewGameBoard() {
}

void ViewGameBoard::prepareScreen(unsigned int deltaTime) {
	SDL_BlitSurface(*minos[board->getCurrentMino().getType()], NULL, screen, NULL);
}

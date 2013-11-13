#include <iostream>

#include "view/ViewGameBoard.h"

ViewGameBoard::ViewGameBoard(ResourceManager<ResourceImage>* aImgMan, const Well* aBoard)
		: imgMan(aImgMan), well(aBoard) {
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
	Tetromino mino = well->getCurrentMino();
//	SDL_RenderCopy(sdlRenderer, sdlTexture, NULL, NULL);
//	SDL_BlitSurface(*minos[mino.getType()], NULL, screen, NULL);
}

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

void ViewGameBoard::render() {
	ViewScreen::render();
}

void ViewGameBoard::prepareScreen(uint32_t deltaTime) {
	std::cout << "prepare at " << deltaTime << std::endl;
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	Tetromino mino = well->getCurrentMino();
	SDL_Texture* txMino = SDL_CreateTextureFromSurface(renderer,*minos[mino.getType()]);
	SDL_RenderCopy(renderer, txMino, NULL, NULL);
}

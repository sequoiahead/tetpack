#include <iostream>

#include "view/ViewGameBoard.h"

ViewGameBoard::ViewGameBoard(ResourceManager<ResourceImage>* aImgMan, const Well* aBoard)
		: imgMan(aImgMan), well(aBoard) {
	minosUrls[Tetromino::I] = "I.png";
	minosUrls[Tetromino::J] = "J.png";
	minosUrls[Tetromino::L] = "L.png";
	minosUrls[Tetromino::O] = "O.png";
	minosUrls[Tetromino::S] = "S.png";
	minosUrls[Tetromino::T] = "T.png";
	minosUrls[Tetromino::Z] = "Z.png";

	for (unsigned short t = 0; t < Tetromino::_LAST; t++) {
		minos[t] = SDL_CreateTextureFromSurface(renderer,*imgMan->get(minosUrls[t]));
	}

	blockHeightPx = heightPx / well->getHeight();
	blockWidthPx = widthPx / well->getWidth();
}

ViewGameBoard::~ViewGameBoard() {
}

void ViewGameBoard::prepareScreen(uint32_t deltaTime) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	Tetromino mino = well->getCurrentMino();
	SDL_Rect dest;
	dest.x = mino.getX() * blockWidthPx;
	dest.y = mino.getY() * blockHeightPx;
	dest.h = mino.getHeight() * blockHeightPx;
	dest.w = mino.getWidth() * blockWidthPx;
	SDL_Point center;
	center.x = dest.x;
	center.y = dest.y;
	double angle = 90*(static_cast<uint8_t>(mino.getDirection()));
	SDL_RenderCopyEx(renderer, minos[mino.getType()], NULL, &dest, angle, &center, SDL_FLIP_NONE);
}

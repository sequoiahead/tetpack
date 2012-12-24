#include <iostream>
#include <stdexcept>
#include <string>

#include "view/TetPackView.h"

TetPackView::TetPackView(ResourceManager<ResourceImage>* aImgMan, GameBoard* aBoard)
		: imgMan(aImgMan), board(aBoard) {
	minosImgs[MINO_I] = "I.png";
	minosImgs[MINO_J] = "J.png";
	minosImgs[MINO_L] = "L.png";
	minosImgs[MINO_O] = "O.png";
	minosImgs[MINO_S] = "S.png";
	minosImgs[MINO_T] = "T.png";
	minosImgs[MINO_Z] = "Z.png";

	for (unsigned short t = 0; t < MINO_LAST; t++) {
		minos[t] = imgMan->get(minosImgs[t]);
	}
}

TetPackView::~TetPackView() {
}

void TetPackView::prepareScreen(unsigned int deltaTime) {
	SDL_BlitSurface(*minos[MINO_L], NULL, screen, NULL);
}

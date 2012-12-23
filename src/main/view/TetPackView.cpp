#include <iostream>
#include <stdexcept>
#include <string>

#include "view/TetPackView.h"

TetPackView::TetPackView(ResourceManager& aResMan)
		: resMan(aResMan) {
	lMino = resMan.get<ResourceImage>("L.png");
}

TetPackView::~TetPackView() {
}

void TetPackView::prepareScreen(unsigned int deltaTime) {
	SDL_BlitSurface(*lMino, NULL, screen, NULL);
}

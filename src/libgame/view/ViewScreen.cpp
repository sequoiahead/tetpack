#include "libgame/view/ViewScreen.h"

ViewScreen::ViewScreen(unsigned int aWidth, unsigned int aHeight, unsigned int aBpp)
		: width(aWidth), height(aHeight), bpp(aBpp) {

	screen = SDL_SetVideoMode(width, height, bpp, SDL_SWSURFACE | SDL_DOUBLEBUF);
	SDL_Flip(screen);
}

ViewScreen::~ViewScreen() {
	SDL_FreeSurface(screen);
}

void ViewScreen::render() {

}

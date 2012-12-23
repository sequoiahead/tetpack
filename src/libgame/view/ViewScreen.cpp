#include <SDL/SDL_timer.h>

#include "libgame/view/ViewScreen.h"

ViewScreen::ViewScreen(unsigned int aWidth, unsigned int aHeight, unsigned int aBpp)
		: width(aWidth), height(aHeight), bpp(aBpp), lastTick(SDL_GetTicks()) {

	screen = SDL_SetVideoMode(width, height, bpp, SDL_SWSURFACE | SDL_DOUBLEBUF);
}

ViewScreen::~ViewScreen() {
	SDL_FreeSurface(screen);
}

void ViewScreen::render() {
	unsigned int ticks = SDL_GetTicks();
	prepareScreen(ticks - lastTick);
	lastTick = ticks;
	SDL_Flip(screen);
}

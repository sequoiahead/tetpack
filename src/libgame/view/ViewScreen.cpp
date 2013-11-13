#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_render.h>
#include <iostream>

#include "libgame/view/ViewScreen.h"

ViewScreen::ViewScreen(unsigned int aWidth, unsigned int aHeight, unsigned int aBpp)
		: width(aWidth), height(aHeight), bpp(aBpp), lastTick(SDL_GetTicks()) {

	SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS, &window, &renderer);
}

ViewScreen::~ViewScreen() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void ViewScreen::render() {
	unsigned int ticks = SDL_GetTicks();
	SDL_RenderClear(renderer);
	prepareScreen(ticks - lastTick);
	lastTick = ticks;
	SDL_RenderPresent(renderer);
}

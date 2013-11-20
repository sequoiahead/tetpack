#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_render.h>
#include <iostream>

#include "libgame/view/ViewScreen.h"
#include "libgame/core/Exception.h"

ViewScreen::ViewScreen(unsigned int aWidth, unsigned int aHeight, unsigned int aBpp)
		: widthPx(aWidth), heightPx(aHeight), bpp(aBpp), lastTick(SDL_GetTicks()) {
	SDL_CreateWindowAndRenderer(widthPx, heightPx, SDL_WINDOW_SHOWN,
			&window, &renderer);
	if (window == NULL || renderer == NULL) {
		throw Exception("Failed to initialize window or renderer");
	}
}

ViewScreen::~ViewScreen() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void ViewScreen::render() {
	uint32_t ticks = SDL_GetTicks();
	SDL_RenderClear(renderer);
	prepareScreen(ticks - lastTick);
	lastTick = ticks;
	SDL_RenderPresent(renderer);
}

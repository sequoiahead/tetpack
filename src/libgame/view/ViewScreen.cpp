#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_render.h>
#include <iostream>

#include "libgame/view/ViewScreen.h"
#include "libgame/core/Exception.h"

ViewScreen::ViewScreen(unsigned int aWidth, unsigned int aHeight, unsigned int aBpp)
		: width(aWidth), height(aHeight), bpp(aBpp), lastTick(SDL_GetTicks()) {
	SDL_CreateWindowAndRenderer(width, height, SDL_WINDOWPOS_CENTERED | SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS,
			&window, &renderer);
	if (window == NULL or renderer == NULL) {
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
	std::cout << "before prepare" << std::endl;
	prepareScreen(ticks - lastTick);
	std::cout << "after prepare" << std::endl;
	lastTick = ticks;
	SDL_RenderPresent(renderer);
}

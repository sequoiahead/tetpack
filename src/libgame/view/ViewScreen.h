#ifndef VIEWSCREEN_H_
#define VIEWSCREEN_H_

#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>

#include "libgame/view/View.h"

const uint32_t SCREEN_WIDTH_DEFAULT = 1024;
const uint32_t SCREEN_HEIGHT_DEFAULT = 768;
const uint32_t SCREEN_BPP_DEFAULT = 32;

class ViewScreen : public View {
public:
	explicit ViewScreen(unsigned int = SCREEN_WIDTH_DEFAULT, unsigned int = SCREEN_HEIGHT_DEFAULT, unsigned int =
			SCREEN_BPP_DEFAULT);
	virtual ~ViewScreen();
	ViewScreen(const ViewScreen&) = delete;
	const ViewScreen& operator=(const ViewScreen&) = delete;

	virtual void render();

protected:
	SDL_Window* window;
	SDL_Renderer* renderer;

	uint32_t widthPx;
	uint32_t heightPx;
	uint32_t bpp;

	uint32_t lastTick;

	virtual void prepareScreen(uint32_t deltaTime) =0;
};

#endif /* VIEWSCREEN_H_ */

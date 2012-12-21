#ifndef VIEWSCREEN_H_
#define VIEWSCREEN_H_

#include <SDL/SDL_video.h>

#include "libgame/view/View.h"

const unsigned int SCREEN_WIDTH_DEFAULT = 640;
const unsigned int SCREEN_HEIGHT_DEFAULT = 480;
const unsigned int SCREEN_BPP_DEFAULT = 32;

class ViewScreen : public View {
public:
	explicit ViewScreen(unsigned int = SCREEN_WIDTH_DEFAULT, unsigned int = SCREEN_HEIGHT_DEFAULT, unsigned int =
			SCREEN_BPP_DEFAULT);
	virtual ~ViewScreen();

	virtual void render();

protected:
	SDL_Surface* screen;

	unsigned int width;
	unsigned int height;
	unsigned int bpp;

	unsigned int lastTick;

private:
	//noncopyable
	ViewScreen(const ViewScreen&);
	const ViewScreen& operator=(const ViewScreen&);
};

#endif /* VIEWSCREEN_H_ */
